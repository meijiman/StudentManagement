/*
 * UI.c
 *
 *  Created on: Aug 16, 2022
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "SearchStudent.h"
#include "SortStudent.h"
#include "StudentManagement.h"
#include "FileManagement.h"
#include "Util.h"

void printMenu(FILE *fp) {
	int choice;
	while (1) {
		clearScreen();
		printf("Welcome to Student Management System!\n");
		printf("1. Add student\n");
		printf("2. Remove student\n");
		printf("3. Modify student\n");
		printf("4. Search student by name\n");
		printf("5. Sort student by name\n");
		printf("6. Display students\n");
		printf("7. Create sample data\n");
		printf("8. Cleanup data\n");
		printf("9. Sort student by year of birth\n");
		printf("0. Exit\n");
		printf("\n");
		printf("Enter your choice: ");
		fflush(stdin);
		scanf("%d", &choice);
		switch(choice) {
		case 1:
			addStudent();
			break;
		case 2:
			removeStudent();
			break;
		case 3:
			modifyStudent();
			break;
		case 4:
			searchStudentByName();
			break;
		case 5:
			sortStudentByName();
			break;
		case 6:
			displayStudents();
			break;
		case 7:
			createSampleData();
			break;
		case 8:
			cleanupData();
			break;
		case 9:
			sortStudentByYearOfBirth();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Invalid choice!\n");
			pauseScreen();
		}
	}
}
