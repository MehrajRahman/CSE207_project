#ifndef LINEARDS_H
#define LINEARDS_H

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "portal_system.h"
#include "logger.h"

struct Node
{
    void *dataPtr;
    struct Node *next;
};

struct Personalized_DS
{
    struct Node *head;
    struct Node *tail;
};

struct Node *createNode(void *data);

struct Personalized_DS *Singly_LL();

void add(struct Personalized_DS *Info, void *data);

enum DataType
{
    STUDENT,
    FACULTY
};

void addData(struct Personalized_DS *Info, enum DataType type);

void printData(struct Personalized_DS *Info, enum DataType type);

void freeList(struct Personalized_DS *Info, enum DataType type);


#endif