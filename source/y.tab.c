#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
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

typedef union 
{
    SimplePathWriter *SimplePathWriterPtr;
    CommandList *CommandListPtr;
    SimpleLength *LengthPtr;
    SimpleCommand *CommandPtr;

    long Long;
    double Double;
    char StrPtr[2*BUFSIZ];
} YYSTYPE;
#define INTEGER 257
#define LEXERR 258
#define END_OF_FILE 259
#define COMMA 260
#define PEN_UP 261
#define PEN_DOWN 262
#define GOTO 263
#define UP 264
#define DOWN 265
#define LEFT 266
#define RIGHT 267
#define MOVE 268
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    3,    2,    2,    2,    2,    2,
    2,    2,
};
short yylen[] = {                                         2,
    2,    0,    2,    1,    1,    1,    1,    4,    2,    2,
    2,    2,
};
short yydefred[] = {                                      0,
    6,    7,    0,    0,    0,    0,    0,    0,    0,    4,
    5,    9,   10,   11,   12,    0,    1,    3,    0,    8,
};
short yydgoto[] = {                                       8,
    9,   10,   12,
};
short yysindex[] = {                                   -245,
    0,    0, -252, -252, -252, -252, -252,    0, -255,    0,
    0,    0,    0,    0,    0, -246,    0,    0, -252,    0,
};
short yyrindex[] = {                                      8,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    9,   -4,
};
#define YYTABLESIZE 23
short yytable[] = {                                      13,
   14,   15,   16,   17,   11,    1,    2,    2,    3,    4,
    5,    6,    7,   19,   20,    1,    2,   18,    3,    4,
    5,    6,    7,
};
short yycheck[] = {                                       4,
    5,    6,    7,  259,  257,  261,  262,    0,  264,  265,
  266,  267,  268,  260,   19,  261,  262,    9,  264,  265,
  266,  267,  268,
};
#define YYFINAL 8
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 268
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","LEXERR","END_OF_FILE",
"COMMA","PEN_UP","PEN_DOWN","GOTO","UP","DOWN","LEFT","RIGHT","MOVE",
};
char *yyrule[] = {
"$accept : simplePathWriter",
"simplePathWriter : commandList END_OF_FILE",
"simplePathWriter :",
"commandList : commandList command",
"commandList : command",
"length : INTEGER",
"command : PEN_UP",
"command : PEN_DOWN",
"command : MOVE length COMMA length",
"command : UP length",
"command : DOWN length",
"command : LEFT length",
"command : RIGHT length",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
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

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
{
        /* commandList */
        if (yyvsp[-1].CommandListPtr != 0)
        {
            gResult.setCommands(*yyvsp[-1].CommandListPtr);
        }
    }
break;
case 2:
{
        /* empty */
    }
break;
case 3:
{
        /* commandList command */
        if (yyvsp[-1].CommandListPtr != 0)
        {
            yyval.CommandListPtr = yyvsp[-1].CommandListPtr;
            if (yyvsp[0].CommandPtr != 0)
            {
                yyval.CommandListPtr->push_back(*yyvsp[0].CommandPtr);
                delete (yyvsp[0].CommandPtr);
            }
        }
    }
break;
case 4:
{
        /* command */
        if (yyvsp[0].CommandPtr != 0)
        {
            yyval.CommandListPtr = new CommandList;
            yyval.CommandListPtr->push_back(*yyvsp[0].CommandPtr);
            delete (yyvsp[0].CommandPtr);
        }
    }
break;
case 5:
{
        /* INTEGER */
        yyval.LengthPtr = new SimpleLength((long) atol(yyvsp[0].StrPtr));
    }
break;
case 6:
{
        /* PEN_UP */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_PEN_UP, SimpleLength());
    }
break;
case 7:
{
        /* PEN_DOWN */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_PEN_DOWN, SimpleLength());
    }
break;
case 8:
{
        /* MOVE length length */
        std::vector<SimpleLength> vv;
        vv.push_back(*yyvsp[-2].LengthPtr);
        vv.push_back(*yyvsp[0].LengthPtr);
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_MOVE, vv);
        delete yyvsp[-2].LengthPtr;
        delete yyvsp[0].LengthPtr;
    }
break;
case 9:
{
        /* UP length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_UP, *yyvsp[0].LengthPtr);
        delete yyvsp[0].LengthPtr;
    }
break;
case 10:
{
        /* DOWN length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_DOWN, *yyvsp[0].LengthPtr);
        delete yyvsp[0].LengthPtr;
    }
break;
case 11:
{
        /* LEFT length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_LEFT, *yyvsp[0].LengthPtr);
        delete yyvsp[0].LengthPtr;
    }
break;
case 12:
{
        /* RIGHT length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_RIGHT, *yyvsp[0].LengthPtr);
        delete yyvsp[0].LengthPtr;
    }
break;
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
