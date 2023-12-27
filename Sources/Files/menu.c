
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../headers/menu.h"
#include "../headers/timer.h"
#include "../headers/logger.h"
#include "../headers/LinearDS.h"
#include "../headers/utils.h"

static struct logger* l=NULL;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void textcolor(int color) {
    switch (color) {
        case 1:
            printf(ANSI_COLOR_RED);
            break;
        case 2:
            printf(ANSI_COLOR_GREEN);
            break;
        case 3:
            printf(ANSI_COLOR_YELLOW);
            break;
        case 4:
            printf(ANSI_COLOR_BLUE);
            break;
        case 5:
            printf(ANSI_COLOR_MAGENTA);
            break;
        case 6:
            printf(ANSI_COLOR_CYAN);
            break;
        case 7:
        default:
            printf(ANSI_COLOR_RESET);
            break;
    }
}


void printMessageCenter(const char *message)
{
    int len =0;
    int pos = 0;
    len = (44 - strlen(message))/2;
    log_print(l , "\n\n\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        
        log_print(l , " ");
    }
    textcolor(7);
    log_print(l , "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ");
    log_print(l , "%s ",message);
    log_print(l , "\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n ");
}
  
void Login_Menu()
{
     printMessageCenter("Login Menu");
        textcolor(4);
        log_print(l , "\t\t\t\t\t\t\t\xB2 1. Admin  \n\n");
        textcolor(2);
        log_print(l , "\t\t\t\t\t\t\t\xB2 2. Faculty\n\n");
        textcolor(3);
        log_print(l , "\t\t\t\t\t\t\t\xB2 3. Student\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\t\t\xB2 4. Exit\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        textcolor(4);
}

void Admin_Menu_Student()
{
    uint8_t choice;
    do
    {
        printMessageCenter("Admin Menu Student");
        textcolor(4);
        log_print(l , "\t\t\t\t\t\t\t\xB2 1. Add Student   \n\n");
        textcolor(2);
        log_print(l , "\t\t\t\t\t\t\t\xB2 2. Delete Student\n\n");
        textcolor(3);
        log_print(l , "\t\t\t\t\t\t\t\xB2 3. Update Student Information\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\t\t\xB2 4. View All Students\n\n");
        textcolor(6);
        log_print(l , "\t\t\t\t\t\t\t\xB2 5.Return to Main Menu\n\n");
        textcolor(7);
        log_print(l , "\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        textcolor(4);


       

        scanf("%hhu", &choice);

        switch (choice)
        {
        case 1:
            addStudentData();
            break;
        case 2:
            log_print(l, "Work In Progress! \n");
            break;
        case 3:
            Admin_Menu_Faculty();
            break;
        case 4:
            printStudentData();
            break;
        case 5:
            log_print(l, "Goodbye!!!!.\n");
            timer();
            system("@cls||clear");
            return;
            break;
        default:
            log_print(l, "Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
}

void Admin_Menu_Faculty()
{
    

    uint8_t choice;
    do
    {
       

        printMessageCenter("Admin Menu Faculty");
        textcolor(4);
        log_print(l , "\t\t\t\t\t\t\t\xB2 1. Add Faculty Member   \n\n");
        textcolor(2);
        log_print(l , "\t\t\t\t\t\t\t\xB2 2. Delete Faculty Member\n\n");
        textcolor(3);
        log_print(l , "\t\t\t\t\t\t\t\xB2 3. Update Faculty Information\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\t\t\xB2 4. View All Faculties\n\n");
        textcolor(6);
        log_print(l , "\t\t\t\t\t\t\t\xB2 5.Return to Main Menu\n\n");
        textcolor(7);
        log_print(l , "\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        textcolor(4);


        log_print(l , "\t\t\t\t\t\t\t\xB2 Enter Input : ");
       
        scanf("%hhu", &choice);

        switch (choice)
        {
        case 1:
           addFacultyData();
            break;
        case 2:
            log_print(l, "Work In Progress! \n");
            break;
        case 3:
            log_print(l, "Work In Progress! \n");
            break;
        case 4:
            printFacultyData();
            break;
        case 5:
            log_print(l, "Goodbye!!!!.\n");
            timer();
            system("@cls||clear");
            return;
            break;
        default:
            log_print(l, "Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
}

void Admin_Menu_Courses()
{
    

    uint8_t choice;
    do
    {

        printMessageCenter("Admin Menu Courses");
        textcolor(4);
        log_print(l , "\t\t\t\t\t\t\t\xB2 1. Create Course\n\n");
        textcolor(2);
        log_print(l , "\t\t\t\t\t\t\t\xB2 2. Delete Course\n\n");
        textcolor(3);
        log_print(l , "\t\t\t\t\t\t\t\xB2 3. Enroll a student in the course\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\t\t\xB2 4. Remove a student from the course\n\n");
        textcolor(6);
        log_print(l , "\t\t\t\t\t\t\t\xB2 5. View all courses \n\n");
        textcolor(9);
        log_print(l , "\t\t\t\t\t\t\t\xB2 6. View students enrolled in each course\n\n");
        textcolor(8);
        log_print(l , "\t\t\t\t\t\t\t\xB2 7.Return to Main Menu \n\n");
        textcolor(7);
        log_print(l , "\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        textcolor(4);


        log_print(l , "\t\t\t\t\t\t\t\xB2 Enter Input : ");
       
        scanf("%hhu", &choice);

        switch (choice)
        {
        case 1:
           addCourseData();
            break;
        case 2:
            log_print(l, "Work In Progress! \n");
            break;
        case 3:
            log_print(l, "Work In Progress! \n");
            break;
        case 4:
            printCourseData();
            break;
        case 5:
            printCourseData();
            break;
           
        case 6:
            log_print(l, "Work In Progress! \n");
            break;
        case 7:
            log_print(l, "Goodbye!!!!.\n");
            timer();
            system("@cls||clear");
            return;

        default:
            log_print(l, "Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
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
    

    uint8_t choice;

    do
    {
         printMessageCenter("Admin Menu");
        textcolor(4);
        log_print(l , "\t\t\t\t\t\t\t\xB2 1. Student management\n\n");
        textcolor(2);
        log_print(l , "\t\t\t\t\t\t\t\xB2 2. Faculty management\n\n");
        textcolor(3);
        log_print(l , "\t\t\t\t\t\t\t\xB2 3. Course management\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\t\t\xB2 4. Department management\n\n");
        textcolor(6);
        log_print(l , "\t\t\t\t\t\t\t\xB2 5.Return to Main Menu\n\n");
        textcolor(9);
         log_print(l , "\t\t\t\t\t\t\t\xB2 6. Logout \n\n");
        textcolor(7);
        log_print(l , "\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        textcolor(4);


        log_print(l , "\t\t\t\t\t\t\t\xB2 Enter Input : ");

       
        scanf("%hhu", &choice);

        switch (choice)
        {
        case 1:
            system("@cls||clear");
            Admin_Menu_Student();
            break;
        case 2:
        system("@cls||clear");
            Admin_Menu_Faculty();
            break;
        case 3:
        system("@cls||clear");
            Admin_Menu_Courses();
            break;
        case 4:
        system("@cls||clear");
            Admin_Menu_Department();
            break;
        case 5:
            log_print(l, "Goodbye!!!!.\n");
            timer();
            system("@cls||clear");
            return;
            break;
        case 6:
            log_print(l, "Goodbye!!!!.\n");
            timer();
            system("@cls||clear");
            return;
            break;
        default:
            log_print(l, "Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);
}

void header()
{
    // l = init_logger(stdout, stderr, stderr);
    log_print(l, "\t\t\t\t\t     \033[33m _______   ___     ___      __   __    __ \033[0m \n");
    log_print(l, "\t\t\t\t\t     \033[33m|   ____|\\   \\  //  \\  //  / |  |  |  |          \033[0m \n");
    log_print(l, "\t\t\t\t\t     \033[33m|  |__    \\   \\//    \\//  /  |  |  |  |        \033[0m \n");
    log_print(l, "\t\t\t\t\t     \033[33m|   __|    \\      __       /   |  |  |  |        \033[0m \n");
    log_print(l, "\t\t\t\t\t     \033[33m|  |____    \\    //\\     /    |  `--'  |          \033[0m \n");
    log_print(l, "\t\t\t\t\t     \033[33m|_______|    \\__//  \\__ /     \\______/           \033[0m \n");

    log_print(l, "\t\t    \033[34m -------------------------------------------------------------------------------------  \033[0m \n");
}

void intro()
{
    l = init_logger(stdout, stderr, stderr);
    log_print(l, "\t\t	\033[34m||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||   \033[0m \n");
    log_print(l, "\t\t	\033[34m||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||   \033[0m \n");
    
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
    
}

void Student_menu(char *username)
{
    uint8_t choice;
    
    do
    {
        printMessageCenter("Student menu");
        textcolor(4);
        log_print(l , "\t\t\t\t\t\t\t\xB2 1. My Profile   \n\n");
        textcolor(2);
        log_print(l , "\t\t\t\t\t\t\t\xB2 2. Change Password\n\n");
        textcolor(3);
        log_print(l , "\t\t\t\t\t\t\t\xB2 3. Advising\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\t\t\xB2 4. Degree Review\n\n");
        textcolor(6);
        log_print(l , "\t\t\t\t\t\t\t\xB2 5. Class Schedule \n\n");
        textcolor(9);
        log_print(l , "\t\t\t\t\t\t\t\xB2 6. Log Out\n\n");
        textcolor(8);
        log_print(l , "\t\t\t\t\t\t\t\xB2 7. Return to main menu. \n\n");
        textcolor(7);
        log_print(l , "\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        textcolor(4);



        log_print(l , "\t\t\t\t\t\t\t\xB2 Enter Input : ");
       
        scanf("%hhu", &choice);

        switch (choice)
        {
        case 1:
        
            printSingleStudentInfo(username);
            timer();
            system("@cls||clear");
            break;
        case 2:
        
            StudentChangePassword(username);
            timer();
            system("@cls||clear");
            break;
        case 3:
        
            addCourseToStudent(username);
            timer();
            system("@cls||clear");
            break;
        case 4:


            log_print(l, "Work In Progress.\n");
            break;
        case 5:
            log_print(l, "Work In Progress.\n");
            break;
        case 6:
            log_print(l, "Goodbye!!!!.\n");
            timer();
            system("@cls||clear");
            return;
            break;
        default:
            
            log_print(l, "Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 7);
}

void Faculty_Menu()
{
    // system("cls");
    // log_print(l, "WELCOME TO FACULTY MENU");
    // log_print(l, "\n\n\n\t\t\t\t\t\t\t\t\t\t\t 	\033[33mThis is yellow\033[0m \n\n");
    // log_print(l, "\033[32mThis is green\033[0m");
    // log_print(l, "1.Profile\n"); // Shows name, Designation,depertment , edu background etc
    // log_print(l, "2.Change Password\n");
    // log_print(l, "3.Allocated Courses\n");        
    // log_print(l, "4.Browse student by course\n"); 
         
    // log_print(l, "6.Logout\n");

        printMessageCenter("Faculty Menu");
        textcolor(4);
        log_print(l , "\t\t\t\t\t\t\t\xB2 1. Profile   \n\n");
        textcolor(2);
        log_print(l , "\t\t\t\t\t\t\t\xB2 2. Change Password\n\n");
        textcolor(3);
        log_print(l , "\t\t\t\t\t\t\t\xB2 3. Allocated Courses\n\n");
        textcolor(5);
        log_print(l , "\t\t\t\t\t\t\t\xB2 4. Browse student by course \n\n");
        textcolor(6);
        log_print(l , "\t\t\t\t\t\t\t\xB2 5. Log Out\n\n");
        textcolor(8);
        log_print(l , "\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        textcolor(4);
}


