typedef union{
char *ident;
int number;
double number_d;
void* ptr;
char *type;
struct databus* db;
} YYSTYPE;
#define	ID	257
#define	NUM	258
#define	NUM_C	259
#define	NUM_D	260
#define	INT	261
#define	CHAR	262
#define	DOUBLE	263
#define	BOOL	264
#define	CONST	265
#define	PLUS	266
#define	MINUS	267
#define	TIMES	268
#define	SLASH	269
#define	EQL	270
#define	NEQ	271
#define	LES	272
#define	LEQ	273
#define	GTR	274
#define	GEQ	275
#define	MOD	276
#define	XOR	277
#define	ODD	278
#define	SPLUS	279
#define	SMINUS	280
#define	UMINUS	281
#define	AND	282
#define	OR	283
#define	NOT	284
#define	LPAREN	285
#define	RPAREN	286
#define	LBRACKETS	287
#define	RBRACKETS	288
#define	LBRACE	289
#define	RBRACE	290
#define	COMMA	291
#define	SEMICOLON	292
#define	PERIOD	293
#define	BECOMES	294
#define	COLON	295
#define	MAIN	296
#define	IF	297
#define	ELSE	298
#define	WHILE	299
#define	WRITE	300
#define	READ	301
#define	DO	302
#define	CALL	303
#define	SWITCH	304
#define	CASE	305
#define	DEFAULT	306
#define	BREAK	307
#define	CONTINUE	308
#define	FOR	309
#define	REPEAT	310
#define	UNTIL	311
#define	EXIT	312


extern YYSTYPE yylval;

int compile(const char* filePath);