#ifndef STRUCTURE_H
#define STRUCTURE_H



typedef struct Course Course;
typedef struct Faculty Faculty;
typedef struct Student Student;
typedef struct Department Department;



typedef struct Student
{
    char *username; // Unique key!
    char *password;
    char *name;
    int id;
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
    int course_code;
    char *allocated_faculty;
    int section;
    int time_slot;
    int student_number;
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
    int course_count;
    Faculty *faculties;
    int faculty_count;
    char *chairperson;
    Student *students;
    int student_count;
} Department;

// #define struct Student * stp
// #define struct Department * dtp
// #define struct Faculty * ftp
// #define struct Course * ctp

#endif