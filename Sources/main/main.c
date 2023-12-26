#include <stdio.h>
#include "../headers/portal_system.h"
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
  system("@cls||clear");
    intro();
    init_systems();
    // Admin_Menu();
    // timer();
    struct Personalized_DS *Info_std = Singly_LL();

    timer();
    system("@cls||clear");
    intro();
    Login_Menu();
    int choice;
    do
    {
        // Login_Menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // addStudent(Info_std);
            log_print(l, "Exiting...\n");
            
            break;
        case 2:
            
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

    return 0;
}

