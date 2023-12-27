

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>

#include "../headers/utils.h"
#include "../headers/portal_system.h"


#include "../headers/logger.h"
#include "../headers/LinearDS.h"




// static struct logger* l=NULL;

// typedef struct Node
// {
//     void *dataPtr;
//     struct Node *next;
// } Node;

// typedef struct Personalized_DS
// {
//     Node *head;
//     Node *tail;

// } Personalized_DS;

// struct Node *createNode(void *data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     if (newNode)
//     {
//         newNode->dataPtr = data;
//         newNode->next = NULL;
//     }
//     return newNode;
// }

// struct Personalized_DS *Singly_LL()
// {
//     struct Personalized_DS *list = (struct Personalized_DS *)malloc(sizeof(struct Personalized_DS));
//     if (list)
//     {
//         list->head = NULL;
//         list->tail = NULL;
//     }
//     return list;
// }

// void add()
// {
//     struct Node *newNode = createNode(data);
//     if (newNode)
//     {
//         if (Info->head == NULL)
//         {
//             Info->head = Info->tail = newNode;
//         }
//         else
//         {
//             Info->tail->next = newNode;
//             Info->tail = newNode;
//         }
//     }
// }

void addStudentData()
{
    // l = init_logger(stdout, stderr, stderr);
    system("@cls||clear");
    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (newStudent == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter student's username: ");
    scanf("%49s", newStudent->username);

    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter student's password: ");
    scanf("%49s", newStudent->password);

    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter student's full name: ");
    scanf("%49s", newStudent->name);

    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter student's ID: ");
    scanf("%hu", &newStudent->id);

    int depChoice;
    do
    {
        printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Choose student's department:\n");
        printf("\t\t\t\t\t\t\t1. Computer Science\n\t\t\t\t\t\t\t2. Electrical Engineering\n\t\t\t\t\t\t\t3. Pharmacy\n\t\t\t\t\t\t\t4. Mathematical and Physical Sciences\n\t\t\t\t\t\t\t5. Non-Elective\n");
        scanf("%d", &depChoice);

        if (depChoice < 1 || depChoice > 5)
        {
            printf("\t\t\t\t\t\t\tInvalid choice. Please choose again.\n");
        }
    } while (depChoice < 1 || depChoice > 5);

    memset(newStudent->std_dep, 0, sizeof(newStudent->std_dep));
    newStudent->std_dep[depChoice - 1] = true;

    switch (depChoice)
    {
    case 1:
        strcpy(newStudent->department, "CSE");
        break;
    case 2:
        strcpy(newStudent->department, "EEE");
        break;
    case 3:
        strcpy(newStudent->department, "Pharmacy");
        break;
    case 4:
        strcpy(newStudent->department, "Department of Mathematical and Physical Sciences");
        break;
    case 5:
        strcpy(newStudent->department, "Non-Elective");
        break;
    default:
        strcpy(newStudent->department, "Non-Elective");
        break;
    }

    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter student's advisor: ");
    scanf("%49s", newStudent->advisor);

    newStudent->cgpa = 0;
    newStudent->completed_credit = 0;
    newStudent->completed_courses = NULL;
    newStudent->num_current_courses = 0;
    memset(newStudent->current_semester_courses, 0, sizeof(newStudent->current_semester_courses));
    newStudent->num_current_courses = 0;

    // add(Info, newStudent);

    FILE *file = fopen("../Sources/db/student_data.dat", "ab");
    if (file != NULL)
    {
        fwrite(newStudent, sizeof(Student), 1, file);
        fclose(file);
    }
    else
    {
        printf("Error opening file for writing!\n");
    }

    free(newStudent);
}

void printStudentData()
{
    // l = init_logger(stdout, stderr, stderr);
    system("@cls||clear");
    FILE *file = fopen("../Sources/db/student_data.dat", "rb");
    if (file != NULL)
    {
        Student student;

        while (fread(&student, sizeof(Student), 1, file) == 1)
        {
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Username: %s\n", student.username);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Password: %s\n", student.password);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Full Name: %s\n", student.name);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's ID: %d\n", student.id);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Department: %s\n", student.department);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Completed Credit Hours: %.2f\n", student.completed_credit);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Advisor: %s\n", student.advisor);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's CGPA: %.2f\n", student.cgpa);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Department Information: ");
            if (student.std_dep[0])
                printf("Computer Science\n");
            if (student.std_dep[1])
                printf("Electrical Engineering\n");
            if (student.std_dep[2])
                printf("Pharmacy\n");
            if (student.std_dep[3])
                printf("Mathematical and Physical Sciences\n");
            if (student.std_dep[4])
                printf("Non-Elective\n");

            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Allocated Courses:\n");
            if (student.num_current_courses > 0 && student.current_semester_courses != NULL)
            {
                for (int i = 0; i < student.num_current_courses; ++i)
                {
                    printf("\t\t\t\t\t\t\t\t** Course ID: %s\n", student.current_semester_courses[i].course_id);
                    printf("\t\t\t\t\t\t\t\t** Course Name: %s\n", student.current_semester_courses[i].course_name);
                    printf("\n");
                }
            }
            else
            {
                printf("\t\t\t\t\t\t\t   **No allocated courses for this student.\n");
            }
            printf("\n");

            // free(student.current_semester_courses);
            printf("\n");
            printf("\n");
        }

        fclose(file);
    }
    else
    {
        printf("Error opening file for reading!\n");
    }
}

