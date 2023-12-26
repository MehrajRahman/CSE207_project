#ifndef LOGIN_FUNCTION_H
#define LOGIN_FUNCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "portal_system.h"
// #include "menu.h"

bool Login_Credential_Check_Student(char *username, char *password);

bool Login_Credential_Check_Faculty(char *username, char *password, int numFaculties, Faculty *faculties);

void Student_Login_page(int numOfStudents, Student *student);

void Faculty_Login_Page(int numOfFaculties, Faculty *faculty);

#endif