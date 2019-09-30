/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>

	int lineNum = 0;
	int commentLine = 0;
	int checkNull = 1;
%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+
floatnum {digit}*+"."+{digit}*
%x COMMENT
%x CONTENT

/* Rules section */
%%
"+" 	{ printf("%s \t ADD\n", yytext); }
"-"	{ printf("%s \t SUB\n", yytext); }
"*"     { printf("%s \t MUL\n", yytext); }
"/"     { printf("%s \t DIV\n", yytext); }
"%"     { printf("%s \t MOD\n", yytext); }
"++"     { printf("%s \t INC\n", yytext); }
"--"     { printf("%s \t DEC\n", yytext); }
">"     { printf("%s \t MT\n", yytext); }
"<"     { printf("%s \t LT\n", yytext); }
">="     { printf("%s \t MTE\n", yytext); }
"<="     { printf("%s \t LTE\n", yytext); }
"=="     { printf("%s \t EQ\n", yytext); }
"!="     { printf("%s \t NE\n", yytext); }
"["     { printf("%s \t LSB\n", yytext); }
"]"     { printf("%s \t RSB\n", yytext); }
","     { printf("%s \t COMMA\n", yytext); }
";"     { printf("%s \t SEMICOLON\n", yytext); }
"print"	{ printf("%s \t PRINT\n", yytext); }
"if"     { printf("%s \t IF\n", yytext); }
"else"     { printf("%s \t ELSE\n", yytext); }
"for"     { printf("%s \t FOR\n", yytext); }
"while"     { printf("%s \t WHILE\n", yytext); }
"string"     { printf("%s \t STRING\n", yytext); }
"int"     { printf("%s \t INT\n", yytext); }
"float"     { printf("%s \t FLOAT\n", yytext); }
"="     { printf("%s \t ASGN\n", yytext); }
"+="     { printf("%s \t ADDASGN\n", yytext); }
"-="     { printf("%s \t SUBASGN\n", yytext); }
"*="     { printf("%s \t MULASGN\n", yytext); }
"/="     { printf("%s \t DIVASGN\n", yytext); }
"%="     { printf("%s \t MODASGN\n", yytext); }
"&&"     { printf("%s \t AND\n", yytext); }
"||"     { printf("%s \t OR\n", yytext); }
"!"     { printf("%s \t NOT\n", yytext); }
"("     { printf("%s \t LB\n", yytext); }
")"     { printf("%s \t RB\n", yytext); }
"{"     { printf("%s \t LCB\n", yytext); }
"}"     { printf("%s \t RCB\n", yytext); }
"void"     { printf("%s \t VOID\n", yytext); }
"bool"     { printf("%s \t BOOL\n", yytext); }
"true"     { printf("%s \t TRUE\n", yytext); }
"false"     { printf("%s \t FALSE\n", yytext); }
"return"     { printf("%s \t RET\n", yytext); }
"continue"     { printf("%s \t CONT\n", yytext); }
"break"     { printf("%s \t BREAK\n", yytext); }

{number}    { printf("%s \t I_CONST\n", yytext); }
{floatnum}    { printf("%s \t F_CONST\n", yytext); }
{id}	{ printf("%s \t ID\n", yytext); }
\n	{++lineNum;}
[ \t]	{;}


"//".*	{printf("%s \t C++ Comment\n", yytext); ++commentLine;}

"/*"	{printf("/*"); BEGIN COMMENT;}
<COMMENT>\n	{ printf("%s", yytext); ++lineNum; ++commentLine;}
<COMMENT>"*/"	{ printf("%s \t C Comment\n", yytext); ++commentLine; BEGIN INITIAL;}

["].*"\""?.*["] {printf("%c \t QUOTA\n", yytext[0]);
		if(yyleng>2){
			for(int i=1;i<yyleng-1;i++){
				printf("%c", yytext[i]);
			}printf(" \t STR_CONST\n");}
		printf("%c \t QUOTA\n", yytext[yyleng-1]);}


%%

/*	C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();
	printf("\nParse over, the line number is %d.\n\n", lineNum);
	printf("comment: %d lines\n\n", commentLine);

	return 0;
}
