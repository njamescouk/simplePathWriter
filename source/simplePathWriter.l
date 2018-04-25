%{
/* C definitions */
#pragma warning( disable : 4786 )
#pragma warning( disable : 4996 )

#include "SimpleCommand.h"
#include "SimplePathWriter.h"
#include "SimpleLength.h"
#include <cstring>
#include "y.tab.h"
    /*
#include <stdlib.h>
#include <io.h>
#include <vector>
#include <string>
#include <map>
#include "simpleGlobals.h"

#include "yaccFns.h"
*/
#define YY_USE_PROTOS
extern int yydebug;

char *getState();
int seenEOF = 0;

%}

%option yylineno

/* regular definitions */
space [ \t]
ws    {space}+
identifier [_a-zA-Z]+
digits [0-9]+
number -?{digits}\.{digits}

%%
"pu"            {
                    #ifdef LEX_MSG
                    fprintf (stderr, "PEN_UP\n");
                    #endif
                    return PEN_UP;
                }

"pd"            {
                    #ifdef LEX_MSG
                    fprintf (stderr, "PEN_DOWN\n");
                    #endif
                    return PEN_DOWN;
                }

"m"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "MOVE\n");
                    #endif
                    return MOVE;
                }

"u"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "UP\n");
                    #endif
                    return UP;
                }

"d"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "DOWN\n");
                    #endif
                    return DOWN;
                }

"l"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "LEFT\n");
                    #endif
                    return LEFT;
                }

"r"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "RIGHT\n");
                    #endif
                    return RIGHT;
                }

"M"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "ABS_MOVE\n");
                    #endif
                    return ABS_MOVE;
                }

"U"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "ABS_UP\n");
                    #endif
                    return ABS_UP;
                }

"D"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "ABS_DOWN\n");
                    #endif
                    return ABS_DOWN;
                }

"L"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "ABS_LEFT\n");
                    #endif
                    return ABS_LEFT;
                }

"R"             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "ABS_RIGHT\n");
                    #endif
                    return ABS_RIGHT;
                }

#.*            {
                    #ifdef LEX_MSG
                    fprintf (stderr, "COMMENT\n");
                    #endif
                    // return COMMENT;
                }

-?{digits}      {
                    #ifdef LEX_MSG
                    fprintf (stderr, "INTEGER %s\n", yytext);
                    #endif
                    BEGIN (INITIAL);
                    strcpy(yylval.StrPtr, yytext);
                    return INTEGER;
                }

","             {
                    #ifdef LEX_MSG
                    fprintf (stderr, "COMMA\n");
                    #endif
                    return COMMA;
                }

\n              {
                }

{ws}            {}

.               {
                    return LEXERR;
                }

<<EOF>>         {
                    /* we fake this to get round the no newline 
                    at end of file problem */
                    if (seenEOF == 0)
                    {
                        seenEOF = 1;
                        return END_OF_FILE;
                    }
                    else
                    {
                        yyterminate();
                    }
                }


%%
/* user code */

int yywrap (void)
{
   return 1;
}   

#ifdef LEX_DEBUG

int main (int argc, char *argv[])
{
    FILE *fp = stdin;

    if (argc > 0)
    {
        fp = fopen(argv[1], "rt");
    }

    fprintf(stderr, "lex_debug\n");
    yyin = fp;

    while (yylex())
       ;

    if (fp != stdin)
        fclose(fp);
}

char *getState()
{
    char *res = 0;

    switch (YY_START)
    {
        case INITIAL:
        res = "INITIAL";
        break;
        default:
        res = "ERROR";
        break;
    }

    return res;
}

#endif /* LEX_DEBUG */