void printSingleStudentInfo(char *username)
{
    FILE *file = fopen("../Sources/db/student_data.dat", "rb");
    if (file != NULL)
    {
        Student student;

        while (fread(&student, sizeof(Student), 1, file) == 1)
        {
            if (strcmp(student.username, username) == 0)
            {
                printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Username: %s\n", student.username);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Password: %s\n", student.password);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Full Name: %s\n", student.name);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's ID: %d\n", student.id);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Department: %s\n", student.department);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Completed Credit Hours: %.2f\n", student.completed_credit);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's Advisor: %s\n", student.advisor);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Student's CGPA: %.2f\n", student.cgpa);
                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Department Information: ");
                if (student.std_dep[0])
                    printf("Computer Science\n");
                if (student.std_dep[1])
                    printf("Electrical Engineering\n");
                if (student.std_dep[2])
                    printf("Pharmacy\n");
                if (student.std_dep[3])
                    printf("Mathematical and Physical Sciences\n");
                if (student.std_dep[4])
                    printf("Non-Elective\n");

                printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Allocated Courses:\n");
                if (student.num_current_courses > 0 && student.current_semester_courses != NULL)
                {
                    for (int i = 0; i < student.num_current_courses; ++i)
                    {
                        printf("\t\t\t\t\t\t\t\t** Course ID: %s\n", student.current_semester_courses[i].course_id);
                        printf("\t\t\t\t\t\t\t\t** Course Name: %s\n", student.current_semester_courses[i].course_name);
                        printf("\n");
                    }
                }
                else
                {
                    printf("\t\t\t\t\t\t\t**   No allocated courses for this student.\n");
                }
                printf("\n");

                // free(student.current_semester_courses);
                fclose(file);
                return;
            }
        }

        printf("Student with username '%s' not found.\n", username);
        fclose(file);
    }
    else
    {
        printf("Error opening file for reading!\n");
    }
}

void StudentChangePassword(char *username)
{
    system("@cls||clear");
    FILE *file = fopen("../Sources/db/student_data.dat", "rb+");
    if (file != NULL)
    {
        Student student;

        while (fread(&student, sizeof(Student), 1, file) == 1)
        {
            if (strcmp(student.username, username) == 0)
            {
                char newPassword[50];
                printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter new password for username '%s': ", username);
                scanf("%49s", newPassword);
                fseek(file, -sizeof(Student), SEEK_CUR);
                strcpy(student.password, newPassword);
                fwrite(&student, sizeof(Student), 1, file);
                fclose(file);
                printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Password updated successfully for username: %s ", username);
                return;
            }
        }

        fclose(file);
        printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Student with username '%s' not found.\n", username);
    }
    else
    {
        printf("Error opening file for reading!\n");
    }
}

