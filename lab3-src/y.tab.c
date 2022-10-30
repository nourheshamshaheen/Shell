/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 18 "shell.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union	{
		char   *string_val;
	} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 23 "shell.y"
extern "C" 
{
	int yylex();
	void yyerror (char const *s);
}
#define yylex yylex
#include <stdio.h>
#include "command.h"
#include <signal.h>
#include <glob.h>
#include <string.h>
#line 44 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define WORD 257
#define NOTOKEN 258
#define GREAT 259
#define NEWLINE 260
#define LESS 261
#define AMPS 262
#define APPEND 263
#define PIPE 264
#define GREATAMPS 265
#define APPENDAMPS 266
#define CHAR 267
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    3,    3,    3,    4,    4,    6,
    8,    8,    9,    9,    9,    7,    5,    5,    5,   10,
   10,   10,   10,   10,   10,   10,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    1,    3,    1,    2,    3,    1,    2,
    2,    0,    1,    1,    0,    1,    2,    1,    0,    2,
    2,    2,    1,    2,    2,    0,
};
static const YYINT yydefred[] = {                         0,
    0,   16,    6,    0,    0,    2,    4,    0,    9,   12,
    7,    3,    0,    0,   23,    0,    0,    0,    0,    0,
   18,    0,   20,   22,   21,    8,   25,   24,    5,   17,
   13,   14,   11,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,   20,    9,   10,   22,   33,   21,
};
static const YYINT yysindex[] = {                      -231,
 -238,    0,    0,    0, -231,    0,    0, -250,    0,    0,
    0,    0, -230, -229,    0, -227, -226, -225, -224, -242,
    0, -257,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,   34,    0,    0, -223,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -258,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   30,    0,    0,    0,   19,    0,    0,    0,   18,
};
#define YYTABLESIZE 38
static const YYINT yytable[] = {                         31,
   10,   10,   10,   10,   10,   10,   10,   10,   13,   32,
   14,   15,   16,   17,   18,   19,   13,   29,   14,   15,
   16,   11,   18,   19,    1,    2,   23,   24,    3,   25,
    2,   27,   28,    1,   12,   26,   19,   30,
};
static const YYINT yycheck[] = {                        257,
  259,  260,  261,  262,  263,  264,  265,  266,  259,  267,
  261,  262,  263,  264,  265,  266,  259,  260,  261,  262,
  263,  260,  265,  266,  256,  257,  257,  257,  260,  257,
  257,  257,  257,    0,    5,   17,  260,   20,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#define YYUNDFTOKEN 280
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"WORD","NOTOKEN","GREAT",
"NEWLINE","LESS","AMPS","APPEND","PIPE","GREATAMPS","APPENDAMPS","CHAR",0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : goal",
"goal : commands",
"commands : command",
"commands : commands command",
"command : simple_command",
"simple_command : piped_command iomodifier_opt_list NEWLINE",
"simple_command : NEWLINE",
"simple_command : error NEWLINE",
"piped_command : piped_command PIPE command_and_args",
"piped_command : command_and_args",
"command_and_args : command_word arg_list",
"arg_list : arg_list argument",
"arg_list :",
"argument : WORD",
"argument : CHAR",
"argument :",
"command_word : WORD",
"iomodifier_opt_list : iomodifier_opt_list iomodifier_opt",
"iomodifier_opt_list : iomodifier_opt",
"iomodifier_opt_list :",
"iomodifier_opt : GREAT WORD",
"iomodifier_opt : APPEND WORD",
"iomodifier_opt : LESS WORD",
"iomodifier_opt : AMPS",
"iomodifier_opt : APPENDAMPS WORD",
"iomodifier_opt : GREATAMPS WORD",
"iomodifier_opt :",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 197 "shell.y"

void
yyerror(const char * s)
{
	fprintf(stderr,"%s", s);
}

#if 0
main()
{
	yyparse();
}
#endif
#line 236 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
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
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
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

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 5:
#line 51 "shell.y"
	{
		printf("   Yacc: Execute command\n");
		Command::_currentCommand.execute();
	}
break;
case 7:
#line 60 "shell.y"
	{ yyerrok; }
break;
case 10:
#line 69 "shell.y"
	{
		Command::_currentCommand.insertSimpleCommand( Command::_currentSimpleCommand );
	}
break;
case 13:
#line 86 "shell.y"
	{
		/* Nour's code*/
		/* char * str = $1;*/
		/* int i= 0;*/
		/* while(str[i])*/
		/* {*/
		/* 	if(strcmp(str[i],"*")==0)*/
		/* 	{*/
		/* 		glob_t* pglob; */
		/* 		glob_t glob_results;*/
		/* 		char **p;*/
		/* 		printf(glob("*",GLOB_NOCHECK,0,&glob_results));*/
		/* 		// p_glob is a struct*/
		/* 		// for each matching pattern, insert argument*/
		/* 		//Command::_currentSimpleCommand->insertArgument();*/
		/* 	}*/
		/* 	else if(strcmp(str[i],"?")==0)*/

		/* 	{*/
				
		/* 		// for each matching pattern, insert argument*/
		/* 			//Command::_currentSimpleCommand->insertArgument();*/
		/* 	}*/
		/* 	i++;*/
		/* }*/
		/* Lara's code*/
		char * str = (char *) malloc( sizeof(yystack.l_mark[0].string_val) * sizeof( char ) );
		str = yystack.l_mark[0].string_val;
		/* printf("	This is str %s\n",str);*/
		if(strstr(str,"*")!=NULL){
			printf("\t******************\n\tFOUND A WILDCARD [*]\n\t******************\n");
		}
		else if(strstr(str,"?")!=NULL){
			printf("\t******************\n\tFOUND A WILDCARD [?]\n\t******************\n");
		}
           printf("   Yacc: insert argument \"%s\"\n", yystack.l_mark[0].string_val);
	       Command::_currentSimpleCommand->insertArgument( yystack.l_mark[0].string_val );\
	}
break;
case 14:
#line 124 "shell.y"
	{
		/* char* str = "*";*/
		/* // printf("	This is str %s\n",str);*/
		/* if(strstr(str,"*")!=NULL){*/
		/* 	printf("\t******************\n\tFOUND A WILDCARD [*]\n\t******************\n");*/
		/* }*/
		/* else if(strstr(str,"?")!=NULL){*/
		/* 	printf("\t******************\n\tFOUND A WILDCARD [?]\n\t******************\n");*/
		/* }*/
           printf("   Yacc: insert argument \"%s\"\n", "*");
	       /*Command::_currentSimpleCommand->insertArgument(NULL);\*/
	}
break;
case 16:
#line 140 "shell.y"
	{
		/* Here, we implement our exit function*/
			if (strcmp(yystack.l_mark[0].string_val, "exit") == 0) {
				printf("You are now exiting Nour and Lara's shell. Bye!\n");
				exit(0);	
			}
			printf("   Yacc: insert command \"%s\"\n", yystack.l_mark[0].string_val);
	       
	       Command::_currentSimpleCommand = new SimpleCommand();
	       Command::_currentSimpleCommand->insertArgument( yystack.l_mark[0].string_val );
	}
break;
case 20:
#line 161 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[0].string_val;
		Command::_currentCommand._appendFlag = 0;

	}
break;
case 21:
#line 167 "shell.y"
	{
		printf("   Yacc: insert output \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._outFile = yystack.l_mark[0].string_val;
		Command::_currentCommand._appendFlag = 1;
	}
break;
case 22:
#line 172 "shell.y"
	{
		printf("   Yacc: insert input \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._inputFile = yystack.l_mark[0].string_val;

	}
break;
case 23:
#line 177 "shell.y"
	{
		printf("   Yacc: running in background.\n");
		Command::_currentCommand._background = true;

	}
break;
case 24:
#line 182 "shell.y"
	{
		printf("   Yacc: insert error \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._errFile = yystack.l_mark[0].string_val;
		Command::_currentCommand._appendFlagErr = 1;
	}
break;
case 25:
#line 187 "shell.y"
	{
		printf("   Yacc: insert error \"%s\"\n", yystack.l_mark[0].string_val);
		Command::_currentCommand._errFile = yystack.l_mark[0].string_val;

	}
break;
#line 574 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
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
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
