#ifndef PORTAL_SYSTEM_H
#define PORTAL_SYSTEM_H

// typedef struct Course Course;
// typedef struct Faculty Faculty;
// typedef struct Student Student;
// typedef struct Department Department;

// #include <stdint.h>
// #include <stdbool.h>
// typedef struct Student
// {
//     char *username; // Unique key!
//     char *password;
//     char *name;
//     uint16_t id;
//     char *department;
//     float completed_credit;
//     Course *current_semester_course;
//     Course *completed_courses;
//     char *advisor;
//     float cgpa;

// } Student;

// typedef struct Course
// {
//     char *course_id;
//     char *course_name;
//     uint16_t course_code;
//     char *allocated_faculty;
//     uint16_t section;
//     uint16_t time_slot;
//     uint16_t student_number;
//     float min_credit_required;
//     bool dept_course[5]; 
//     char *department;
//     Student *students_list;
// } Course;

// typedef struct Faculty
// {
//     char *username; // Unique key!
//     char *password;
//     char *name;
//     char *department;
//     char *allocated_courses;
//     char *designation;
//     char *educational_background;
// } Faculty;

// typedef struct Department
// {
//     char *dept_id;
//     char *name;
//     Course *courses;
//     uint16_t course_count;
//     Faculty *faculties;
//     uint16_t faculty_count;
//     char *chairperson;
//     Student *students;
//     uint16_t student_count;
// } Department;

typedef struct Course Course;
typedef struct Faculty Faculty;
typedef struct Student Student;
typedef struct Department Department;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_LENGTH 50
#define MAX_COURSES 5

typedef struct Course
{
    char course_id[MAX_LENGTH];
    char course_name[MAX_LENGTH];
    uint16_t  course_code;
    Faculty *allocated_faculty;
    uint16_t  section;
    uint16_t  time_slot;
    uint16_t  student_number;
    float  course_credit;
    float min_credit_required;
    bool dept_course[5]; 
    char department[MAX_LENGTH];
    Student *students_list;
} Course;

typedef struct Student
{
    char username[MAX_LENGTH]; // Unique key!
    char password[MAX_LENGTH];
    char name[MAX_LENGTH];
    uint16_t  id;
    char department[MAX_LENGTH];
    float completed_credit;
    Course current_semester_courses[5];
    uint16_t num_current_courses;
    Course *completed_courses;
    char advisor[MAX_LENGTH];
    float cgpa;
    bool std_dep[5];
} Student;



typedef struct Faculty
{
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char name[MAX_LENGTH];
    char department[MAX_LENGTH];
    Course *allocated_courses;
    uint16_t  allocated_courses_count;
    char designation[MAX_LENGTH];
    char educational_background[MAX_LENGTH];
} Faculty;

typedef struct Department
{
    char dept_id[MAX_LENGTH];
    char name[MAX_LENGTH];
    Course *courses;
    uint16_t  course_count;
    Faculty *faculties;
    uint16_t  faculty_count;
    char chairperson[MAX_LENGTH];
    Student *students;
    uint16_t  student_count;
} Department;
// #define struct Student * stp
// #define struct Department * dtp
// #define struct Faculty * ftp
// #define struct Course * ctp

#endif