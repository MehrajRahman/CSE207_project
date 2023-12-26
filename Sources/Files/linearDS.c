
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/portal_system.h"
#include "../headers/LinearDS.h"
#include "../headers/logger.h"


static struct logger* l=NULL;

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

struct Node *createNode(void *data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode)
    {
        newNode->dataPtr = data;
        newNode->next = NULL;
    }
    return newNode;
}

struct Personalized_DS *Singly_LL()
{
    struct Personalized_DS *list = (struct Personalized_DS *)malloc(sizeof(struct Personalized_DS));
    if (list)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    return list;
}

void add(struct Personalized_DS *Info, void *data)
{
    struct Node *newNode = createNode(data);
    if (newNode)
    {
        if (Info->head == NULL)
        {
            Info->head = Info->tail = newNode;
        }
        else
        {
            Info->tail->next = newNode;
            Info->tail = newNode;
        }
    }
}

void addStudentData(struct Personalized_DS *Info)
{
    char username[50];
    char password[50];
    char name[50];
    int id;
    char department[50];
    float completed_credit;
    char advisor[50];
    float cgpa;

    log_print(l, "Enter student username: ");
    scanf("%s", username);

    log_print(l, "Enter student password: ");
    scanf("%s", password);

    log_print(l, "Enter student name: ");
    scanf("%s", name);
    fflush(stdin);

    log_print(l, "Enter student ID: ");
    scanf("%d", &id);

    log_print(l, "Enter student department: ");
    scanf("%s", department);
    fflush(stdin);

    log_print(l, "Enter completed credit hours: ");
    scanf("%f", &completed_credit);

    Course *current_semester_course = NULL;
    Course *completed_courses = NULL;

    log_print(l, "Enter student advisor: ");
    scanf("%s", advisor);

    log_print(l, "Enter student CGPA: ");
    scanf("%f", &cgpa);

    Student *newStudent = (Student *)malloc(sizeof(Student));

    newStudent->username = strdup(username);
    newStudent->password = strdup(password);
    newStudent->name = strdup(name);
    newStudent->id = id;
    newStudent->department = strdup(department);
    newStudent->completed_credit = completed_credit;
    newStudent->current_semester_course = current_semester_course;
    newStudent->completed_courses = completed_courses;
    newStudent->advisor = strdup(advisor);
    newStudent->cgpa = cgpa;

    add(Info, newStudent);
}

void addFacultyData(struct Personalized_DS *Info)
{
    char username[50];
    char password[50];
    char name[50];
    char department[50];
    char *designation;

    log_print(l, "Enter faculty username: ");
    scanf("%s", username);

    log_print(l, "Enter faculty password: ");
    scanf("%s", password);

    log_print(l, "Enter faculty name: ");
    scanf("%s", name);

    log_print(l, "Enter faculty department: ");
    scanf("%s", department);

    log_print(l, "Enter faculty designation: ");
    scanf("%s", designation);

    Faculty *newFaculty = (Faculty *)malloc(sizeof(Faculty));

    newFaculty->username = strdup(username);
    newFaculty->password = strdup(password);
    newFaculty->name = strdup(name);
    newFaculty->department = strdup(department);
    newFaculty->designation = strdup(designation);

    add(Info, newFaculty);
}

void addCourseData(struct Personalized_DS *courseList)
{
    char course_id[50];
    char course_name[50];
    int course_code;
    char allocated_faculty[50];
    int section;
    int time_slot;
    int student_number;
    char department[50];

    log_print(l, "Enter course ID: ");
    scanf("%s", course_id);

    log_print(l, "Enter course name: ");
    scanf("%s", course_name);

    log_print(l, "Enter course code: ");
    scanf("%d", &course_code);

    log_print(l, "Enter allocated faculty: ");
    scanf("%s", allocated_faculty);

    log_print(l, "Enter section: ");
    scanf("%d", &section);

    log_print(l, "Enter time slot: ");
    scanf("%d", &time_slot);

    log_print(l, "Enter student number: ");
    scanf("%d", &student_number);

    log_print(l, "Enter department: ");
    scanf("%s", department);

    Course *newCourse = (Course *)malloc(sizeof(Course));

    newCourse->course_id = strdup(course_id);
    newCourse->course_name = strdup(course_name);
    newCourse->course_code = course_code;
    newCourse->allocated_faculty = strdup(allocated_faculty);
    newCourse->section = section;
    newCourse->time_slot = time_slot;
    newCourse->student_number = student_number;
    newCourse->department = strdup(department);
    newCourse->students_list = NULL;

    add(courseList, newCourse);
}

void addDepartmentData(struct Personalized_DS *Info)
{
    char dept_id[50];
    char name[50];
    Course *courses = NULL;
    int course_count = 0;
    Faculty *faculties = NULL;
    int faculty_count = 0;
    char chairperson[50];
    Student *students = NULL;
    int student_count = 0;

    log_print(l, "Enter department ID: ");
    scanf("%49s", dept_id);

    log_print(l, "Enter department name: ");
    scanf("%49s", name);

    log_print(l, "Enter chairperson name: ");
    scanf("%49s", chairperson);

    Department *newDepartment = (Department *)malloc(sizeof(Department));
    newDepartment->dept_id = strdup(dept_id);
    newDepartment->name = strdup(name);
    newDepartment->chairperson = strdup(chairperson);
    newDepartment->courses = courses;
    newDepartment->course_count = course_count;
    newDepartment->faculties = faculties;
    newDepartment->faculty_count = faculty_count;
    newDepartment->students = students;
    newDepartment->student_count = student_count;

    add(Info, newDepartment);
}

void addStudentToCourse(struct Personalized_DS *studentList, Course *course, int studentId)
{
    struct Node *current = studentList->head;
    Student *studentToAdd = NULL;

    while (current != NULL)
    {
        Student *currentStudent = (Student *)current->dataPtr;
        if (currentStudent->id == studentId)
        {
            studentToAdd = currentStudent;
            break;
        }
        current = current->next;
    }

    if (studentToAdd != NULL)
    {
        struct Node *newNode = createNode(studentToAdd);
        if (newNode)
        {
            if (course->students_list == NULL)
            {
                course->students_list = newNode;
            }
            else
            {
                struct Node *temp = course->students_list;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            log_print(l, "Student with ID %d added to the course.\n", studentId);
        }
        else
        {
            log_print(l, "Memory allocation failed.\n");
        }
    }
    else
    {
        log_print(l, "Student with ID %d not found.\n", studentId);
    }
}

void addFacultyToCourse(struct Personalized_DS *facultyList, Course *course, char *facultyUsername)
{
    struct Node *current = facultyList->head;
    Faculty *facultyToAdd = NULL;

    while (current != NULL)
    {
        Faculty *currentFaculty = (Faculty *)current->dataPtr;
        if (strcmp(currentFaculty->username, facultyUsername) == 0)
        {
            facultyToAdd = currentFaculty;
            break;
        }
        current = current->next;
    }

    if (facultyToAdd != NULL)
    {
        struct Node *newNode = createNode(facultyToAdd);
        if (newNode)
        {
            if (course->allocated_faculty == NULL)
            {
                course->allocated_faculty = strdup(facultyUsername);
            }
            else
            {
                log_print(l, "This course already has a faculty assigned.\n");
            }
        }
    }
    else
    {
        log_print(l, "Faculty with username %s not found.\n", facultyUsername);
    }
}