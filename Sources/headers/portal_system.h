#ifndef PORTAL_SYSTEM_H
#define PORTAL_SYSTEM_H

typedef struct Course Course;
typedef struct Faculty Faculty;
typedef struct Student Student;
typedef struct Department Department;

#include <stdint.h>
#include <stdbool.h>
typedef struct Student
{
    char *username; // Unique key!
    char *password;
    char *name;
    uint16_t id;
    char *department;
    float completed_credit;
    Course *current_semester_course;
    Course *completed_courses;
    char *advisor;
    float cgpa;

} Student;

typedef struct Course
{
    char *course_id;
    char *course_name;
    uint16_t course_code;
    char *allocated_faculty;
    uint16_t section;
    uint16_t time_slot;
    uint16_t student_number;
    float min_credit_required;
    bool dept_course[5]; 
    char *department;
    Student *students_list;
} Course;

typedef struct Faculty
{
    char *username; // Unique key!
    char *password;
    char *name;
    char *department;
    char *allocated_courses;
    char *designation;
    char *educational_background;
} Faculty;

typedef struct Department
{
    char *dept_id;
    char *name;
    Course *courses;
    uint16_t course_count;
    Faculty *faculties;
    uint16_t faculty_count;
    char *chairperson;
    Student *students;
    uint16_t student_count;
} Department;

// #define struct Student * stp
// #define struct Department * dtp
// #define struct Faculty * ftp
// #define struct Course * ctp

#endif