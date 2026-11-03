#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fa.h"

int starts_with(char* line, char* prefix) {
    return strncmp(line, prefix, strlen(prefix)) == 0;
}

void read_finals(FA* fa, char* line) {
    char* open = strchr(line, '{');
    char* close = strchr(line, '}');
    if (open == NULL || close == NULL) {
        printf("Bad final states line: %s\n", line);
        exit(1);
    }
    *close = 0;

    char* name = strtok(open + 1, ", ");
    while (name != NULL) {
        if (fa->final_count == FA_MAX_FINALS) {
            printf("Too many final states\n");
            exit(1);
        }
        strcpy(fa->finals[fa->final_count], name);
        fa->final_count++;
        name = strtok(NULL, ", ");
    }
}

void read_transition(FA* fa, char* line) {
    if (fa->transition_count == FA_MAX_TRANSITIONS) {
        printf("Too many transitions\n");
        exit(1);
    }
    Transition* t = &fa->transitions[fa->transition_count];

    char* from = strtok(line + 2, ", )=");
    char* label = strtok(NULL, ", )=");
    char* to = strtok(NULL, ", )=");
    if (from == NULL || label == NULL || to == NULL) {
        printf("Bad transition line: %s\n", line);
        exit(1);
    }

    strcpy(t->from, from);
    strcpy(t->label, label);
    strcpy(t->to, to);
    fa->transition_count++;
}

void fa_load(FA* fa, char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        printf("Could not open FA file %s\n", path);
        exit(1);
    }

    fa->initial[0] = 0;
    fa->final_count = 0;
    fa->transition_count = 0;

    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        
        if (starts_with(line, "d(")) {
            read_transition(fa, line);
        }
        else if (starts_with(line, "q0 =")) {
            sscanf(line, "q0 = %15s", fa->initial);
        }
        else if (starts_with(line, "F =")) {
            read_finals(fa, line);
        }
        else if (line[0] == 0 || starts_with(line, "Q =") || starts_with(line, "Σ =")) {
            // whatever
        }
        else {
            printf("Unknown line in %s: %s\n", path, line);
        }
    }
    fclose(file);

    if (fa->initial[0] == 0) {
        printf("No initial state in %s\n", path);
        exit(1);
    }
}

// I'm tryna accept labels like "space", a range like "A-Z", or a single character like "-"
int label_matches(char* label, char c) {
    if (strcmp(label, "space") == 0) {
        return c == ' ';
    }
    if (strlen(label) == 3 && label[1] == '-') {
        return c >= label[0] && c <= label[2];
    }
    if (strlen(label) == 1) {
        return c == label[0];
    }
    return 0;
}

int is_final(FA* fa, char* state) {
    for (int i = 0; i < fa->final_count; i++) {
        if (strcmp(fa->finals[i], state) == 0) {
            return 1;
        }
    }
    return 0;
}

int fa_accepts(FA* fa, char* word) {
    char* current = fa->initial;

    for (int i = 0; word[i] != 0; i++) {
        char* next = NULL;
        for (int j = 0; j < fa->transition_count; j++) {
            Transition* t = &fa->transitions[j];
            if (strcmp(t->from, current) == 0 && label_matches(t->label, word[i])) {
                next = t->to;
                break;
            }
        }
        if (next == NULL) {
            return 0;
        }
        current = next;
    }

    return is_final(fa, current);
}