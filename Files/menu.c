
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include "../headers/timer.h"

void Login_Menu()
{
    printf("Welcome to Login menu\n\n");
    printf("1.Admin\n");
    printf("1.Faculty\n");
    printf("1.Student\n");
}

void Admin_Menu_Student()
{
    printf("1.Add Student \n");
    printf("2.Delete Student \n");
    printf("3.Update Student Information \n");
    printf("4.View All Students \n");
}

void Admin_Menu_Faculty()
{
    printf("1.Add Faculty Member \n");
    printf("2.Delete Faculty Member \n");
    printf("3.Update Faculty Information \n");
    printf("4.View All Faculties \n");
}

void Admin_Menu_Courses()
{
    printf("1.Create Course \n");
    printf("2.Delete Course \n");
    printf("3.Enroll a student in the course \n");
    printf("4.Remove a student from the course \n");
    printf("5.View all courses \n");
    printf("6.View students enrolled in each course \n");
}

void Admin_Menu_Department()
{
    printf("1.Create Department \n");
    printf("2.Delete Department \n");
    printf("3.Assign faculty member to department \n");
    printf("4.Unassign faculty member from department \n");
    printf("5.View all departments \n");
    printf("6.View faculties assigned to each department \n");
}

void Admin_Menu()
{
    printf("welcome\n");
    printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    printf("1.Student management\n");
    printf("2.Faculty management\n");
    printf("3.Course management\n");
    printf("4.Department management\n");
    printf("5.Logout\n");
}

void intro()
{
    printf("\n\n\n\t\t\t\t\t 	\033[33m||||||||||||    |||    ||    |||    |||        |||          \033[0m \n");
    printf("\t\t\t\t\t 	\033[33m|||      |||    |||    ||    |||    |||        |||          \033[0m \n");
    printf("\t\t\t\t\t	\033[33m|||              |||   ||   |||     |||        |||          \033[0m \n");
    printf("\t\t\t\t\t	\033[33m|||||||||||      |||  |  |  |||     |||        |||          \033[0m \n");
    printf("\t\t\t\t\t 	\033[33m|||||||||||       ||| |  | |||      |||        |||          \033[0m \n");
    printf("\t\t\t\t\t 	\033[33m|||               ||| |  | |||      |||        |||          \033[0m \n");
    printf("\t\t\t\t\t 	\033[33m|||      |||       ||||||||||       ||||||||||||||          \033[0m \n");
    printf("\t\t\t\t\t	\033[33m||||||||||||       ||||  ||||       ||||||||||||||||        \033[0m \n\n\n");

    printf("\t\t	\033[34m||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||   \033[0m \n");
    printf("\t\t	\033[34m||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||   \033[0m \n");
    timer();
    system("clear");
    Login_Menu();
}

void Student_menu()
{
    // system("cls");
    printf("WELCOME TO FACULTY MENU");
    // printf("\033[32mThis is green\033[0m");
    printf("1.My Profile\n");
    printf("2.Change Password\n");
    printf("3.Advising\n");      // includes offerd course and retakeable courses
    printf("4.Degree Review\n"); // shows all completed course and their grade
    printf("5.Class Schedule\n");
    printf("6.Logout\n");
}

void Faculty_Menu()
{
    // system("cls");
    // printf("WELCOME TO FACULTY MENU");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t 	\033[33mThis is yellow\033[0m \n\n");
    printf("\033[32mThis is green\033[0m");
    printf("1.Profile\n"); // Shows name, Designation,depertment , edu background etc
    printf("2.Change Password\n");
    printf("3.Allocated Courses\n");        // shows allocated courses info like section , no. of students ,time,day
    printf("4.Browse student by course\n"); // shows student list of each allocated courses
    // printf("5.Student Evaluations\n");            //shows evaluation report for each course
    printf("6.Logout\n");
}
