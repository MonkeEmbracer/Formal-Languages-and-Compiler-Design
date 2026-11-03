#ifndef FA_H
#define FA_H

#define FA_NAME_LEN 16
#define FA_MAX_TRANSITIONS 64
#define FA_MAX_FINALS 16

typedef struct {
    char from[FA_NAME_LEN];
    char label[FA_NAME_LEN];
    char to[FA_NAME_LEN];
} Transition;

typedef struct {
    char initial[FA_NAME_LEN];
    char finals[FA_MAX_FINALS][FA_NAME_LEN];
    int final_count;
    Transition transitions[FA_MAX_TRANSITIONS];
    int transition_count;
} FA;

void fa_load(FA* fa, char* path);
int fa_accepts(FA* fa, char* word);

#endif