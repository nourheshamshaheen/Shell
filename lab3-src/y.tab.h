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
extern YYSTYPE yylval;
