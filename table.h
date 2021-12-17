#include <stdio.h>
#include <string.h>

#define TXMAX 100
#define AL 20
#define LEVMAX 3
#define AMAX 65535
#define STACKSIZE 100000

int lev=0;
int tx=0;
int dx=0;
int num;
double num_d;
int size;
int array;
struct list* array_size;
int array_dim;
char id[AL];
int error_count;
extern int line;
struct list{
    int v;
    struct list *next;
};
enum object{constant,variable,procedur};
enum type_e{int_t,char_t, double_tt, bool_t, none_t};
enum object kind;
enum type_e type;

void error(int);

void syntax_error(char* s){
    error_count++;
    printf("syntax error in line %d: %s\n", line+1, s);
    exit(1);
}
struct table1{
	char name[AL];
	enum object kind;
	enum type_e type;
	int val,adr,size,array,array_dim;
	double val_d;
	struct list* array_size;
	};
struct table1 table[TXMAX+1];

struct procReg1{
int dx0;
int tx0;
int cx0;
};
struct procReg1 procReg;

int array_len(struct list* head)
{
	struct list* each = head;
	int len=1;
	if(head==NULL){
		len=0;
	}else{
		do{
			len*=each->v;
			each = each->next;
		}while(each!=NULL);
	}
	return len;
}
int list_get_last(struct list* head)
{
	if(head==NULL){
		syntax_error("array is empty!");
		return -1;
	}
	struct list* each = head;
	while(each->next!=NULL)
		each = each->next;
	return each->v;

}
int list_del_last(struct list* head)
{
	if(head==NULL){
		return 0;
	}
	struct list* each = head;
	struct list* befor=head;
	while(each->next!=NULL){
		befor=each;
		each = each->next;
	}
	befor->next=NULL;
	free(each);
	each=NULL;
	return 0;

}
int list_get_product_after_id(struct list* head, int id)
{
	int p=1,i=0;
	struct list* each = head;
	if(head==NULL){
		return 0;
	}
	while(each!=NULL){
		if(i++>id)
			p*=each->v;
		each = each->next;
	}
	return p;
}
int list_get_by_id(struct list* head, int id)
{
	int i;
	struct list* each = head;
	for(i=0;i<id;i++)
	{
		if(each==NULL){
			syntax_error("array index out of range!");
			return -1;
		}
		each = each->next;
	}
	if(each==NULL){
		syntax_error("array index out of range!");
		return -1;
	}
	return each->v;
}
char* list_prints(struct list* head, char *s){
	struct list* each = head;
	strcpy(s,"");
	char stmp[50]="";
	if(head==NULL){
		sprintf(s,"%d",0);
	}else{
		while(each!=NULL){
			sprintf(stmp,"%d ",each->v);
			strcat(s,stmp);
			each = each->next;
		}
	}
	return s;
}
struct list* list_add(struct list* head, int v)
{
	struct list* each = head;
	if(head==NULL){
		head = (struct list*)malloc(sizeof(struct list));
		head->v=v;
		head->next=NULL;
	}else{
		while(each->next!=NULL)
			each = each->next;
		struct list* tmp = (struct list*)malloc(sizeof(struct list));
		tmp->v=v;
		tmp->next=NULL;
		each->next=tmp;
	}
	return head;
}

void enter(enum object k){
	tx=tx+1;
	strcpy(table[tx].name,id);
	table[tx].kind=k;
	switch(k)
		{
		case constant:
			if(type==double_tt){
				table[tx].val=0;
				table[tx].val_d=num_d;
			}else{
				if(num>AMAX){
					error(31);
					num=0;
				}
				table[tx].val=num;
				table[tx].val_d=0;
			}
			table[tx].type=type;
			break;
			
		case variable:		
			table[tx].adr=dx;
			table[tx].type=type;
			if(array){
				table[tx].array=array;
				table[tx].array_dim=array_dim;
				table[tx].array_size=array_size;
				dx += array_len(table[tx].array_size);
			}else{
				dx++;
			}
			break;
		case procedur:
			break;

		}
}


int position(char id[10])
{
	int i;
	//strcpy(table[0].name,id);
	i=tx;
	while(strcmp(table[i].name,id)!=0){
		i--;
		if(i==0)
			break;
	}
	return i;
}

void printTable(int tofile)
{
	int i;
	char kind[15];
	char type[15];
	int array_size0=0;
	printf("****************************************************************************************************************************************************\n");
	printf("table:\n");
	printf("%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n", "name", "kind", "val", "val_d", "type", "adr", "size", "array", "array_dim", "array_size");
	for(i=0;i<=tx;i++)
	{
		switch(table[i].kind)
		{
			case constant:
				strcpy(kind, "constant");
				break;
			case variable:
				strcpy(kind, "variable");
				break;
			case procedur:
				strcpy(kind, "procedur");
				break;
		}
		switch(table[i].type)
		{
			case int_t:
				strcpy(type, "int");
				break;
			case char_t:
				strcpy(type, "char");
				break;
			case double_tt:
				strcpy(type, "double");
				break;
			case bool_t:
				strcpy(type, "bool");
				break;
			case none_t:
				strcpy(type, "none");
				break;
		}
		char ss[50];
		list_prints(table[i].array_size,ss);
		printf("%15s%15s%15d%15lf%15s%15d%15d%15d%15d%15s\n", table[i].name, kind, table[i].val, table[i].val_d, type, table[i].adr, table[i].size, table[i].array, table[i].array_dim, ss);
	}
	printf("****************************************************************************************************************************************************\n");
}