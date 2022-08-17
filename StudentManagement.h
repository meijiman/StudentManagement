/*
 * student.h
 *
 *  Created on: Aug 16, 2022
 *      Author: root
 */

#define MAX_FULLNAME 20
#define MAX_PLACE_OF_BIRTH 20
#define MAX_DEPARTMENT 20
#define MAX_MAJOR 20

#ifndef STUDENTMANAGEMENT_H_
#define STUDENTMANAGEMENT_H_

typedef struct student {
	int id;
	char fullName[MAX_FULLNAME];
	int yearOfBirth;
	char placeOfBirth[MAX_PLACE_OF_BIRTH];
	char department[MAX_DEPARTMENT];
	char major[MAX_MAJOR];
	float entryScore;
	float gpa;
} Student;

Student s;

void addStudent();
void removeStudent();
void modifyStudent();
void displayStudents();
void searchStudentByName();
void createSampleData();
void cleanupData();

#endif /* STUDENTMANAGEMENT_H_ */
