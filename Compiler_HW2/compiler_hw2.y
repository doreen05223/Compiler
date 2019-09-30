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
}INT_FLOAT;

typedef struct _Variable{
    char    id[100];
    char    kind[10];
    char    attribute[1000];
    INT_FLOAT  Val;
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

/* Yacc will start at this nonterminal */
%start program

/* Precedence */
%left OR
%left AND
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
    : type ID LB {new_scope();} paramater RB ifforward {isFunction=1;} NEWLINE {
	if(isforward == 0) dump_symbol(CUR_TABLE);
	else if(isforward == 1) {CUR_TABLE==NULL;isforward=0;}
	delete_scope(); 
	INT_FLOAT n;
	isVariable = 0;
	wkind = 1;
	insert_symbol(&CUR_TABLE, $2, $1, wkind, n); 
	if(reDeclarF==1 && isVariable==0) print_redeclaredF();}
    | ID LB paramater RB SEMICOLON {isFunction=1; isVariable = 0; get_id($1);} NEWLINE{
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
    | type ID SEMICOLON {isVariable=1; INT_FLOAT n; wkind=0; insert_symbol(&CUR_TABLE, $2, $1, wkind, n);} NEWLINE {
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
    : ID INC {}
    | ID DEC {}
;

assign_stat
    : ID ASGN expression_stat    {}
    | ID ADDASGN expression_stat {}
    | ID SUBASGN expression_stat {}
    | ID MULASGN expression_stat {}
    | ID DIVASGN expression_stat {}
    | ID MODASGN expression_stat {}
;

if_stat
    : IF expression_stat block NEWLINE { 
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
    | IF expression_stat block ELSE LCB NEWLINE{
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();
        new_scope();} program rcb NEWLINE {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
    | IF expression_stat block ELSE {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();} if_stat {}
;

while_stat
    : WHILE expression_stat block NEWLINE {
	dump_symbol(CUR_TABLE);
	delete_scope();
	if(unDeclarV==1) print_undeclaredV();}
;

block
    : lcb program rcb {}
;

lcb
    : LCB {new_scope();}
;

rcb 
    : RCB
;

print_func
    : PRINT LB expression_stat RB SEMICOLON {memcpy(&savebuf,buf,256);} NEWLINE {if(unDeclarV==1) print_undeclaredV();}
;

expression_stat
    : operand
    | expression_stat AND expression_stat {}
    | expression_stat OR expression_stat  {}
    | expression_stat EQ expression_stat  {}
    | expression_stat NE expression_stat  {}
    | expression_stat LT expression_stat  {}
    | expression_stat LTE expression_stat {}
    | expression_stat MT expression_stat  {}
    | expression_stat MTE expression_stat {}
    | expression_stat ADD expression_stat {}
    | expression_stat SUB expression_stat {}
    | expression_stat MUL expression_stat {}
    | expression_stat DIV expression_stat {}
    | expression_stat MOD expression_stat {}
;

operand
    : literal
    | identifier
    | bool_stat
    | LB expression_stat RB { $$ = $2; }
;

literal
    : I_CONST {}
    | F_CONST {}
    | STRING  {}
;

identifier
    : ID { $$ = get_id($1); } 
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
	}
	print_syntaxError();
    }
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
}

void print_undeclaredF(){
    printf("\n|-----------------------------------------------|\n");
    printf("| Error found in line %d:%s\n", yylineno, savebuf);
    printf("| Undeclared function %s", saveID);
    printf("\n|-----------------------------------------------|\n\n");
    memset(&savebuf, '\0', 256);
    unDeclarF = 0;
    saveID = '\0';
}

void new_scope(){
    if(CUR_TABLE == NULL) {
	create_symbol(&CUR_TABLE);
	(CUR_TABLE->depth)++;
    }
    else{
    	struct Table* next;
    	create_symbol(&next);
    	CUR_TABLE->next = next;
    	next->prev = CUR_TABLE;
    	next->depth = CUR_TABLE->depth + 1;
    	CUR_TABLE = next;
    }
}

void delete_scope(){
    CUR_TABLE = CUR_TABLE->prev;
    free(CUR_TABLE->next);
}
