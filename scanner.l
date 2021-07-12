%{
    #include <stdio.h>
    #include <string.h>
    #include "parser.tab.h"

    int line = 1;
    int is_tab(char c[4]);
    int count_newlines(char* token);
    
%}
%x c_comment
eol [\n]+
whitespace [ \t\n]*

alpha [a-zA-Z]
digit [0-9]
under [_]

start_au ({alpha}|{under})+({alpha}|{under}|{digit})*
anu {alpha}|{digit}|{under} 

add "+"
sub "-"
mul "*"
div "/"
pow "^"

gt ">"
lt "<"
neq "!="
is_eq "=="
comp_operator {gt}|{lt}|{neq}|{is_eq}

and "AND"
or "OR"
log_operator {and}|{or}

str \".*\"
true "TRUE"
false "FALSE"
bool {true}|{false}

comment {whitespace}?"%".*{eol}?

%%
"PROGRAM" {return PROG;}
"RETURN" {return RET;}
"FUNCTION" {return FUNC;}
"END_FUNCTION" {return ENDFUNC;}
"STARTMAIN" {return SMAIN;}
"ENDMAIN" {return EMAIN;}
"CHAR" {strcpy(yylval.str, yytext); return CHAR;}
"INTEGER" {strcpy(yylval.str, yytext); return INT;}
"VARS" {return VARS;}
"WHILE" {return WHILE;}
"ENDWHILE" {return EWHILE;}
"FOR" {return FOR;}
"TO" {return TO;}
"STEP" {return STEP;}
"ENDFOR" {return EFOR;}
"IF" {return IF;}
"THEN" {return THEN;}
"ELSEIF" {return ELSEIF;}
"ELSE" {return ELSE;}
"ENDIF" {return ENDIF;}
"SWITCH" {return SWITCH;}
"CASE" {return CASE;}
"DEFAULT" {return DEFAULT;}
"ENDSWITCH" {return ESWITCH;}
"PRINT" {return PRINT;}
"BREAK" {return BREAK;}
"STRUCT" {return STRUCT;}
"ENDSTRUCT" {return ESTRUCT;}
"TYPEDEF" {return TYPEDEF;}

"/*"   {BEGIN(c_comment);}
<c_comment>"*/"         {BEGIN(0);}
<c_comment>(\n)+|.      {line += count_newlines(yytext);}

{add} {return ADD;}
{sub} {return SUB;}
{mul} {return MUL;}
{div} {return DIV;}
{pow} {return POW;}

{comp_operator} {return COMP_OPER;}
{log_operator} {return LOG_OPER;}

":" {return COLON;}
":=" {return COLON_EQ;}
"," {return COMMA;}
";" {return SEMIC;}
"=" {return EQS;}
{comment}+ {line += count_newlines(yytext); return COMMENT;} /*the ? at the end of the regex is there in order to 
                                allow flex scann EOF even though there is a comment on the last line.
                                (another solution would be for each code that contains a comment at the end of the line,
                                have an empty line after the comment)
*/

{eol} {line += strlen(yytext); return EOL;} //If eof is expected, you are allowed to \n as many times as you want
"(" {return OP;}
")" {return CP;}
"[" {return OB;}
"]" {return CB;}
[ ] /*Ignore Whitespace*/

{bool} {return BOOL;}
{alpha}+ {strcpy(yylval.str, yytext); return ALPHA;}
{digit}+ {yylval.ival = atoi(yytext); return POS_NUM;}
{under}+ {strcpy(yylval.str, yytext); return UNDER;}
{start_au}+ {strcpy(yylval.str, yytext); return SAU;} //Starting with an Alpha or Under
{anu}+ {return ANU;} //Alpha Number Under
{str} {return STR;}
. { printf("Unused character: %c\n", *yytext); }


%%

int count_newlines(char* token){
    int cnt = 0, i;
    for(i=0;i<strlen(token);i++){
        if(token[i] == '\n'){
            cnt++;
        }
    }
    //printf("Counted %d after comment newlines\n",cnt);
    //printf("i has a value of: %d\n",i);
    return cnt;
}

/*//IF YOU NEED TO CHANGE THE BEHAVIOUR OF HOW A WHITESPACE IS TREATED THIS FUNCTION MUST ALSO CHANGE (and the flex rule)!!!
//tab will match any space that is at the beggining of a line
//if there are 4 spaces in a row (that is considered to be a tab)
//return 1 (so flex returns the TAB token)
//if there are not enough spaces, then return 0, which will lead flex ignoring them
//TODO: There should be a better way of doing this! FIX IT
int is_tab(char c[4]){
    int i, counter = 0;
    for (i = 0 ; i < 4; i++){
        if(c[i] == ' '){
            counter++;
        }
    }
    if(counter == 4){
        return 1;
    }
    return 0;
}

if you uncomment this, make sure you add the line below, before the whitespace ignore line
^[ \t]+ { if(is_tab(yytext)){ return TAB; } }*/