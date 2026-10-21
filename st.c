#include "st.h"

#include <stdlib.h>
#include <string.h>

#define ST_SIZE 101

typedef struct Entry {
    char* lexeme;
    int position;
    struct Entry* next;
} Entry;

Entry* buckets[ST_SIZE];
Entry** by_position = NULL;
int count = 0;
int capacity = 0;

char* copy_string(const char* s) {
    size_t n = strlen(s) + 1;
    char* copy = malloc(n);
    memcpy(copy, s, n);
    return copy;
}

unsigned hash(const char* s) {
    unsigned long h = 0;
    while (*s != 0) {
        h = h * 31 + *s;
        s++;
    }
    return (unsigned)(h % ST_SIZE);
}

int st_insert_or_get(const char* lexeme) {
    unsigned b = hash(lexeme);

    for (Entry* e = buckets[b]; e != NULL; e = e->next) {
        if (strcmp(e->lexeme, lexeme) == 0) {
            return e->position;
        }
    }

    Entry* e = malloc(sizeof *e);
    e->lexeme = copy_string(lexeme);
    e->position = count;
    e->next = buckets[b];
    buckets[b] = e;

    if (count == capacity) {
        capacity = capacity ? capacity * 2 : 16;
        Entry** new_array = realloc(by_position, capacity * sizeof(*new_array));
        by_position = new_array;
    }
    by_position[count++] = e;

    return e->position;
}

void st_print(FILE* out) {
    fprintf(out, "%-8s %-8s %s\n", "pos", "bucket", "lexeme");
    for (int i = 0; i < count; i++) {
        fprintf(out, "%-8d %-8u %s\n", i, hash(by_position[i]->lexeme), by_position[i]->lexeme);
    }
}

void st_free() {
    for (int b = 0; b < ST_SIZE; b++) {
        Entry* e = buckets[b];
        while (e) {
            Entry* next = e->next;
            free(e->lexeme);
            free(e);
            e = next;
        }
        buckets[b] = NULL;
    }
    free(by_position);
    by_position = NULL;
    count = capacity = 0;
}