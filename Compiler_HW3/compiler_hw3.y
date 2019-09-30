/*	Definition section */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int yylineno;
extern int yylex();
void yyerror();
extern char* yytext;   // Get current token from lex
extern char buf[256];  // Get current code line from lex
char savebuf[256];
char syntaxerror[256];
char syntaxerrorToken[100];
char saveAttri[1000];

/**********************************************************************/
#define get_data(Val)   ( Val.type == I_CONST ? Val.data.idata : Val.data.fdata )
#define operation(left, op, right)  if((left.type == I_CONST) && (right.type == I_CONST)){  \
                                        ret.type = I_CONST;                                 \
                                        ret.data.idata = get_data(left) op get_data(right); \
                                    }                                                       \
                                    else{                                                   \
                                        ret.type = F_CONST;                                 \
                                        ret.data.fdata = get_data(left) op get_data(right); \
                                    }
#define print_rel($$) printf("%s\n",get_data($$) ? " true" : " false");
#define print_type(type)    if(type == I_CONST) fprintf(file, "\ti");\
			    else if(type == F_CONST) fprintf(file, "\tf");\
			    else fprintf(file, "\ta");
#define def_type_trans(left, right)     if((left.type == I_CONST)&&(right.type == F_CONST))    fprintf(file, "\tf2i\n"); \
					if((left.type == F_CONST)&&(right.type == I_CONST)) fprintf(file, "\ti2f\n");
/**********************************************************************/
//define print_type(type)    type == I_CONST ? fprintf(file, "\ti") : fprintf(file, "\tf")
/* Strcuct */
typedef union _DATA{
    int     idata;
    double  fdata;
    char    sdata[101];
    bool    bdata;
}DATA;

typedef struct _INT_FLOAT{
    int     type;
    DATA    data;
    int	    iidx;
}INT_FLOAT;

typedef struct _Variable{
    char    id[100];
    char    kind[10];
    char    attribute[1000];
    INT_FLOAT  Val;
    int iidx;
}Variable;

struct Table{
    int index;
    int depth;
    Variable Var[1001];
    struct Table* prev;
    struct Table* next;
};

/* Symbol table function - you can add new function if need. */
Variable* lookup_symbol(struct Table*, char* id);
void create_symbol(struct Table** table);
void insert_symbol(struct Table** table, char* id, int type, int kind, INT_FLOAT Var);
void dump_symbol(struct Table* table);
void print_redeclaredV();
void print_undeclaredV();
void print_redeclaredF();
void print_undeclaredF();
void print_syntaxError();
INT_FLOAT get_id(char* id);
void new_scope();
void delete_scope();

FILE* file;
INT_FLOAT val_assign(int type, void* value, int index);
INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right);
void assign_expr(char* id, INT_FLOAT value);
void assign_id(char* id, int op, INT_FLOAT expr);
int var_idx;
int ERROR = 0;
void print_var(char* id);
void print_load(char* id);
void print_store(char* id);
void print_jump(int op, char* label_name);
void print_label(char* label_name);
void alu_type_trans(INT_FLOAT left, INT_FLOAT right);
void op_assign(INT_FLOAT left, INT_FLOAT right);
int bool_handler(INT_FLOAT left, int op, INT_FLOAT right);
int isWhile = 0;
int label_idx = 0;

struct Table* CUR_TABLE;
int depth;
int reDeclarV=0, unDeclarV=0, reDeclarF=0, unDeclarF=0;
char* saveID;
int isVariable=0, isFunction=0;
int wkind; //0=variable, 1=function, 2=parameter
int countAttri=0, iferror=0, isforward=0;
%}

/* Using union to define nonterminal and token type */
%union {
    int i_val;
    float f_val;
    char* string;
    bool b_val;
    INT_FLOAT if_val;
}
 
/* Token without return */
%token PRINT
%token IF ELSE FOR WHILE
%token VOID
%token COMMA SEMICOLON LSB RSB
%token NEWLINE
%token ADD SUB MUL DIV MOD INC DEC
%token MT LT MTE LTE EQ NE
%token ASGN ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%token AND OR NOT
%token LB RB LCB RCB

