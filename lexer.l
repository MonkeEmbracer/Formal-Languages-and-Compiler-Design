%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "st.h"

#define MAX_TOKENS 128

char* token_names[MAX_TOKENS];
int token_count = 0;
FILE* pif = NULL;
int error_count = 0;

void emit(const char* name);
void lex_error(int line, const char* message, const char* text);
%}

%option noyywrap yylineno

%x TITLE AUTHOR AUTHOR_NAME

TITLE_TEXT [a-zA-Z][a-zA-Z0-9 .;,!?-]*
AUTHOR_TEXT [a-zA-Z][a-zA-Z0-9 .,_-]*
MSG_TEXT [a-zA-Z0-9 .;,!?-]*

IDWORD [A-Z][a-zA-Z]*
ID {IDWORD}(" "{IDWORD})*
INT 0|-?[1-9][0-9]*

%%

<TITLE>{TITLE_TEXT} { emit("TITLE"); }
<TITLE>\n { emit("NEWLINE"); BEGIN(AUTHOR); }

<AUTHOR>"by " { emit("BY"); BEGIN(AUTHOR_NAME); }
<AUTHOR>\n { lex_error(yylineno - 1, "expected 'by <author>'", NULL); BEGIN(INITIAL); }
<AUTHOR_NAME>{AUTHOR_TEXT} { emit("AUTHOR"); }
<AUTHOR_NAME>\n { emit("NEWLINE"); BEGIN(INITIAL); }

"There once was "|"Let there be "|"There existed "|"Once upon a time, there was "|"There also was "|"There was "|"Unbeknownst to man, there also was "|"There shall be " {
    emit("DECL_KW");
}
", " { emit("COMMA_SP"); }
"a math wizard" { emit("TYPE_INT"); }
"an eternal worm" { emit("TYPE_QUEUE"); }

"Should "/{ID} { emit("IF_CONT"); }
"If "/{ID} { emit("IF_CONT"); }

{ID} { emit("IDENTIFIER"); }
{INT} { emit("INT_CONST"); }
-?0[0-9]+|-0 { lex_error(yylineno, "invalid integer", yytext); }
\n { emit("NEWLINE"); }

"Then, "|"One day, "|"Suddenly, "|"Surprisingly, "|"Shockingly, "|"As foretold, "|"Obviously, "|"To your dismay, "|"To their dismay, "|"Repeatedly, "|"Out of the blue, " {
    emit("ASSIGN_KW");
}
" became "|" turned into "|" turned "|" was reborn as "|" will turn to "|" turns into "|" becomes "|" shall become "|" shapeshifts into "|" shapeshifted into "|" shall shapeshift into "|" shall turn into "|" is reborn as " {
    emit("ASSIGN_MID");
}

" plus "|" added to "|" combined with "|" compounded with "|" merged with "|" along with " {
    emit("OP_PLUS");
}
" minus "|" without "|" subtracting " {
    emit("OP_MINUS");
}
" multiplied by "|" multiplied with "|" times " {
    emit("OP_TIMES");
}
" divided by "|" shared between "|" given evenly to "|" split in " {
    emit("OP_DIV");
}
"(" { emit("LPAREN"); }
")" { emit("RPAREN"); }

" is greater than "|" trumps "|" shall be greater than "|" surpasses "|" dwarfs "|" dwarfed "|" surpassed "|" was greater than "|" dwarf "|" be greater than " {
    emit("CMP_GT");
}
" is greater or equal to "|" shall be at least "|" is at least "|" was at least "|" be at least " {
    emit("CMP_GE");
}
" is smaller than "|" is trumped by "|" is dwarfed by "|" shall be smaller than "|" was dwarfed by "|" was smaller than "|" be dwarfed by " {
    emit("CMP_LT");
}
" is smaller or equal to "|" shall be smaller or equal to "|" is at most "|" shall be at most "|" was at most "|" be at most " {
    emit("CMP_LE");
}
" is exactly "|" is precisely "|" is "|" mirrors "|" shall mirror "|" mirrored "|" was "|" be "|" was exactly "|" be exactly " {
    emit("CMP_EQ");
}
" is different from "|" differs from "|" shall be different from "|" was different from "|" differ from " {
    emit("CMP_NE");
}
" or "  { emit("OR"); }
" and " { emit("AND"); }
"grass is green" { emit("BOOL_TRUE"); }
"black is white" { emit("BOOL_FALSE"); }

"The eternal worm " { emit("WORM_PUSH_START"); }
" has devoured "|" devours "|" shall devour " {
    emit("WORM_PUSH_VERB");
}
"Our dear " { emit("WORM_PUSH_PREFIX"); }
" has been devoured by " { emit("WORM_PUSH_BY"); }
" has released "|" releases "|" shall release "|" released " {
    emit("WORM_POP_VERB");
}
"its earliest victim" { emit("WORM_POP_OBJ"); }
"the earliest victim of " { emit("WORM_TOP"); }
"Rejoice! "|"With a swift blow, "|"Blood of an eternal worm shall spill, " {
    emit("WORM_CLEAR_START");
}
" has been slain!"|" is slain"|", by name" {
    emit("WORM_CLEAR_END");
}
" is hungry"|" is famished" {
    emit("WORM_EMPTY");
}