void addFacultyData()
{
    system("@cls||clear");
    Faculty *newFaculty = (Faculty *)malloc(sizeof(Faculty));
    Course *allocated_courses = NULL;

    fflush(stdin);
    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter faculty username: ");
    scanf("%49s", newFaculty->username);

    fflush(stdin);
    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter faculty password: ");
    scanf("%49s", newFaculty->password);
    fflush(stdin);

    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter faculty name: ");
    scanf("%49s", newFaculty->name);

    fflush(stdin);
    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter faculty department: ");
    scanf("%49s", newFaculty->department);

    fflush(stdin);
    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter faculty designation: ");
    scanf("%49s", newFaculty->designation);

    fflush(stdin);
    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter faculty educational background: ");
    scanf("%49s", newFaculty->educational_background);

    newFaculty->allocated_courses = allocated_courses;
    newFaculty->allocated_courses_count = 0;

    // add(Info, newFaculty);

    FILE *file = fopen("../Sources/db/faculty_data.dat", "ab");
    if (file != NULL)
    {
        fwrite(newFaculty, sizeof(Faculty), 1, file);
        fclose(file);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Error opening file for writing!\n");
    }
}

void printFacultyData()
{
    system("@cls||clear");
    FILE *file = fopen("../Sources/db/faculty_data.dat", "rb");
    if (file != NULL)
    {
        Faculty *faculty = (Faculty *)malloc(sizeof(Faculty));

        while (fread(faculty, sizeof(Faculty), 1, file) == 1)
        {
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Username: %s\n", faculty->username);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Password: %s\n", faculty->password);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Name: %s\n", faculty->name);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Department: %s\n", faculty->department);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Designation: %s\n", faculty->designation);
            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Educational Background: %s\n", faculty->educational_background);

            printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Allocated Courses:\n");
            if (faculty->allocated_courses_count > 0)
            {
                for (uint16_t i = 0; i < faculty->allocated_courses_count; ++i)
                {
                    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 **Course ID: %s\n", faculty->allocated_courses[i].course_id);
                    printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 **Course Name: %s\n", faculty->allocated_courses[i].course_name);
                }
            }
            else
            {
                printf("\t\t\t\t\t\t\t** No allocated courses for this faculty.\n");
            }
            printf("\n");
        }

        fclose(file);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\xDB\xDB\xB2 Error opening file for reading!\n");
    }
}

void addCourseData()
{
    system("@cls||clear");
    Course *newCourse = (Course *)malloc(sizeof(Course));

    for (int i = 0; i < 5; ++i)
    {
        newCourse->dept_course[i] = false;
    }

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter course ID: ");
    scanf("%49s", newCourse->course_id);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter course name: ");
    scanf("%49s", newCourse->course_name);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter course code: ");
    scanf("%hu", &newCourse->course_code);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter section: ");
    scanf("%hu", &newCourse->section);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter time slot: ");
    scanf("%hu", &newCourse->time_slot);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter student number: ");
    scanf("%hu", &newCourse->student_number);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Available Departments for the Course:\n");
    printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 1. CSE\n");
    printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 2. EEE\n");
    printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 3. Pharmacy\n");
    printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 4. Mathematical and Physical Sciences\n");
    printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 5. Non-elective Courses\n");
    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Select the departments (separated by commas): ");

    int departmentChoice;
    do
    {
        scanf("%d", &departmentChoice);
        newCourse->dept_course[departmentChoice - 1] = true;
    } while (getchar() == ',');

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter course credit: ");
    scanf("%f", &newCourse->course_credit);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter minimum credit required: ");
    scanf("%f", &newCourse->min_credit_required);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter department: ");
    scanf("%49s", newCourse->department);
    fflush(stdin);

    newCourse->students_list = NULL;
    newCourse->allocated_faculty = NULL;

    // add(courseList, newCourse);

    FILE *file = fopen("../Sources/db/Course_data.dat", "ab");
    if (file != NULL)
    {
        fwrite(newCourse, sizeof(Course), 1, file);
        fclose(file);
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Error opening file for writing!\n");
    }
}

