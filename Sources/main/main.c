#include <stdio.h>
#include <string.h>
#include "../headers/portal_system.h"
#include "../headers/timer.h"
#include "../headers/menu.h"
#include "../headers/logger.h"
#include "../headers/LinearDS.h"
#include "../headers/utils.h"
#include "../headers/login_function.h"

static struct logger* l=NULL;
//  = NULL;

void init_systems(){
  l = init_logger(stdout, stderr, stderr);
}

void shutdown_systems(){
  shutdown_logger(l);
}

void init_data(){
    FILE *file = fopen("../Sources/db/student_data.dat", "rb");
    if (file != NULL)
    {
        Student *student = (Student *)malloc(sizeof(Student));

        while (fread(student, sizeof(Student), 1, file) == 1)
        {
            printf("%s ", student->username );
            // addItem(dict_std, student->username, student->password);  
        }
        free(student);
        fclose(file);
    }
    else{
        printf("Not found File!!");
    }

    // return dict_std;

}



int main(){
    char buff[10];
    char username[50],uname[50], password[50];
    system("@cls||clear");

    
    // dict_t **dict_std = init_data();

    // static struct nlist *hashtab[HASHSIZE]; /* pointer table */


    // printf("new Test: %s", (char *)getItem(*dict_std, "fg"));    
    intro();
    init_systems();

    struct Personalized_DS *Info_std = Singly_LL();
    struct Personalized_DS *course_list = Singly_LL();
    struct Personalized_DS *faculty_list = Singly_LL();
    // struct Personalized_DS *Info_std = Singly_LL();

    timer();
    system("@cls||clear");
    int choice;
    do
    {
        
        Login_Menu();
        log_print(l , "\t\t\t\t\t\t\t\xB2 Enter Input : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        fgets(buff, sizeof(buff), stdin);
            // char username[50],uname[50], password[50];
            printf("Enter Username: ");
            scanf("%49s", username);
            printf("Enter Password: ");
            scanf("%49s", password);
            if(strcmp("Admin", username) == 0 && strcmp("Admin", username) == 0  ){
                system("@cls||clear");
                Admin_Menu();
            }else{
                printf("Wrong Credentails!! \n");
            }
            break;
            
            break;
        case 2:
            
            
        case 3:
            // char buff[10];
            fgets(buff, sizeof(buff), stdin);
           
            printf("Enter Username: ");
            scanf("%49s", username);
            printf("Enter Password: ");
            scanf("%49s", password);
            if(studentExist(username, password)){
                system("@cls||clear");
                Student_menu(username);
            }else{
                printf("Wrong Credentails!!\n");
            }
            break;
        case 4:
            return 0;
            break;
        case 5:
            system("@cls||clear");
            addCourseData(course_list, faculty_list);
            break;
        default:
            
            log_print(l, "Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);


    
    shutdown_logger(l);

    return 0;
}

