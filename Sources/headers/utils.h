#ifndef UTILS_H
#define UTILS_H

void addStudent(struct Personalized_DS *Info);

void addStudentData();

void printStudentData();

void addFacultyData();

void printFacultyData();

void addCourseData();

void printCourseData();

void addDepartmentData();

void printDepartmentData();

void addCourseToStudent(char *username);

void printSingleStudentInfo(char *username);

void StudentChangePassword(char *username);

bool studentExist(char* username,char * password);


#endif