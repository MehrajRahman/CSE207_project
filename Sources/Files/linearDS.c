
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/Structure_Dynamic.h"
#include "../headers/LinearDS.h"



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


void addData(struct Personalized_DS *Info, enum DataType type)
{
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    void *newData = NULL;
    size_t data_size = 0;

    if (type == STUDENT)
    {
        data_size = sizeof(Student);
    }
    else if (type == FACULTY)
    {
        data_size = sizeof(Faculty);
    }
    else
    {
        printf("Unknown type.\n");
        return;
    }

    newData = malloc(data_size);

    if (newData)
    {
        if (type == STUDENT)
        {
            ((Student *)newData)->username = strdup(username);
            ((Student *)newData)->password = strdup(password);
        }
        else if (type == FACULTY)
        {
            ((Faculty *)newData)->username = strdup(username);
            ((Faculty *)newData)->password = strdup(password);
        }

        if (!(((Student *)newData)->username && ((Student *)newData)->password) &&
            !(((Faculty *)newData)->username && ((Faculty *)newData)->password))
        {
            free(((Student *)newData)->username);
            free(((Student *)newData)->password);
            free(((Faculty *)newData)->username);
            free(((Faculty *)newData)->password);
            free(newData);
            printf("Memory allocation failed.\n");
            return;
        }
    }
    else
    {
        printf("Memory allocation failed.\n");
        return;
    }

    add(Info, newData);
}

void printData(struct Personalized_DS *Info, enum DataType type)
{
    struct Node *current = Info->head;

    printf("List of ");

    if (type == STUDENT)
    {
        printf("Students:\n");
        while (current != NULL)
        {
            Student *currentStudent = (Student *)current->dataPtr;
            printf("Username: %s, Password: %s\n", currentStudent->username, currentStudent->password);
            current = current->next;
        }
    }
    else if (type == FACULTY)
    {
        printf("Faculty:\n");
        while (current != NULL)
        {
            Faculty *currentFaculty = (Faculty *)current->dataPtr;
            printf("Username: %s, Password: %s\n", currentFaculty->username, currentFaculty->password);
            current = current->next;
        }
    }
    else
    {
        printf("Unknown type\n");
    }
}

void freeList(struct Personalized_DS *Info, enum DataType type)
{
    struct Node *current = Info->head;
    struct Node *temp;

    while (current != NULL)
    {
        temp = current;
        current = current->next;

        if (type == STUDENT)
        {
            Student *currentStudent = (Student *)temp->dataPtr;
            free(currentStudent->username);
            free(currentStudent->password);
        }
        else if (type == FACULTY)
        {
            Faculty *currentFaculty = (Faculty *)temp->dataPtr;
            free(currentFaculty->username);
            free(currentFaculty->password);
        }

        free(temp->dataPtr);
        free(temp);
    }

    free(Info);
}

void addStudent(struct Personalized_DS *Info)
{
    addData(Info, STUDENT);
}

void printStudents(struct Personalized_DS *Info)
{
    printData(Info, STUDENT);
}
