%{
/* C declarations */
#pragma warning( disable : 4786 )
#pragma warning( disable : 4996 )
#include <stdio.h>
#include "yaccFns.h"

#include "SimplePathWriter.h"
#include "CommandList.h"
#include "SimpleLength.h"
#include "SimpleCommand.h"

#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include "simpleGlobals.h"

void yyerror (char *s);
extern char *yytext;

extern char *szVersion;

%}
/* token declarations */
%token INTEGER
%token LEXERR
%token END_OF_FILE
%token COMMA
%token PEN_UP
%token PEN_DOWN
%token GOTO
%token UP
%token DOWN
%token LEFT
%token RIGHT
%token MOVE
%token ABS_UP
%token ABS_DOWN
%token ABS_LEFT
%token ABS_RIGHT
%token ABS_MOVE

%union 
{
    SimplePathWriter *SimplePathWriterPtr;
    CommandList *CommandListPtr;
    SimpleLength *LengthPtr;
    SimpleCommand *CommandPtr;

    long Long;
    double Double;
    char StrPtr[2*BUFSIZ];
}

%type <CommandListPtr> commandList
%type <CommandPtr> command
%type <LengthPtr> length

%type <StrPtr> INTEGER

%%

/* translation rules */
simplePathWriter
    : commandList END_OF_FILE
    {
        /* commandList */
        if ($1 != 0)
        {
            gResult.setCommands(*$1);
        }
    }
    |
    {
        /* empty */
    }
    ;

commandList
    : commandList command
    {
        /* commandList command */
        if ($1 != 0)
        {
            $$ = $1;
            if ($2 != 0)
            {
                $$->push_back(*$2);
                delete ($2);
            }
        }
    }
    | command
    {
        /* command */
        if ($1 != 0)
        {
            $$ = new CommandList;
            $$->push_back(*$1);
            delete ($1);
        }
    }
    ;

length
    : INTEGER
    {
        /* INTEGER */
        $$ = new SimpleLength((long) atol($1));
    }
    ;

command
    : PEN_UP
    {
        /* PEN_UP */
        $$ = new SimpleCommand(SPW_COMMAND_PEN_UP, SimpleLength());
    }
    | PEN_DOWN
    {
        /* PEN_DOWN */
        $$ = new SimpleCommand(SPW_COMMAND_PEN_DOWN, SimpleLength());
    }
    | MOVE length COMMA length
    {
        /* MOVE length length */
        std::vector<SimpleLength> vv;
        vv.push_back(*$2);
        vv.push_back(*$4);
        $$ = new SimpleCommand(SPW_COMMAND_MOVE, vv);
        delete $2;
        delete $4;
    }
    | UP length
    {
        /* UP length */
        $$ = new SimpleCommand(SPW_COMMAND_UP, *$2);
        delete $2;
    }
    | DOWN length
    {
        /* DOWN length */
        $$ = new SimpleCommand(SPW_COMMAND_DOWN, *$2);
        delete $2;
    }
    | LEFT length
    {
        /* LEFT length */
        $$ = new SimpleCommand(SPW_COMMAND_LEFT, *$2);
        delete $2;
    }
    | RIGHT length
    {
        /* RIGHT length */
        $$ = new SimpleCommand(SPW_COMMAND_RIGHT, *$2);
        delete $2;
    }
    | ABS_MOVE length COMMA length
    {
        /* ABS_MOVE length length */
        std::vector<SimpleLength> vv;
        vv.push_back(*$2);
        vv.push_back(*$4);
        $$ = new SimpleCommand(SPW_COMMAND_ABS_MOVE, vv);
        delete $2;
        delete $4;
    }
    | ABS_UP length
    {
        /* ABS_UP length */
        $$ = new SimpleCommand(SPW_COMMAND_ABS_UP, *$2);
        delete $2;
    }
    | ABS_DOWN length
    {
        /* ABS_DOWN length */
        $$ = new SimpleCommand(SPW_COMMAND_ABS_DOWN, *$2);
        delete $2;
    }
    | ABS_LEFT length
    {
        /* ABS_LEFT length */
        $$ = new SimpleCommand(SPW_COMMAND_ABS_LEFT, *$2);
        delete $2;
    }
    | ABS_RIGHT length
    {
        /* ABS_RIGHT length */
        $$ = new SimpleCommand(SPW_COMMAND_ABS_RIGHT, *$2);
        delete $2;
    }
    ;

%%
/* user code */

void yyerror (char *s)
{
   fprintf (stderr, "%s:\n  reading \"%s\" near line %d\n", s, yytext, yylineno);
}

/*
int main()
{
    int res = yyparse();
    printf("%d\n", res);
    if (res == 0)
    {
        printf("%s\n", gResult.ToString()->c_str());
    }

    return res;
}
*/

