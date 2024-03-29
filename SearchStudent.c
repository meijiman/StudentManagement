/*
 * SearchStudent.c
 *
 *  Created on: Aug 16, 2022
 *      Author: root
 */

#include <stdio.h>
#include <string.h>
#include "SearchStudent.h"
#include "Util.h"
#include "FileManagement.h"
#include "StudentManagement.h"

void searchStudentByName() {
	clearScreen();
	printf("******* Search Student By Name *******\n");
	printf("Enter Name to search: ");

	char name[20];
	fflush(stdin);
	scanf("%[^\n]s", name);

	rewind(fp);

	int i = 1;
	printHeader();
	while (fread(&s, sizeof(Student), 1, fp)) {
		if (strcasestr(s.fullName, name)) {
			printRecord(&s, i);
			i++;
		}
	}
	pauseScreen();
}

void searchStudentByYearOfBirth() {
	clearScreen();
	printf("******* Search Student By Year Of Birth *******\n");
	printf("Enter Year of Birth to search: ");

	int year;
	fflush(stdin);
	scanf("%d", &year);

	rewind(fp);

	int i = 1;
	printHeader();
	while (fread(&s, sizeof(Student), 1, fp)) {
		if (s.yearOfBirth == year) {
			printRecord(&s, i);
			i++;
		}
	}
	pauseScreen();
}
