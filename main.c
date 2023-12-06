#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./headers/Structure_Dynamic.h"



int main() {
    Student* Dummy = NULL;
    int numStudents = 0;
    
        numStudents++;
        Dummy = realloc(Dummy, numStudents * sizeof(Student));
        Dummy[numStudents - 1].username = malloc(50 * sizeof(char));
        Dummy[numStudents - 1].password = malloc(50 * sizeof(char));
        strcpy(Dummy[numStudents - 1].username,"Shoeb1");
        strcpy(Dummy[numStudents - 1].password,"1234");

        numStudents++;
        Dummy = realloc(Dummy, numStudents * sizeof(Student));
        Dummy[numStudents - 1].username = malloc(50 * sizeof(char));
        Dummy[numStudents - 1].password = malloc(50 * sizeof(char));
        strcpy(Dummy[numStudents - 1].username,"Shoeb2");
        strcpy(Dummy[numStudents - 1].password,"1234");


    for (int i = 0; i < numStudents; i++) 
    {
        printf("Dummy %d:\n", i + 1);
        printf("Username: %s\n", Dummy[i].username);
        printf("Password: %s\n", Dummy[i].password);
        printf("\n");
    }

    for (int i = 0; i < numStudents; i++)
     {
        free(Dummy[i].username);
        free(Dummy[i].password);
        free(Dummy[i].name);
    }
    free(Dummy);

}

