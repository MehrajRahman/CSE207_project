#include "../headers/portal_system.h"

typedef struct Node
{
    void *dataPtr;
    struct Node *next;
} Node;

typedef struct Personalized_DS
{
    Node *head;
    Node *tail;

} Personalized_DS;

struct Node *createNode(void *data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode)
    {
        newNode->dataPtr = data;
        newNode->next = NULL;
    }
    return newNode;
}

struct Personalized_DS *Singly_LL()
{
    struct Personalized_DS *list = (struct Personalized_DS *)malloc(sizeof(struct Personalized_DS));
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

void add(struct Personalized_DS *Info, void *data)
{
    struct Node *newNode = createNode(data);
    if (newNode)
    {
        if (Info->head == NULL)
        {
            Info->head = Info->tail = newNode;
        }
        else
        {
            Info->tail->next = newNode;
            Info->tail = newNode;
        }
    }
}

