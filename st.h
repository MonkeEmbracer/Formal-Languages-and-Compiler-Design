#ifndef ST_H
#define ST_H

#include <stdio.h>

int st_insert_or_get(const char* lexeme);

void st_print(FILE* out);

void st_free();

#endif