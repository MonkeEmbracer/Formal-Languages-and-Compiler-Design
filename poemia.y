%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char* message);

extern int yylineno;
extern char* yytext;

void scanner_init(const char* source, const char* token_list);
int scanner_finish(void);

static int* productions = NULL;
static int production_count = 0;
static int production_capacity = 0;

static void use(int number) {
    if (production_count == production_capacity) {
        production_capacity = production_capacity == 0 ? 64 : production_capacity * 2;
        productions = realloc(productions, production_capacity * sizeof(int));
    }
    productions[production_count++] = number;
}
%}

%define parse.error verbose

%token TITLE NEWLINE BY AUTHOR
%token DECL_KW COMMA_SP TYPE_INT TYPE_QUEUE
%token ASSIGN_KW ASSIGN_MID
%token IDENTIFIER INT_CONST STRING_CONST
%token OP_PLUS OP_MINUS OP_TIMES OP_DIV LPAREN RPAREN
%token CMP_GT CMP_GE CMP_LT CMP_LE CMP_EQ CMP_NE
%token OR AND BOOL_TRUE BOOL_FALSE
%token IF_START IF_OPEN IF_CONT COMMA_NL IF_THEN ELSE_KW DOT QUOTE_END
%token REPEAT_START REPEAT_COLON REPEAT_END
%token WORM_PUSH_START WORM_PUSH_VERB WORM_PUSH_PREFIX WORM_PUSH_BY
%token WORM_POP_VERB WORM_POP_OBJ WORM_TOP WORM_CLEAR_START WORM_CLEAR_END WORM_EMPTY
%token READ_START READ_END
%token PRINT_KW PRINT_MESSAGE PRINT_OF

%start program

%%

program
    : TITLE NEWLINE BY AUTHOR NEWLINE stmt_list { use(1); }
    ;

stmt_list
    : stmt_list NEWLINE statement { use(2); }
    | statement { use(3); }
    ;

statement
    : decl_stmt { use(4); }
    | assign_stmt { use(5); }
    | if_stmt { use(6); }
    | repeat_stmt { use(7); }
    | print_stmt { use(8); }
    | read_stmt { use(9); }
    | push_stmt { use(10); }
    | pop_stmt { use(11); }
    | clear_stmt { use(12); }
    | %empty { use(13); }
    ;

decl_stmt
    : DECL_KW IDENTIFIER COMMA_SP type { use(14); }
    ;

type
    : TYPE_INT { use(15); }
    | TYPE_QUEUE { use(16); }
    ;

assign_stmt
    : ASSIGN_KW IDENTIFIER ASSIGN_MID expr { use(17); }
    ;

expr
    : expr add_op term { use(18); }
    | term { use(19); }
    ;

term
    : term mul_op factor { use(20); }
    | factor { use(21); }
    ;

factor
    : IDENTIFIER { use(22); }
    | INT_CONST { use(23); }
    | LPAREN expr RPAREN { use(24); }
    | WORM_TOP IDENTIFIER { use(25); }
    ;

add_op
    : OP_PLUS { use(26); }
    | OP_MINUS { use(27); }
    ;

mul_op
    : OP_TIMES { use(28); }
    | OP_DIV { use(29); }
    ;

if_stmt
    : IF_START IF_OPEN IF_CONT bool_expr COMMA_NL
      IF_THEN NEWLINE stmt_list DOT else_part QUOTE_END { use(30); }
    ;

else_part
    : NEWLINE ELSE_KW NEWLINE stmt_list DOT { use(31); }
    | %empty { use(32); }
    ;

bool_expr
    : bool_expr OR bool_term { use(33); }
    | bool_term { use(34); }
    ;

bool_term
    : bool_term AND bool_factor { use(35); }
    | bool_factor { use(36); }
    ;

bool_factor
    : comparison { use(37); }
    | LPAREN bool_expr RPAREN { use(38); }
    | BOOL_TRUE { use(39); }
    | BOOL_FALSE { use(40); }
    | IDENTIFIER WORM_EMPTY { use(41); }
    ;

comparison
    : expr cmp_op expr { use(42); }
    ;

cmp_op
    : CMP_GT { use(43); }
    | CMP_GE { use(44); }
    | CMP_LT { use(45); }
    | CMP_LE { use(46); }
    | CMP_EQ { use(47); }
    | CMP_NE { use(48); }
    ;

repeat_stmt
    : REPEAT_START REPEAT_COLON stmt_list NEWLINE REPEAT_END bool_expr { use(49); }
    ;

push_stmt
    : WORM_PUSH_START IDENTIFIER WORM_PUSH_VERB expr { use(50); }
    | WORM_PUSH_PREFIX expr WORM_PUSH_BY IDENTIFIER { use(51); }
    ;

pop_stmt
    : WORM_PUSH_START IDENTIFIER WORM_POP_VERB WORM_POP_OBJ { use(52); }
    ;

clear_stmt
    : WORM_CLEAR_START IDENTIFIER WORM_CLEAR_END { use(53); }
    ;

read_stmt
    : READ_START IDENTIFIER read_end { use(54); }
    ;

read_end
    : READ_END { use(55); }
    | %empty { use(56); }
    ;

print_stmt
    : PRINT_KW PRINT_MESSAGE STRING_CONST { use(57); }
    | PRINT_KW PRINT_OF printable { use(58); }
    ;

printable
    : expr { use(59); }
    | bool_expr { use(60); }
    ;

%%

void yyerror(const char* message) {
    printf("SYNTAX ERROR line %d near '%s': %s\n", yylineno, yytext, message);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <source file> [token list]\n", argv[0]);
        return 1;
    }

    scanner_init(argv[1], argc > 2 ? argv[2] : "tokens.txt");
    int parse_result = yyparse();
    int lexical_errors = scanner_finish();

    if (parse_result == 0 && lexical_errors == 0) {
        printf("Program is syntactically correct\n");

        printf("Reductions (bottom-up order):\n");
        for (int i = 0; i < production_count; i++) {
            printf("%d ", productions[i]);
        }
        printf("\n");

        printf("Rightmost derivation:\n");
        for (int i = production_count - 1; i >= 0; i--) {
            printf("%d ", productions[i]);
        }
        printf("\n");
    }
    else {
        if (lexical_errors > 0) {
            printf("%d lexical error(s)\n", lexical_errors);
        }
        if (parse_result != 0) {
            printf("Parsing failed\n");
        }
    }

    free(productions);
    return parse_result != 0 || lexical_errors != 0;
}