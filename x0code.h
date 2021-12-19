#include "x0table.h"
#define CXMAX 1000
#define LOOPMAX 50

int cx,cx1,cx2;        // cx：代码指针，相当于p，虚拟机代码指针, 取值范围[0, cxmax-1]
int err;               // 错误计数器

// 虚拟机代码指令
enum fct{lit,opr,lod,sto,cal,ini,jmp,jpc,ext};
enum inloop{brk,ctn};
// 虚拟机代码指令名称
char *mnemonic[9]={"lit","opr","lod","sto","cal","ini","jmp","jpc", "ext"};

FILE *fcode;             // 输出符号表
FILE *ferrout;           // 输出文件及出错示意（如有错）、各行对应的生成代码首地址（如无错）
FILE *fresult;           // 输出执行结果
FILE *fin;               // 输入源文件
char fname[AL];

enum listswitcher{false,true};
enum listswitcher listswitch;

struct instruction{
	enum fct f;             // 虚拟机代码指令
	int l;                  // 引用层与声明层的层次差
	int a;                  // 根据f的不同而不同
	int isd;                // 是否是double类型
	double d;               // double类型的值
};
struct instruction code[CXMAX+1];  // 存放虚拟机代码的数组

struct loop{                       // 存放循环
	int cx;
	enum inloop type;
	int level;
};
struct loop loopReg[LOOPMAX];
int loop_pos=0;
int loop_level=0;

int become_level=0;
int pop_stack=0;
int array_id=0;

struct stack{
	int vi;            // 元素的值
	double vd;         // 元素的值
	enum type_e type;  // 元素的类型
};

void error(int n){
	printf("***");
	fputs("***",ferrout);
	printf("error%d",n);
	fprintf(ferrout,"error%d",n);
}

void code_error(char * s)
{
	printf("%s\n", s);
	exit(1);
}
void _gen(enum fct x,int y,int z,int isd,double d)
{
	if(cx>CXMAX)
		printf("program too long!");
	code[cx].f=x;
	code[cx].l=y;
	code[cx].a=z;
	code[cx].isd=isd;
	code[cx].d=d;
	cx++;
}

/* 
 * 生成虚拟机代码 
 *
 * x: instruction.f; 
 * y: instruction.l; 
 * z: instruction.a;
 */
void gen(enum fct x,int y,int z)
{
	_gen(x,y,z,0,0.0);
}

void listcode( )
{
	int i;
	if(listswitch==true){
		printf("****************************************************************************************************************************************************\n");
		printf("pcode:\n");
		printf("%15s %15s %15s %15s %15s %15s\n","id","f","l","a","isd","d");
		fprintf(fcode, "%15s %15s %15s %15s\n","id","f","l","a");
		for(i=0;i<=cx-1;i++){
			printf("%15d %15s %15d %15d %15d %15lf\n",i,mnemonic[(int)code[i].f],code[i].l,code[i].a,code[i].isd,code[i].d);
			fprintf(fcode, "%15d %15s %15d %15d %15d %15lf\n",i,mnemonic[(int)code[i].f],code[i].l,code[i].a);
		}
		printf("****************************************************************************************************************************************************\n");
	}
}


// 通过过程基址求上l层过程的基址
int base(int l,int b,struct stack s[STACKSIZE])
{
	int b1;
	b1=b;
	while(l>0){
		b1=s[b1].vi;
		l=l-1;
	}
	return b1;
}

/*
 * 解释程序 
 */