/* Token with return, which need to sepcify type */
%token <i_val> I_CONST
%token <f_val> F_CONST
%token <string> STRING
%token <string> ID
%token <i_val> INT
%token <i_val> FLOAT
%token <b_val> BOOL
%token <if_val> TRUE FALSE
%token <if_val> RET CONT BREAK

/* Nonterminal with return, which need to sepcify type */
%type <if_val> expression_stat
%type <if_val> initializer
%type <if_val> identifier
%type <f_val> incdec_stat
%type <i_val> type
%type <if_val> literal
%type <if_val> operand
%type <if_val> bool_stat
%type <i_val> boolean_expr

/* Yacc will start at this nonterminal */
%start program

/* Precedence */
%left OR
%left AND
%left ADDASGN SUBASGN MULASGN DIVASGN MODASGN
%left EQ NE MT LT MTE LTE
%left ADD SUB
%left MUL DIV MOD
%left INC DEC
/* Grammar section */
%%

program
    : program stat
    |
;

stat
    : declaration       {}
    | compound_stat     {}
    | expression_stat   {}
    | print_func        {}
    | function		{}
    | NEWLINE		{}
;

function
    : type ID LB {new_scope(); if(strcpy($2,"main")==0) fprintf(file, ".method public static %s()\n.limit stack 50\n.limit locals 50\n",$2);} paramater RB ifforward {isFunction=1;} NEWLINE {
	if(isforward == 0) dump_symbol(CUR_TABLE);
	else if(isforward == 1) {CUR_TABLE==NULL;isforward=0;}
	delete_scope(); 
	INT_FLOAT n;
	isVariable = 0;
	wkind = 1;
	insert_symbol(&CUR_TABLE, $2, $1, wkind, n); 
	if(strcpy($2,"main")==0) fprintf(file, "\treturn\n.end method\n");
	if(reDeclarF==1 && isVariable==0) print_redeclaredF();}
    | ID LB paramater RB SEMICOLON {isFunction=1; isVariable = 0; get_id($1);} NEWLINE{
	fprintf(file, "invokestatic compeiler_hw3/%s()",$1);
	if(unDeclarF==1 && isVariable==0) print_undeclaredF();
        if(unDeclarV==1) print_undeclaredV();}

ifforward
    : fblock
    | SEMICOLON {isforward=1;}

paramater
    : type ID COMMA {INT_FLOAT n; wkind=2; insert_symbol(&CUR_TABLE, $2, $1, wkind, n);} paramater{}
    | type ID {INT_FLOAT n; wkind=2; insert_symbol(&CUR_TABLE, $2, $1, wkind, n); }
    | ID COMMA paramater {get_id($1);}
    | ID {get_id($1);}
    | {}
    | expression_stat 
;

fblock
    :flcb program RET operand SEMICOLON NEWLINE frcb {}
    |flcb program frcb {}
;

flcb
    : LCB
;

frcb
    : RCB
;

declaration
    : type ID ASGN initializer SEMICOLON {isVariable=1; wkind=0; insert_symbol(&CUR_TABLE, $2, $1, wkind, $4);} NEWLINE {
	if(reDeclarV==1) print_redeclaredV();}
    | type ID SEMICOLON {isVariable=1; INT_FLOAT n; wkind=0; fprintf(file, "\tldc 0\n"); insert_symbol(&CUR_TABLE, $2, $1, wkind, n);} NEWLINE {
	if(reDeclarV==1) print_redeclaredV();}
;

type
    : INT   { $$ = I_CONST; }
    | FLOAT { $$ = F_CONST; }
    | STRING{ $$ = STRING; }
    | BOOL  { $$ = BOOL; }
    | VOID  { $$ = VOID; }
;

initializer
    : expression_stat
;

compound_stat
    : incdec_stat SEMICOLON
    | assign_stat SEMICOLON
    | if_stat
    | while_stat
    | block
;

incdec_stat
    : ID INC {
	INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
	fprintf(file, "\tldc 1\n");
	assign_id($1, ADD, one);
    }
    | ID DEC {
	INT_FLOAT one;
        one.type = I_CONST;
        one.data.idata = 1;
	fprintf(file, "\tldc 1\n");
	assign_id($1, SUB, one);
    }
;

