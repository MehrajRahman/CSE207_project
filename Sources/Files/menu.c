
#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#include "../headers/menu.h"
#include "../headers/timer.h"
#include "../headers/logger.h"
#include "../headers/LinearDS.h"

static struct logger* l=NULL;
  
void Login_Menu()
{
    log_print(l, "Welcome to Login menu\n\n");
    log_print(l, "1.Admin\n");
    log_print(l, "2.Faculty\n");
    log_print(l, "3.Student\n");
}

void Admin_Menu_Student()
{
    log_print(l, "1.Add Student \n");
    log_print(l, "2.Delete Student \n");
    log_print(l, "3.Update Student Information \n");
    log_print(l, "4.View All Students \n");
}

void Admin_Menu_Faculty()
{
    log_print(l, "1.Add Faculty Member \n");
    log_print(l, "2.Delete Faculty Member \n");
    log_print(l, "3.Update Faculty Information \n");
    log_print(l, "4.View All Faculties \n");
}

void Admin_Menu_Courses()
{
    log_print(l, "1.Create Course \n");
    log_print(l, "2.Delete Course \n");
    log_print(l, "3.Enroll a student in the course \n");
    log_print(l, "4.Remove a student from the course \n");
    log_print(l, "5.View all courses \n");
    log_print(l, "6.View students enrolled in each course \n");
}

void Admin_Menu_Department()
{
    log_print(l, "1.Create Department \n");
    log_print(l, "2.Delete Department \n");
    log_print(l, "3.Assign faculty member to department \n");
    log_print(l, "4.Unassign faculty member from department \n");
    log_print(l, "5.View all departments \n");
    log_print(l, "6.View faculties assigned to each department \n");
}

void Admin_Menu()
{
    log_print(l, "welcome\n");
    log_print(l, "\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
    log_print(l, "1.Student management\n");
    log_print(l, "2.Faculty management\n");
    log_print(l, "3.Course management\n");
    log_print(l, "4.Department management\n");
    log_print(l, "5.Logout\n");
}

void intro()
{
    l = init_logger(stdout, stderr, stderr);
    log_print(l, "\n\n\n\t\t\t\t\t 	\033[33m||||||||||||    |||    ||    |||    |||        |||          \033[0m \n");
    log_print(l, "\t\t\t\t\t 	\033[33m|||      |||    |||    ||    |||    |||        |||          \033[0m \n");
    log_print(l, "\t\t\t\t\t	\033[33m|||              |||   ||   |||     |||        |||          \033[0m \n");
    log_print(l, "\t\t\t\t\t	\033[33m|||||||||||      |||  |  |  |||     |||        |||          \033[0m \n");
    log_print(l, "\t\t\t\t\t 	\033[33m|||||||||||       ||| |  | |||      |||        |||          \033[0m \n");
    log_print(l, "\t\t\t\t\t 	\033[33m|||               ||| |  | |||      |||        |||          \033[0m \n");
    log_print(l, "\t\t\t\t\t 	\033[33m|||      |||       ||||||||||       ||||||||||||||          \033[0m \n");
    log_print(l, "\t\t\t\t\t	\033[33m||||||||||||       ||||  ||||       ||||||||||||||||        \033[0m \n\n\n");

    log_print(l, "\t\t	\033[34m||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||   \033[0m \n");
    log_print(l, "\t\t	\033[34m||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||   \033[0m \n");
    timer();
    system("@cls||clear");
    Login_Menu();
    int choice;
    do
    {
        Login_Menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // addStudent(Info_std);
            log_print(l, "Exiting...\n");
            
            break;
        case 2:
            // printStudents(Info_std);
            log_print(l, "Exiting...\n");
            break;
        case 3:
            log_print(l, "Exiting...\n");
            break;
        default:
            log_print(l, "Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 3);
    shutdown_logger(l);
}

void Student_menu()
{
    // system("cls");
    log_print(l, "WELCOME TO FACULTY MENU");
    // log_print(l, "\033[32mThis is green\033[0m");
    log_print(l, "1.My Profile\n");
    log_print(l, "2.Change Password\n");
    log_print(l, "3.Advising\n");      // includes offerd course and retakeable courses
    log_print(l, "4.Degree Review\n"); // shows all completed course and their grade
    log_print(l, "5.Class Schedule\n");
    log_print(l, "6.Logout\n");
}

void Faculty_Menu()
{
    // system("cls");
    // log_print(l, "WELCOME TO FACULTY MENU");
    log_print(l, "\n\n\n\t\t\t\t\t\t\t\t\t\t\t 	\033[33mThis is yellow\033[0m \n\n");
    log_print(l, "\033[32mThis is green\033[0m");
    log_print(l, "1.Profile\n"); // Shows name, Designation,depertment , edu background etc
    log_print(l, "2.Change Password\n");
    log_print(l, "3.Allocated Courses\n");        // shows allocated courses info like section , no. of students ,time,day
    log_print(l, "4.Browse student by course\n"); // shows student list of each allocated courses
    // log_print(l, "5.Student Evaluations\n");            //shows evaluation report for each course
    log_print(l, "6.Logout\n");
}