void interpret()
{
	int p=0;  // 指令指针
	int b=0;  // 指令基址
	int t=0;  // 栈顶指针
	struct instruction i; // 存放当前指令
	/*int s[STACKSIZE];*/
	struct stack s[STACKSIZE]; // 栈
	printf("********Start X0*********\n");
 	// fprintf(ferrout,"********Start PL/0*********\n");
	// s[0]不用
	s[0].vi=0;s[0].vd=0.0;s[0].type=int_t;
	// 主程序的三个联系单元均置为0
	s[1].vi=0;s[1].vd=0.0;s[1].type=int_t;
	s[2].vi=0;s[2].vd=0.0;s[2].type=int_t;
	s[3].vi=0;s[3].vd=0.0;s[3].type=int_t;
	int ti=tx;
	// 在栈中登记数组元素的类型
	while(ti>=0){
		if(table[ti].kind==variable){
			if(table[ti].array){
				int len = array_len(table[tx].array_size);
				int tj;
				if(table[ti].type==double_tt){
					for(tj=table[ti].adr;tj<(table[ti].adr+len);tj++){
						s[tj].type=double_tt;
					}
					
				}else{
					for(tj=table[ti].adr;tj<(table[ti].adr+len);tj++){
						s[tj].type=int_t;
					}
				}

			}else{
				if(table[ti].type==double_tt){
					s[table[ti].adr].type=double_tt;
				}else{
					s[table[ti].adr].type=int_t;
				}
			}
		}
		ti--;
	}
	do{
		i=code[p];  // 读当前指令
		p=p+1;
		switch(i.f){
			case lit:  // 将常量a的值取到栈顶
				t=t+1;
				if(i.isd){
					s[t].type=double_tt;
					s[t].vd=i.d;
				}else{
					s[t].type=int_t;
					s[t].vi=i.a;
				}
				break;
			case opr:  // 数学、逻辑运算
				switch(i.a){
					case 0:
						p=0;
						break;
					case 1:
						if(i.isd){
							s[t].type=double_tt;
							s[t].vd=-s[t].vd;
						}else{
							s[t].type=int_t;
							s[t].vi=-s[t].vi;
						}
						break;
					case 2:
						t=t-1;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vd+s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].type=double_tt;
							s[t].vd=s[t].vd+s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vi+s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].type=int_t;
							s[t].vi=s[t].vi+s[t+1].vi;
						}
						break;
					case 3:
						t=t-1;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vd-s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].type=double_tt;
							s[t].vd=s[t].vd-s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vi-s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].type=int_t;
							s[t].vi=s[t].vi-s[t+1].vi;
						}
						break;
					case 4:
						t=t-1;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vd*s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].type=double_tt;
							s[t].vd=s[t].vd*s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vi*s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].type=int_t;
							s[t].vi=s[t].vi*s[t+1].vi;
						}
						break;
					case 5:
						t=t-1;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vd/s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].type=double_tt;
							s[t].vd=s[t].vd/s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].type=double_tt;
							s[t].vd=s[t].vi/s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].type=int_t;
							s[t].vi=s[t].vi/s[t+1].vi;
						}
						break;
					case 6:
						if(s[t].type==double_tt){
							code_error("top of the stack is a double so that we do not know if it is odd.");
						}
						if((s[t].vi)%2==0)
							s[t].vi=0;
						else
							s[t].vi=1;
						break;
					case 8:
						t=t-1;
						if(s[t].type==double_tt||s[t+1].type==double_tt){
							code_error("tops of the stack are doubles so that we do not know if one is equals to another.");
						}
						if(s[t].vi==s[t+1].vi)
							s[t].vi=1;
						else
							s[t].vi=0;
						break;
					case 9:
						t=t-1;
						if(s[t].type==double_tt||s[t+1].type==double_tt){
							code_error("tops of the stack are doubles so that we do not know if one is equals to another.");
						}
						if(s[t].vi!=s[t+1].vi)
							s[t].vi=1;
						else
							s[t].vi=0;
						break;
					case 10:
						t--;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].vi=s[t].vd<s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].vi=s[t].vd<s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].vi=s[t].vi<s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].vi=s[t].vi<s[t+1].vi;
						}
						s[t].type=int_t;
						break;
					case 11:
						t--;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].vi=s[t].vd>=s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].vi=s[t].vd>=s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].vi=s[t].vi>=s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].vi=s[t].vi>=s[t+1].vi;
						}
						s[t].type=int_t;
						break;
					case 12:
						t=t-1;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].vi=s[t].vd>s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].vi=s[t].vd>s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].vi=s[t].vi>s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].vi=s[t].vi>s[t+1].vi;
						}
						s[t].type=int_t;
						break;
					case 13:
						t=t-1;
						if(s[t].type==double_tt&&s[t+1].type==double_tt){
							s[t].vi=s[t].vd<=s[t+1].vd;
						}else if(s[t].type==double_tt&&s[t+1].type==int_t){
							s[t].vi=s[t].vd<=s[t+1].vi;
						}else if(s[t].type==int_t&&s[t+1].type==double_tt){
							s[t].vi=s[t].vi<=s[t+1].vd;
						}else if(s[t].type==int_t&&s[t+1].type==int_t){
							s[t].vi=s[t].vi<=s[t+1].vi;
						}
						s[t].type=int_t;
						break;
					case 14:
						if(s[t].type==double_tt){
							printf("%lf",s[t].vd);
							fprintf(fresult,"%lf",s[t].vd);
						}else{
							printf("%d",s[t].vi);
							fprintf(fresult,"%d",s[t].vi);
						}
						t=t-1;
						break;
					case 15:
						printf("\n");
						fprintf(fresult,"\n");
						break;
					case 16:
						t=t+1;
						s[t].type=int_t;
						printf("?");
						fprintf(fresult,"?");
						if(i.isd){
							scanf("%lf",&s[t].vd);
							fprintf(fresult,"%lf",s[t].vd);
						}else{
							scanf("%d",&s[t].vi);
							fprintf(fresult,"%d",s[t].vi);
						}
						break;
					case 17:	/*写字符*/
						if(s[t].type==double_tt){
							code_error("top of the stack is a double so that we cannot write a charater.");
						}
						printf("%c",s[t].vi);
						fprintf(fresult,"%c",s[t].vi);
						t=t-1;
						break;
					case 18:	/*写栈顶值所在的数据单元int*/
						if(s[t].type==double_tt){
							code_error("top of the stack is a double so that we cannot write from a double address.");
						}
						if(s[s[t].vi].type==double_tt){
							printf("%lf",s[s[t].vi].vd);
							fprintf(fresult,"%lf",s[s[t].vi].vd);
						}else{
							printf("%d",s[s[t].vi].vi);
							fprintf(fresult,"%d",s[s[t].vi].vi);
						}
						t=t-1;
						break;
					case 19:	/*写栈顶值所在的数据单元char*/
						if(s[t].type==double_tt){
							code_error("top of the stack is a double so that we cannot write a charater to an address.");
						}
						if(s[s[t].vi].type==double_tt){
							code_error("adr of the stack is a double so that we cannot write a charater.");
						}
						printf("%c",s[s[t].vi].vi);
						fprintf(fresult,"%c",s[s[t].vi].vi);
						t=t-1;
						break;
					case 20:	/*MOD*/
						t=t-1;
						if(s[t].type==double_tt||s[t+1].type==double_tt){
							code_error("tops of the stack are doubles so that one cannot mod another.");
						}
						s[t].vi=s[t].vi%s[t+1].vi;
						break;
					case 21:	/*xor*/
						t=t-1;
						if(s[t].type==double_tt||s[t+1].type==double_tt){
							code_error("tops of the stack are doubles so that one cannot xor another.");
						}
						s[t].vi=s[t].vi^s[t+1].vi;
						break;
					case 22:	/*and*/
						t=t-1;
						if(s[t].type==double_tt||s[t+1].type==double_tt){
							code_error("tops of the stack are doubles so that one cannot and another.");
						}
						s[t].vi=s[t].vi&&s[t+1].vi;
						break;
					case 23:	/*or*/
						t=t-1;
						if(s[t].type==double_tt||s[t+1].type==double_tt){
							code_error("tops of the stack are doubles so that one cannot or another.");
						}
						s[t].vi=s[t].vi||s[t+1].vi;
						break;
					case 24:	/*not*/
						if(s[t].type==double_tt){
							code_error("top of the stack is double so that one cannot do |not|.");
						}
						s[t].vi=!s[t].vi;
						break;
					case 25:	/*写bool*/
						if(s[t].type==double_tt){
							code_error("tops of the stack are doubles so that one cannot be writen.");
						}
						printf("%s",s[t].vi==0?"false":"true");
						fprintf(fresult,"%s",s[t].vi==0?"false":"true");
						t=t-1;
						break;
					case 26: /*pop stack*/
						t=t-1;
						break;
				}
				break;	
			case lod:
				if(i.a==0)/*lod栈顶值所在的数据单元*/
				{
					if(s[t].type==double_tt){
							code_error("top of the stack is a double so that we cannot lod from a double address.");
					}
					if(s[t].vi>=table[array_id].adr+array_len(table[array_id].array_size)){
						/*printf("%d %d %d\n", table[array_id].adr, array_len(table[array_id].array_size), s[t].vi);*/
						code_error("\narray index out of range.");
					}
					if(s[base(i.l,b,s)+s[t].vi].type==double_tt){
						s[t].type=double_tt;
						s[t].vd=s[base(i.l,b,s)+s[t].vi].vd;
					}else{
						s[t].type=int_t;
						s[t].vi=s[base(i.l,b,s)+s[t].vi].vi;
					}
				}
				else
				{
					t=t+1;
					if(s[base(i.l,b,s)+i.a].type==double_tt){
						s[t].type=double_tt;
						s[t].vd=s[base(i.l,b,s)+i.a].vd;
					}else{
						s[t].type=int_t;
						s[t].vi=s[base(i.l,b,s)+i.a].vi;
					}
				}
				break;
			case sto:
				if(i.a==0)/*sto到次栈顶值所在的数据单元，数据源为栈顶*/
				{
					if(s[t-1].type==double_tt){
							code_error("top of the stack is a double so that we cannot lod from a double address.");
					}
					if(s[t-1].vi>=table[array_id].adr+array_len(table[array_id].array_size)){
						/*printf("%d %d %d\n", table[array_id].adr, array_len(table[array_id].array_size), s[t-1].vi);*/
						code_error("\narray index out of range.");
					}
					if(s[base(i.l,b,s)+s[t-1].vi].type==double_tt){
						if(s[t].type==double_tt){
							s[base(i.l,b,s)+s[t-1].vi].vd=s[t].vd;
							s[t-1].type=s[base(i.l,b,s)+s[t-1].vi].type;
							s[t-1].vd=s[t].vd;
						}else{
							s[base(i.l,b,s)+s[t-1].vi].vd=s[t].vi;
							s[t-1].type=s[base(i.l,b,s)+s[t-1].vi].type;
							s[t-1].vd=s[t].vi;
						}
					}else{
						if(s[t].type==double_tt){
							s[base(i.l,b,s)+s[t-1].vi].vi=(int)s[t].vd;
							s[t-1].type=s[base(i.l,b,s)+s[t-1].vi].type;
							s[t-1].vi=(int)s[t].vd;
						}else{
							s[base(i.l,b,s)+s[t-1].vi].vi=s[t].vi;
							s[t-1].type=s[base(i.l,b,s)+s[t-1].vi].type;
							s[t-1].vi=s[t].vi;
						}
					}
					t=t-1;
				}
				else
				{
					if(s[base(i.l,b,s)+i.a].type==double_tt){
						if(s[t].type==double_tt){
							s[base(i.l,b,s)+i.a].vd=s[t].vd;
						}else{
							s[base(i.l,b,s)+i.a].vd=s[t].vi;
						}
					}else{
						if(s[t].type==double_tt){
							s[base(i.l,b,s)+i.a].vi=(int)s[t].vd;
						}else{
							s[base(i.l,b,s)+i.a].vi=s[t].vi;
						}
					}
					t=t-1;
				}
				break;
			case cal:
			/*
				s[t+1]=base(i.l,b,s);
				s[t+2]=b;
				s[t+3]=p;
				b=t+1;
				p=i.a;
			*/
				break;
			case ini:
				t=t+i.a;
				break;
			case jmp:
				p=i.a;
				break;
			case jpc:
				if(s[t].type==double_tt){
					code_error("top of the stack is a double so that we do not know if it is equals to zero.");
				}
				if(s[t].vi==0)
					p=i.a;
				t=t-1;
				break;
			case ext:						/* exit */
				p=0;
				break;
			}
		}while(p!=0);
		printf("\n********End X0***********\n");
		fclose(fresult);
}