assign_stat
    : ID ASGN expression_stat    { assign_expr($1, $3); print_store($1); }
    | ID ADDASGN expression_stat { assign_id($1, ADD, $3); }
    | ID SUBASGN expression_stat { assign_id($1, SUB, $3); }
    | ID MULASGN expression_stat { assign_id($1, MUL, $3); }
    | ID DIVASGN expression_stat { assign_id($1, DIV, $3); }
    | ID MODASGN expression_stat { assign_id($1, MOD, $3); }
;

if_stat
    : IF boolean_expr block NEWLINE { 
	dump_symbol(CUR_TABLE);
	delete_scope();
	fprintf(file, "\tgoto EXIT_0\n");
	fprintf(file, "LABEL_ELSE%d:\n", label_idx);
	if(unDeclarV==1) print_undeclaredV();}
    | IF boolean_expr block ELSE LCB NEWLINE{
	dump_symbol(CUR_TABLE);
	delete_scope();
	fprintf(file, "\tgoto EXIT_0\n");
	fprintf(file, "LABEL_ELSE%d:\n", label_idx);
	label_idx++;
	if(unDeclarV==1) print_undeclaredV();
        new_scope();} program rcb NEWLINE {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
    | IF boolean_expr block ELSE {
	dump_symbol(CUR_TABLE);
	delete_scope();
	fprintf(file, "\tgoto EXIT_0\n");
	fprintf(file, "LABEL_ELSE%d:\n", label_idx);
	label_idx++;
	if(unDeclarV==1) print_undeclaredV();} if_stat {}
;

boolean_expr
    : LB boolean_expr RB { $$ = $2; }
    | expression_stat AND expression_stat { $$ = bool_handler($1, AND, $3);
	if(isWhile != 1) { print_jump(AND,"LABEL_AND"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_AND"); }
    }
    | expression_stat OR expression_stat { $$ = bool_handler($1, OR, $3);
	if(isWhile != 1) { print_jump(OR,"LABEL_OR"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_OR"); }
    }
    | expression_stat EQ expression_stat { $$ = bool_handler($1, EQ, $3);
	if(isWhile != 1) { print_jump(EQ,"LABEL_EQ"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_EQ"); }
    }
    | expression_stat NE expression_stat { $$ = bool_handler($1, NE, $3);
	if(isWhile != 1) { print_jump(NE,"LABEL_NE"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_NE"); }
    }
    | expression_stat LT expression_stat { $$ = bool_handler($1, LT, $3); 
	if(isWhile != 1) { print_jump(LT,"LABEL_LT"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_LT"); }
    }
    | expression_stat LTE expression_stat { $$ = bool_handler($1, LTE, $3); 
        if(isWhile != 1) { print_jump(LTE,"LABEL_LTE"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_LTE"); }
    }
    | expression_stat MT expression_stat { $$ = bool_handler($1, MT, $3);
	if(isWhile != 1) { print_jump(MT,"LABEL_MT"); fprintf(file, "\tgoto LABEL_ELSE%d\n",label_idx); print_label("LABEL_MT"); }
    }
    | expression_stat MTE expression_stat { $$ = bool_handler($1, MTE, $3);
	if(isWhile != 1) { print_jump(MTE,"LABEL_MTE"); fprintf(file, "\tgoto LABEL_ELSE%d\n", label_idx); print_label("LABEL_MTE"); }
    }

while_stat
    : WHILE {print_label("LABEL_BEGIN"); isWhile = 1;} LB boolean_expr RB{
	print_jump(LT,"LABEL_TRUE");fprintf(file, "\tgoto LABEL_FALSE\n");print_label("LABEL_TRUE"); } block NEWLINE {
	dump_symbol(CUR_TABLE);
	delete_scope();
	print_label("LABEL_FALSE");
	isWhile = 0;
	if(unDeclarV==1) print_undeclaredV(); }
;

block
    : lcb program rcb { }
;

lcb
    : LCB { new_scope(); }
;

rcb 
    : RCB { /*fprintf(file, "\tgoto EXIT_0\n");*/ }
;

print_func
    : PRINT LB expression_stat RB SEMICOLON {
	fprintf(file, "\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n\tswap\n");
        switch($3.type){
            case I_CONST:
                fprintf(file, "\tinvokevirtual java/io/PrintStream/println(I)V\n");
                break;
            case F_CONST:
                fprintf(file, "\tinvokevirtual java/io/PrintStream/println(F)V\n");
                break;
            case STRING:
                fprintf(file, "\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
		break;
	}
	memcpy(&savebuf,buf,256);} NEWLINE {if(unDeclarV==1) print_undeclaredV();}
;

expression_stat
    : operand
    | expression_stat AND expression_stat { $$ = alu($1,AND,$3); }
    | expression_stat OR expression_stat  { $$ = alu($1,OR,$3); }
    | expression_stat EQ expression_stat  { $$ = alu($1,EQ,$3); }
    | expression_stat NE expression_stat  { $$ = alu($1,NE,$3); }
    | expression_stat LT expression_stat  { $$ = alu($1,LT,$3); }
    | expression_stat LTE expression_stat { $$ = alu($1,LTE,$3); }
    | expression_stat MT expression_stat  { $$ = alu($1,MT,$3); }
    | expression_stat MTE expression_stat { $$ = alu($1,MTE,$3); }
    | expression_stat ADD expression_stat { $$ = alu($1,ADD,$3); }
    | expression_stat SUB expression_stat { $$ = alu($1,SUB,$3); }
    | expression_stat MUL expression_stat { $$ = alu($1,MUL,$3); }
    | expression_stat DIV expression_stat { $$ = alu($1,DIV,$3); }
    | expression_stat MOD expression_stat { $$ = alu($1,MOD,$3); }
;

operand
    : literal
    | identifier
    | bool_stat
    | LB expression_stat RB { $$ = $2; }
    | {}
;

literal
    : I_CONST { $$ = val_assign(I_CONST, &$1, -1); fprintf(file, "\tldc %d\n", $1); }
    | F_CONST { $$ = val_assign(F_CONST, &$1, -1); fprintf(file, "\tldc %f\n", $1); }
    | STRING  { $$ = val_assign(STRING, &$1, -1); fprintf(file, "\tldc \"%s\"\n", $1); }
;

identifier
    : ID { $$ = get_id($1); print_load($1); } 
;

bool_stat
    : TRUE	{ $$ = $1; }
    | FALSE	{ $$ = $1; }
;

%%

/* C code section */

int main(int argc, char** argv)
{
    yylineno = 0;
    char str1[] = "(";
    char str2[] = ")";
    char str3[] = "{";
    char token[100];
    int seti=0, setf=0;

    file = fopen("compiler_hw3.j","w");
    fprintf(file,   ".class public compiler_hw3\n"
                    ".super java/lang/Object\n"
		    ".method public static main([Ljava/lang/String;)V\n"
		    ".limit stack 50\n"
		    ".limit locals 50\n");

    yyparse();
    if(iferror == 0){
    	dump_symbol(CUR_TABLE);
    	printf("\nTotal lines: %d \n",yylineno);
    }
    // if syntactic error
    else if(iferror == 1){
	printf("%d:%s\n",yylineno+1, syntaxerror);	// print error line
	if(strpbrk(syntaxerror,str1) && strpbrk(syntaxerror,str2) && strpbrk(syntaxerror,str3)){
		for(int i=0 ; i<strlen(syntaxerror) ; i++){
			if(syntaxerror[i]==' ' && syntaxerror[i+1]!='(') seti=i;
			if((syntaxerror[i]==' ' && syntaxerror[i+1]=='(')||(syntaxerror[i]=='(')){
				setf=i;
				i=strlen(syntaxerror);
			}
		}
                printf("\n|-----------------------------------------------|\n");
    		printf("| Error found in line %d:%s\n", yylineno+1, syntaxerror);
    		printf("| Undeclared function ");
		for(int i=seti+1 ; i<setf ; i++){ printf("%c", syntaxerror[i]); }
    		printf("\n|-----------------------------------------------|\n\n");
		ERROR = 1;
	}
	print_syntaxError();
    }

    fprintf(file, "\tgoto EXIT_0\n");
    fprintf(file, "EXIT_0:\n"
		  "\treturn\n"
                  ".end method\n");
    fclose(file);
    if(ERROR == 1) remove("compiler_hw3.j");

    return 0;
}

void yyerror(char *s)
{
    memcpy(&syntaxerror, buf, 256);
    memcpy(&syntaxerrorToken, s, 100);
    iferror = 1;
}

void print_syntaxError(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno+1, syntaxerror);
    printf("| %s", syntaxerrorToken);
    printf("\n|-----------------------------------------------|\n\n");
    ERROR = 1;
}

void create_symbol(struct Table** table) {
    *table = (struct Table*)malloc(sizeof(struct Table));
    memset(*table, 0, sizeof(struct Table));
}

int noAttri=0, functionDec=0, ii=0, idx=0;
void insert_symbol(struct Table** table, char* id, int type, int kind, INT_FLOAT n){
    if(*table == NULL)  create_symbol(table);
    // Detect if redeclare
    for(int i=1 ; i<=CUR_TABLE->index ; ++i){
        if(strcmp(id, CUR_TABLE->Var[i].id)==0 && type!=(CUR_TABLE->Var[i].Val.type)){
		if(isFunction == 1){ reDeclarF = 1; reDeclarV = 0;}
		if(isVariable == 1){ reDeclarV = 1; reDeclarF = 0;}
		memcpy(&savebuf,buf,256);
		saveID = id;
        	return;
	}
	else if(strcmp(id, CUR_TABLE->Var[i].id)==0 && type==(CUR_TABLE->Var[i].Val.type) && isFunction==1)
		functionDec = 1;
		ii = i;
    }

    if(functionDec==0){
    	// insert symbol
    	idx = ++((*table)->index);
    	strcpy((*table)->Var[idx].id, id);
    	(*table)->Var[idx].Val = n;
    	(*table)->Var[idx].Val.type = type;
	(*table)->Var[idx].iidx = (*table)->Var[idx].Val.iidx = var_idx++;
        def_type_trans((*table)->Var[idx].Val, n);
	if(wkind != 1){
		if(type == I_CONST) fprintf(file, "\tistore %d\n", (*table)->Var[idx].iidx);
    		else if(type == F_CONST) fprintf(file, "\tfstore %d\n", (*table)->Var[idx].iidx);
    		else fprintf(file, "\tastore %d\n", (*table)->Var[idx].iidx);
	}
    }
    // set attribute table
    if(kind == 0) memcpy( (*table)->Var[idx].kind, "variable", 10 );
    else if(kind == 1){ 
	memcpy( (*table)->Var[idx].kind, "function", 10 );
	if(countAttri != 0){
		char getAttri[1000];
		strncpy(getAttri,saveAttri,countAttri-2);
		getAttri[countAttri-2] = '\0';
		if(functionDec==0)
			memcpy( (*table)->Var[idx].attribute, getAttri, 1000 );		// get attribute
		else if(functionDec==1) {
			memcpy( (*table)->Var[ii].attribute, getAttri, 1000 );
			functionDec=0;
		}
		memset(&saveAttri, '\0', 1000);
		memset(&getAttri, '\0', 1000);
        	countAttri = 0;
	}
    }
    else if(kind ==2){
	memcpy( (*table)->Var[idx].kind, "parameter", 10 );
	if(type == I_CONST){ 
		strcat(saveAttri,"int, ");
		countAttri = countAttri+5;
	}
	else if(type == F_CONST){ 
                strcat(saveAttri,"float, ");
                countAttri = countAttri+7;
        }
	else if(type == STRING){
                strcat(saveAttri,"string, ");
                countAttri = countAttri+8;
        }
	else if(type == BOOL){
                strcat(saveAttri,"bool, ");
                countAttri = countAttri+6;
        }
	else countAttri = 0;
    }
}

void print_redeclaredV(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Redeclared variable %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    reDeclarV = 0;
    saveID = '\0';
    ERROR = 1;
}

void print_redeclaredF(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Redeclared function %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    reDeclarF = 0;
    saveID = '\0';
    isFunction = 0;
    ERROR = 1;
}

Variable* lookup_symbol(struct Table* table, char* id) {
    if(table == NULL)   return NULL;
    for(int i=1 ; i<=table->index ; ++i){
        if(!strcmp(id, table->Var[i].id)){
            depth = table->depth;
            return &(table->Var[i]);
        }
    }
    if(table->prev != NULL)
        return lookup_symbol(table->prev, id);
    return NULL;
}

void dump_symbol(struct Table* table) {
    if(table->index > 0){
    	printf("\n%-10s%-10s%-12s%-10s%-10s%-10s\n\n","Index", "Name", "Kind", "Type", "Scope", "Attribute");
    	for(int i=1; i<=table->index ; ++i){
        	switch(table->Var[i].Val.type){
            	case I_CONST: if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "int", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "int", table->depth, table->Var[i].attribute);
			      break; 
            	case F_CONST: if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "float", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "float", table->depth, table->Var[i].attribute);
			      break;
            	case STRING:  if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "string", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "string", table->depth, table->Var[i].attribute);
			      break;
	    	case BOOL:    if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "bool", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "bool", table->depth, table->Var[i].attribute);
			      break;
		case VOID:    if(*table->Var[i].attribute == '\0') printf("%-10d%-10s%-12s%-10s%-10d\n", i-1, table->Var[i].id, table->Var[i].kind, "void", table->depth);
			      else printf("%-10d%-10s%-12s%-10s%-10d%s\n", i-1, table->Var[i].id, table->Var[i].kind, "void", table->depth, table->Var[i].attribute);
			      break;
        	}
    	}
	printf("\n");
    }
}

INT_FLOAT get_id(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL){
	if(isFunction == 1){ unDeclarF = 1; unDeclarV = 0;}
        if(isVariable == 1){ unDeclarV = 1; unDeclarF = 0;}
	memcpy(&savebuf, buf, 256);
        saveID = id;
        INT_FLOAT n = {0};
        return n;
    }
    else
        return v->Val;
}

void print_undeclaredV(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Undeclared variable %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    unDeclarV = 0;
    saveID = '\0';
    ERROR = 1;
}

void print_undeclaredF(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Undeclared function %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    unDeclarF = 0;
    saveID = '\0';
    ERROR = 1;
}

void new_scope(){
    if(CUR_TABLE == NULL) {
	create_symbol(&CUR_TABLE);
	(CUR_TABLE->depth)++;
    }
    struct Table* next;
    create_symbol(&next);
    CUR_TABLE->next = next;
    next->prev = CUR_TABLE;
    next->depth = CUR_TABLE->depth + 1;
    CUR_TABLE = next;
}

void delete_scope(){
    CUR_TABLE = CUR_TABLE->prev;
    free(CUR_TABLE->next);
}

INT_FLOAT val_assign(int type, void* value, int index){
    INT_FLOAT Val;
    Val.type = type;
    Val.iidx = index;
    switch(type){                                           
        case I_CONST:
            Val.data.idata = *(int*) value;
            break;
        case F_CONST:
            Val.data.fdata = *(double*) value; 
            break;
        case STRING: 
            strcpy(Val.data.sdata, (char*) value);     
            break;
    }
    return Val;
}

INT_FLOAT alu(INT_FLOAT left, int op, INT_FLOAT right){
    INT_FLOAT ret;
    alu_type_trans(left, right);
    switch(op){    
        case ADD:
            fprintf(file, "add\n");
            operation(left, +, right);
            break;
        case SUB:
            fprintf(file, "sub\n");
            operation(left, -, right);
            break;
        case MUL:
            fprintf(file, "mul\n");
            operation(left, *, right);
            break;
        case DIV:
            if((right.iidx == -1)&&(((right.type == I_CONST) && (right.data.idata == 0)) || ((right.type == F_CONST) && (right.data.fdata == 0)))){
		memcpy(&savebuf, buf, 256);
		printf("\n|-----------------------------------------------|\n");
    		printf("| Error found in line %d:%s\n", yylineno+1, savebuf);
    		printf("| Variables of numbers is divided by 0");
    		printf("\n|-----------------------------------------------|\n\n");
		memset(&savebuf, '\0', 256);
                ERROR = 1;
                ret.type = -1;
            }
            else {
                fprintf(file, "div\n");
                operation(left, /, right);
            }
            break;
        case MOD:
            if((left.type == I_CONST) && (right.type == I_CONST)){
                fprintf(file, "rem\n");
                ret.type = I_CONST;
                ret.data.idata = left.data.idata % right.data.idata;
            }
            else{
		memcpy(&savebuf, buf, 256);
		printf("\n|-----------------------------------------------|\n");
                printf("| Error found in line %d:%s\n", yylineno+1, savebuf);
                printf("| Modulo operator with floating point operands.");
                printf("\n|-----------------------------------------------|\n\n");
		memset(&savebuf, '\0', 256);
                ERROR = 1;
                ret.type = -1;
            }
            break;
    }
    return ret;
}

void assign_expr(char* id, INT_FLOAT Val){
     Variable* v = lookup_symbol(CUR_TABLE, id);
     if(v == NULL){
        print_undeclaredV();
    }
     else{
        def_type_trans(v->Val, Val);
        v->Val = val_assign(v->Val.type, &Val.data, v->Val.iidx);
    }
}

void assign_id(char* id, int op, INT_FLOAT expr){
    INT_FLOAT left = get_id(id);
    op_assign(left, expr);
    INT_FLOAT Val = alu(left, op, expr);
    assign_expr(id, Val);
    print_var(id);
}

void print_var(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v->Val.type == I_CONST) fprintf(file, "\tistore %d\n", v->iidx);
    else if(v->Val.type == F_CONST) fprintf(file, "\tfstore %d\n", v->iidx);
    else fprintf(file, "\tastore %d\n", v->iidx);
}

void print_load(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    print_type(v->Val.type);
    fprintf(file, "load %d\n", v->iidx);
}

void print_store(char* id){
    Variable* v = lookup_symbol(CUR_TABLE, id);
    if(v == NULL)   return;
    print_type(v->Val.type);
    fprintf(file, "store %d\n", v->iidx);
}

void alu_type_trans(INT_FLOAT left, INT_FLOAT right){
    if((left.type == F_CONST)&&(right.type == I_CONST))
        fprintf(file, "\ti2f\n\tf");
    else if((left.type == I_CONST)&&(right.type == F_CONST))
        fprintf(file, "\tfstore %d\n\ti2f\n\tfload %d\n\tf", var_idx, var_idx);
    else if((left.type == I_CONST)&&(right.type == I_CONST))
        fprintf(file, "\ti");
    else if((left.type == F_CONST)&&(right.type == F_CONST))
        fprintf(file, "\tf");
    else 
	fprintf(file, "\ta");
}

void op_assign(INT_FLOAT left, INT_FLOAT right){
    print_type(right.type); 
    fprintf(file, "store %d\n", var_idx);
    print_type(left.type); 
    fprintf(file, "load %d\n", left.iidx);
    print_type(right.type); 
    fprintf(file, "load %d\n", var_idx);
}

int bool_handler(INT_FLOAT left, int op, INT_FLOAT right){
    //INT_FLOAT ret;
    if((left.type == F_CONST) || (right.type == F_CONST)){
        alu_type_trans(left, right);
        fprintf(file, "cmpl\n");
    }
    else{
        alu_type_trans(left, right);
        fprintf(file, "sub\n");
    }
    return op;
}

void print_label(char* label_name){
    if(label_name == "LABEL_FALSE") fprintf(file, "\tgoto LABEL_BEGIN\n");
    else if(label_name != "LABEL_BEGIN" && label_name != "LABEL_TRUE")
    	fprintf(file, "\tgoto EXIT_0\n");
    fprintf(file, "%s:\n", label_name);
}

void print_jump(int op, char* label_name){
    switch(op){
        case AND:
            break;
        case OR:
            break;
        case EQ:
	    fprintf(file, "\tifeq %s\n", label_name);
            break;
        case NE:
	    fprintf(file, "\tifne %s\n", label_name);
            break;
        case LT:
	    fprintf(file, "\tiflt %s\n", label_name);
            break;
        case LTE:
	    fprintf(file, "\tifle %s\n", label_name);
            break;
        case MT:
	    fprintf(file, "\tifgt %s\n", label_name);
            break;
        case MTE:
	    fprintf(file, "\tifge %s\n", label_name);
            break;
        default:
            fprintf(file, "\tgoto %s\n", label_name);
            break;
    }
}
