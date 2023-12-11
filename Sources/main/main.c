#include <stdio.h>
#include "../headers/Structure_Dynamic.h"
#include "../headers/timer.h"
#include "../headers/menu.h"
#include "../headers/logger.h"
#include "../headers/LinearDS.h"



static struct logger* l=NULL;

void init_systems(){

  l = init_logger(stdout, stderr, stderr);

}

void shutdown_systems(){

  shutdown_logger(l);
 }

int main(){

    intro();
    init_systems();
    // Admin_Menu();
    // timer();
    struct Personalized_DS *Info_std = Singly_LL();

    int choice;
    // do
    // {
    //     log_print(l,"Menu:\n");
    //     log_print(l,"1. Add Student\n");
    //     log_print(l,"2. Print Students\n");
    //     log_print(l,"3. Exit\n");
    //     log_print(l,"Enter your choice: ");
    //     scanf("%d", &choice);

    //     switch (choice)
    //     {
    //     case 1:
    //         addStudent(Info_std);
    //         break;
    //     case 2:
    //         printStudents(Info_std);
    //         break;
    //     case 3:
    //         log_print(l, "Exiting...\n");
    //         break;
    //     default:
    //         log_print(l, "Invalid choice! Please enter a valid option.\n");
    //     }
    // } while (choice != 3);

    freeList(Info_std, STUDENT);
    shutdown_systems();

    return 0;
}