void printCourseData()
{
    system("@cls||clear");
    FILE *file = fopen("../Sources/db/Course_data.dat", "rb");
    if (file != NULL)
    {
        Course *course = (Course *)malloc(sizeof(Course));

        while (fread(course, sizeof(Course), 1, file) == 1)
        {
            printf("\n\n\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Course ID: %s\n", course->course_id);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Course Name: %s\n", course->course_name);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Course Code: %d\n", course->course_code);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Section: %d\n", course->section);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Time Slot: %d\n", course->time_slot);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Student Number: %d\n", course->student_number);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Course Credit: %.2f\n", course->course_credit);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Minimum Credit Required: %.2f\n", course->min_credit_required);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Department: %s\n", course->department);

            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Available Departments for the Course:\n");
            printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 1. CSE: %s\n", course->dept_course[0] ? "Yes" : "No");
            printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 2. EEE: %s\n", course->dept_course[1] ? "Yes" : "No");
            printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 3. Pharmacy: %s\n", course->dept_course[2] ? "Yes" : "No");
            printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 4. Mathematical and Physical Sciences: %s\n", course->dept_course[3] ? "Yes" : "No");
            printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 5. Non-elective Courses: %s\n", course->dept_course[4] ? "Yes" : "No");

            if (course->allocated_faculty != NULL)
            {
                printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Allocated Faculty: %s\n", course->allocated_faculty->username);
            }
            else
            {
                printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Allocated Faculty: None\n");
            }
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Students List:\n");
            if (course->students_list == NULL)
            {
                printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 No students enrolled.\n");
            }
            else
            {
                for (uint16_t i = 0; i < course->student_number; ++i)
                {
                    printf("- %s\n", course->students_list[i].username);
                }
            }

            printf("\n");
        }

        fclose(file);
    }
    else
    {
        printf("Error opening file for reading!\n");
    }
}

void addDepartmentData()
{
    system("@cls||clear");
    Department *newDepartment = (Department *)malloc(sizeof(Department));

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter department ID: ");
    scanf("%49s", newDepartment->dept_id);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter department name: ");
    scanf("%49s", newDepartment->name);
    fflush(stdin);

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter chairperson name: ");
    scanf("%49s", newDepartment->chairperson);
    fflush(stdin);

    newDepartment->courses = NULL;
    newDepartment->course_count = 0;
    newDepartment->faculties = NULL;
    newDepartment->faculty_count = 0;
    newDepartment->students = NULL;
    newDepartment->student_count = 0;

    // add(Info, newDepartment);

    FILE *file = fopen("../Sources/db/Department_data.dat", "ab");
    if (file != NULL)
    {
        fwrite(newDepartment, sizeof(Department), 1, file);
        fclose(file);
    }
    else
    {
        printf("Error opening file for writing!\n");
    }
}

void printDepartmentData()
{
    system("@cls||clear");
    FILE *file = fopen("../Sources/db/Department_data.dat", "rb");
    if (file != NULL)
    {
        Department *department = (Department *)malloc(sizeof(Department));

        while (fread(department, sizeof(Department), 1, file) == 1)
        {
            printf("\n\n\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Department ID: %s\n", department->dept_id);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Department Name: %s\n", department->name);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Chairperson: %s\n", department->chairperson);
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Courses Count: %d\n", department->course_count);

            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Courses:\n");
            for (uint16_t i = 0; i < department->course_count; ++i)
            {
                printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 Course ID: %s\n", department->courses[i].course_id);
                printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 Course Name: %s\n", department->courses[i].course_name);
            }

            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculties:\n");
            for (uint16_t i = 0; i < department->faculty_count; ++i)
            {
                printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Username: %s\n", department->faculties[i].username);
                printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 Faculty Name: %s\n", department->faculties[i].name);
            }

            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Students:\n");
            for (uint16_t i = 0; i < department->student_count; ++i)
            {
                printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 Student Username: %s\n", department->students[i].username);
                printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 Student Name: %s\n", department->students[i].name);
            }
        }

        fclose(file);
        free(department);
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\t\xDB\xDB\xB2 Error opening file for reading!\n");
    }
}

