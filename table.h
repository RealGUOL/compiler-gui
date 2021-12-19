#include <stdio.h>
#include <string.h>

#define TXMAX 100
#define AL 20
#define LEVMAX 3
#define AMAX 65535
#define STACKSIZE 1000

FILE *ftable;      // 输出符号表
int lev = 0;       // 当前程序所在层
int tx=0;          // 符号表当前尾指针
int dx=0;          // 记录数据分配的相对地址
int num;           // 当前number
double num_d;      // 当前number
int size;
int array;         // 当前标识符是否是数组
struct list* array_size;
int array_dim;
char id[AL];
int error_count;
extern int line;
struct list{
    int v;
    struct list *next;
};
// 符号表中的类型
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
	char name[AL];                     // 名字
	enum object kind;                  // 类型：const，var或procedure
	enum type_e type;                  // 具体类型
	int val;                           // 数值，仅const使用
	int adr;                           // 地址，仅const不使用，如果kind=var，则表示变量在堆栈中的地址；如果kind=procedure，则表示过程在程序地址
	int size;                          // 需要分配的数据区空间, 仅procedure使用
	int array;                         // 当前符号是否是数组
	int array_dim;                     // array 维度
	double val_d;                      // 数值，仅const使用
	struct list* array_size;           // 记录多维数组每一维度大小
	};
struct table1 table[TXMAX+1];        // 符号表

struct procReg1{
int dx0;
int tx0;                             // tx0记录本层标识符的初始位置
int cx0;
};
struct procReg1 procReg;

// 获取array的len
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

// 获取array的最后一个元素
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

// 删除array的最后一个元素
int list_del_last(struct list* head)
{
	if(head==NULL){
		return 0;
	}
	struct list* each = head;
	struct list* befor = head;
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

// 获取array的第id个元素
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

// 打印array
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

// 向array中添加元素
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


/* 
 * 在符号表中加入一项 
 *
 * k: 标识符的种类为const，var或procedure
 * 
 */
void enter(enum object k){
	tx=tx+1; // 改变符号表指针
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
				// dx为当前应分配的变量的相对地址，分配后要增加1
				dx++;
			}
			break;
		case procedur:
			break;

		}
}

/* 
 * 查找标识符在符号表中的位置，从tx开始倒序查找标识符
 * 找到则返回在符号表中的位置，否则返回0
 * 
 * id:    要查找的名字
 * tx:    当前符号表尾指针
 */
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
	fprintf(ftable, "%15s%15s%15s%15s%15s%15s%15s%15s%15s%15s\n", "name", "kind", "val", "val_d", "type", "adr", "size", "array", "array_dim", "array_size");
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
		fprintf(ftable, "%15s%15s%15d%15lf%15s%15d%15d%15d%15d%15s\n", table[i].name, kind, table[i].val, table[i].val_d, type, table[i].adr, table[i].size, table[i].array, table[i].array_dim, ss);
	}
	printf("****************************************************************************************************************************************************\n");
}