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
#define ABS_UP 269
#define ABS_DOWN 270
#define ABS_LEFT 271
#define ABS_RIGHT 272
#define ABS_MOVE 273
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    1,    1,    3,    2,    2,    2,    2,    2,
    2,    2,    2,    2,    2,    2,    2,
};
short yylen[] = {                                         2,
    2,    0,    2,    1,    1,    1,    1,    4,    2,    2,
    2,    2,    4,    2,    2,    2,    2,
};
short yydefred[] = {                                      0,
    6,    7,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    4,    5,    9,   10,   11,   12,
    0,   14,   15,   16,   17,    0,    1,    3,    0,    0,
    8,   13,
};
short yydgoto[] = {                                      13,
   14,   15,   17,
};
short yysindex[] = {                                   -234,
    0,    0, -247, -247, -247, -247, -247, -247, -247, -247,
 -247, -247,    0, -250,    0,    0,    0,    0,    0,    0,
 -236,    0,    0,    0,    0, -231,    0,    0, -247, -247,
    0,    0,
};
short yyrindex[] = {                                     13,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
    0,   26,   -4,
};
#define YYTABLESIZE 40
short yytable[] = {                                      18,
   19,   20,   21,   22,   23,   24,   25,   26,   27,   16,
    1,    2,    2,    3,    4,    5,    6,    7,    8,    9,
   10,   11,   12,   29,   31,   32,    1,    2,   30,    3,
    4,    5,    6,    7,    8,    9,   10,   11,   12,   28,
};
short yycheck[] = {                                       4,
    5,    6,    7,    8,    9,   10,   11,   12,  259,  257,
  261,  262,    0,  264,  265,  266,  267,  268,  269,  270,
  271,  272,  273,  260,   29,   30,  261,  262,  260,  264,
  265,  266,  267,  268,  269,  270,  271,  272,  273,   14,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 273
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTEGER","LEXERR","END_OF_FILE",
"COMMA","PEN_UP","PEN_DOWN","GOTO","UP","DOWN","LEFT","RIGHT","MOVE","ABS_UP",
"ABS_DOWN","ABS_LEFT","ABS_RIGHT","ABS_MOVE",
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
"command : ABS_MOVE length COMMA length",
"command : ABS_UP length",
"command : ABS_DOWN length",
"command : ABS_LEFT length",
"command : ABS_RIGHT length",
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
case 13:
{
        /* ABS_MOVE length length */
        std::vector<SimpleLength> vv;
        vv.push_back(*yyvsp[-2].LengthPtr);
        vv.push_back(*yyvsp[0].LengthPtr);
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_ABS_MOVE, vv);
        delete yyvsp[-2].LengthPtr;
        delete yyvsp[0].LengthPtr;
    }
break;
case 14:
{
        /* ABS_UP length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_ABS_UP, *yyvsp[0].LengthPtr);
        delete yyvsp[0].LengthPtr;
    }
break;
case 15:
{
        /* ABS_DOWN length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_ABS_DOWN, *yyvsp[0].LengthPtr);
        delete yyvsp[0].LengthPtr;
    }
break;
case 16:
{
        /* ABS_LEFT length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_ABS_LEFT, *yyvsp[0].LengthPtr);
        delete yyvsp[0].LengthPtr;
    }
break;
case 17:
{
        /* ABS_RIGHT length */
        yyval.CommandPtr = new SimpleCommand(SPW_COMMAND_ABS_RIGHT, *yyvsp[0].LengthPtr);
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
