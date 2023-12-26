
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../headers/portal_system.h"
#include "../headers/menu.h"

#ifndef __cplusplus
#ifndef _BOOL
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif
#endif

#define MAX_LIMIT 50

bool Login_Credential_Check_Student(char *username, char *password, dict_t **dict_std)
{
    bool found = false;
    // for (int i = 0; i < numStudents; i++)
    // {
    //     if (strcmp(username, students[i].username) == 0 && strcmp(password, students[i].password) == 0)
    //     {
    //         found = true;
    //         break;
    //     }
    // }
    return found;
}

bool Login_Credential_Check_Faculty(char *username, char *password, int numFaculties, Faculty *faculties)
{
    bool found = false;

    for (int i = 0; i < numFaculties; i++)
    {
        if (strcmp(username, faculties[i].username) == 0 && strcmp(password, faculties[i].password) == 0)
        {
            found = true;
            break;
        }
    }
    return found;
}

void Student_Login_page(int numOfStudents, Student *student)
{
    char studentUsername[50], studentPassword[50];

    printf("Enter Username: ");
    // scanf("%[^\n]%*c", &studentUsername);
    fgets(studentUsername, MAX_LIMIT, stdin);
    printf("\nEnter Password: ");
    // scanf("%[^\n]%*c", &studentPassword);
    fgets(studentPassword, MAX_LIMIT, stdin);

    while (!Login_Credential_Check_Student(studentUsername, studentPassword, numOfStudents, student))
    {
        system("cls");
        printf("Invalid Credentials\nPlease try again.\n");
        printf("Press any key to continue...");
        getchar();
        system("cls");
    }

    system("cls");
    printf("Welcome %s!\n", studentUsername);
    printf("You are logged in as a student. Please choose an option from the menu below:\n");
    Student_menu();
}

void Faculty_Login_Page(int numOfFaculties, Faculty *faculty)
{
    char facultyUsername[50], facultyPassword[50];

    printf("Enter Faculty Username: ");
    scanf("%s", facultyUsername);
    printf("\nEnter Faculty Password: ");
    scanf("%s", facultyPassword);

    while (!Login_Credential_Check_Faculty(facultyUsername, facultyPassword, numOfFaculties, faculty))
    {
        system("cls");
        printf("Invalid Credentials\nPlease try again.\n");
        printf("Press any key to continue...");
        getchar();
        system("cls");
        printf("Enter Faculty Username: ");
        scanf("%s", facultyUsername);
        printf("\nEnter Faculty Password: ");
        scanf("%s", facultyPassword);
    }

    system("cls");
    printf("Welcome %s!\n", facultyUsername);
    printf("You are logged in as a faculty member. Please choose an option from the faculty menu below:\n");
    Faculty_Menu();
}