"The gods shall communicate the role "|"A voice is heard from above, speaking of the reborn "|"Struck by divine inspiration, "|"The gods have bestowed a new identity upon "|"A song only their ears can hear has inspired "|"Dissatisfied with their existence, " {
    emit("READ_START");
}
" shall take"|" is ready to take on a newfound identity"|" to find a new identity"|" has decided to look for their purpose in the stars" {
    emit("READ_END");
}
"An enamoured poet writes down his thoughts"|"Channels across the globe broadcast breaking news"|"Words shall be written down for generations to come"|"A pale spectator hurried to town, to preach what he had found" {
    emit("PRINT_KW");
}
", of " { emit("PRINT_OF"); }
": " { emit("PRINT_MESSAGE"); }

\"{MSG_TEXT}\" { emit("STRING_CONST"); }
\"[^"\n]* { lex_error(yylineno, "unterminated string", NULL); }

"They encountered a witch, who advised them carefully"|"They passed by a drunken sailor, who loudly shouted at them"|"Hearing the distant song of a bard, they approached to listen closely"|"You shall encounter an old lady, who will advise you the following"|"An old lady approaches, teary eyed, warning our heroes" {
    emit("IF_START");
}
":\n'" { emit("IF_OPEN"); }
"Beware travellers, for if "|"Tread carefully, for if "|"Listen here, bastards! If "|"I curse you, peasants! If "|"So says the old song, that if "|"The townsfolk have been saying that "|"I heard that if " {
    emit("IF_CONT");
}
",\n" { emit("COMMA_NL"); }
"Then the gods shall decree that"|"The legend says that"|"It is said that"|"I shall make sure that" {
    emit("IF_THEN");
}
"Should the prophecy not be fulfilled,"|"Otherwise,"|"Should lady luck not be on your side,"|"Should the odds be in your favour," {
    emit("ELSE_KW");
}
"." { emit("DOT"); }
"'" { emit("QUOTE_END"); }

"Our heroes found themselves waking up every day to experience the following scenario exactly"|"They realised they had been dreaming the same strange dream every night"|"A curse has been cast upon our heroes, rendering them to repeat the following, mindlessly" {
    emit("REPEAT_START");
}
":\n" { emit("REPEAT_COLON"); }
"But they realised they wouldn't go back to normal until "|"But they realised the condition to break the spell was that "|"But fortunately, they were able to break the curse under the condition that " {
    emit("REPEAT_END");
}

<*>. { lex_error(yylineno, "unexpected character", yytext); }

%%

void load_tokens(const char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Could not open token list %s\n", path);
        exit(1);
    }

    char name[256];
    while (fscanf(file, "%s", name) == 1) {
        token_names[token_count] = malloc(strlen(name) + 1);
        strcpy(token_names[token_count], name);
        token_count++;
    }
    fclose(file);
}

int token_code(const char* name) {
    for (int i = 0; i < token_count; i++) {
        if (strcmp(token_names[i], name) == 0) {
            return i;
        }
    }
    printf("Token %s is missing from the token list\n", name);
    exit(1);
}

int is_st_token(const char* name) {
    if (strcmp(name, "IDENTIFIER") == 0) {
        return 1;
    }
    if (strcmp(name, "INT_CONST") == 0) {
        return 1;
    }
    if (strcmp(name, "STRING_CONST") == 0) {
        return 1;
    }
    return 0;
}

void emit(const char* name) {
    int code = token_code(name);
    int position = -1;
    if (is_st_token(name)) {
        position = st_insert_or_get(yytext);
    }
    fprintf(pif, "%-4d %-4d %s\n", code, position, name);
}

void lex_error(int line, const char* message, const char* text) {
    error_count++;
    if (text != NULL) {
        printf("LEXICAL ERROR line %d: %s '%s'\n", line, message, text);
    }
    else {
        printf("LEXICAL ERROR line %d: %s\n", line, message);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <source file> [token list]\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        printf("Could not open source file %s\n", argv[1]);
        return 1;
    }

    if (argc > 2) {
        load_tokens(argv[2]);
    }
    else {
        load_tokens("tokens.txt");
    }

    pif = fopen("pif.out", "w");
    fprintf(pif, "%-4s %-4s %s\n", "code", "pos", "token");

    BEGIN(TITLE);
    yylex();

    fclose(pif);
    fclose(yyin);

    FILE* st_file = fopen("st.out", "w");
    st_print(st_file);
    fclose(st_file);

    if (error_count == 0) {
        printf("Lexically correct\n");
    }
    else {
        printf("%d lexical error(s)\n", error_count);
    }

    st_free();
    for (int i = 0; i < token_count; i++) {
        free(token_names[i]);
    }
    return 0;
}