void addCourseToStudent(char *username)
{
    system("@cls||clear");
    FILE *studentFile = fopen("../Sources/db/student_data.dat", "r+b");
    FILE *courseFile = fopen("../Sources/db/Course_data.dat", "rb");

    // char inputUsername[MAX_LENGTH];
    // printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter student username to view available courses: ");
    // scanf("%49s", inputUsername);

    Student student;
    bool studentFound = false;

    while (fread(&student, sizeof(Student), 1, studentFile) == 1)
    {
        if (strcmp(student.username, username) == 0)
        {
            studentFound = true;
            break;
        }
    }

    if (!studentFound)
    {
        printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Student not found with the given username: %s\n", username);
        fclose(studentFile);
        fclose(courseFile);
        return;
    }

    bool departmentHasCourses = false;

    fseek(courseFile, 0, SEEK_SET);
    Course course;

    printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 %-12s | %-12s | %-10s\n", "Course ID", "Course Name", "Course Credit");
    printf("\n\t\t\t\t\t\t\t------------------------------------------\n");
    while (fread(&course, sizeof(Course), 1, courseFile) == 1)
    {
        if (
            (strcmp(student.department, "CSE") == 0 && course.dept_course[0]) ||
            (strcmp(student.department, "EEE") == 0 && course.dept_course[1]) ||
            (strcmp(student.department, "Pharmacy") == 0 && course.dept_course[2]) ||
            (strcmp(student.department, "Mathematical and Physical Sciences") == 0 && course.dept_course[3]) ||
            (strcmp(student.department, "Non-Elective") == 0 && course.dept_course[4]))
        {
            printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2   %-12s | %-12s | %-10.2f\n", course.course_id, course.course_name, course.course_credit);
            // printf("\n");
            departmentHasCourses = true;
        }
    }

    if (!departmentHasCourses)
    {
        printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 No courses available for your department.\n");
        return;
    }

    int depIndex = -1;

    for (int i = 0; i < 5; ++i)
    {
        if (student.std_dep[i])
        {
            depIndex = i;
            break;
        }
    }

    int courseCount = 0;
    const int MAX_CURRENT_COURSES = 5;

    while (courseCount < 5)
    {
        printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Enter Course ID %d: ", courseCount + 1);
        char selectedCourseID[MAX_LENGTH];
        scanf("%49s", selectedCourseID);

        if (strcmp(selectedCourseID, "done") == 0)
        {
            if (courseCount < 3)
            {
                printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Minimum %d courses need to be selected.\n", 3);
            }
            else
            {
                break;
            }
        }
        else
        {
            bool found = false;

            fseek(courseFile, 0, SEEK_SET);
            while (fread(&course, sizeof(Course), 1, courseFile) == 1)
            {
                if (depIndex != -1 && course.dept_course[depIndex] && strcmp(course.course_id, selectedCourseID) == 0)
                {
                    if (student.num_current_courses < MAX_CURRENT_COURSES)
                    {
                        student.current_semester_courses[student.num_current_courses++] = course;
                        found = true;
                        courseCount++;
                    }
                    else
                    {
                        printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Maximum number of courses reached for this semester.\n");
                        break;
                    }
                }
            }
            if (!found)
            {
                printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Course ID %s not found or not available for your department. Please try again.\n", selectedCourseID);
            }
        }
    }

    if (studentFound)
    {
        fseek(studentFile, -sizeof(Student), SEEK_CUR);
        fwrite(&student, sizeof(Student), 1, studentFile);
    }
    else
    {
        printf("\n\t\t\t\t\t\t\t\xDB\xDB\xB2 Student not found with the given username: %s\n", username);
    }

    fclose(studentFile);
    fclose(courseFile);
}


bool studentExist(char* username,char * password){
    FILE *file = fopen("../Sources/db/student_data.dat", "rb");
    if (file != NULL)
    {
        Student student;

        while (fread(&student, sizeof(Student), 1, file) == 1)
        {
            if (strcmp(student.username, username) == 0 && strcmp(student.password, password) == 0 )
            {
                fclose(file);
                return true;
            }
        }

        printf("Student with username %s not found.\n", username);
        fclose(file);
        return false;
    }
    else
    {
        printf("Error opening file for reading!\n");
        return false;
    }
}


