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
extern YYSTYPE yylval;
