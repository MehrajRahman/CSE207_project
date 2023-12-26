#ifndef UTILS_H
#define UTILS_H

// #include <stdio.h>

typedef struct dict_t_struct
{
    char *key;
    void *value;
    struct dict_t_struct *next;
} dict_t;

dict_t **dictAlloc(void);

void dictDealloc(dict_t **dict);

void *getItem(dict_t *dict, char *key);

void delItem(dict_t **dict, char *key);

void addItem(dict_t **dict, char *key, void *value);

#endif