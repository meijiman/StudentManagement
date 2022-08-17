/*
 * Util.c
 *
 *  Created on: Aug 17, 2022
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "StudentManagement.h"

void clearScreen() {
	system("clear");
}

void pauseScreen() {
	printf("\n\n");
	printf("Press any key to back to main menu ...");
	fflush(stdin);
	getchar();
}

void printHeader() {
	printf("====================================================================================================================================================\n");
	printf("%-5s %-10s %-20s %-20s %-20s %-20s %-20s %-20s %-20s\n", "", "ID", "FULLNAME", "YEAR OF BIRTH", "PLACE OF BIRTH", "DEPARTMENT", "MAJOR", "ENTRY SCORE", "GPA");
	printf("====================================================================================================================================================\n");
}

void printRecord(Student *pstudent, int no) {
	printf("%-5d %-10d %-20s %-20d %-20s %-20s %-20s %-20.2f %-20.2f\n", no, pstudent->id, pstudent->fullName, pstudent->yearOfBirth, pstudent->placeOfBirth, pstudent->department, pstudent->major, pstudent->entryScore, pstudent->gpa);
}
