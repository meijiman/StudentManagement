/*
 * SortStudent.c
 *
 *  Created on: Aug 16, 2022
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SortStudent.h"
#include "FileManagement.h"
#include "Util.h"

void sortStudentByName() {
	clearScreen();
	printf("******* Sort Student By Name *******\n");
	rewind(fp);
	Student *pstudents = (Student *) malloc(sizeof(Student));
	int len = 1;
	while(fread(&s, sizeof(Student), 1, fp)) {
		pstudents = (Student *) realloc(pstudents, sizeof(Student) * len);
		pstudents[len - 1] = s;
		len++;
	}

	len--;

	Student temp;
	for(int i = 0; i < len; i++){
		for(int j = i + 1; j < len; j++){
			if(strcmp((pstudents + i)->fullName, (pstudents + j)->fullName) > 0){
			temp = *(pstudents + j);
			*(pstudents + j) = *(pstudents + i);
			*(pstudents + i) = temp;
		  }
		}
	}

	printHeader();
	for (int i = 0; i < len; i++) {
		printRecord(pstudents + i, i + 1);
	}

	pauseScreen();
}

void sortStudentByYearOfBirth() {
	clearScreen();
	printf("******* Sort Student By Year Of Birth *******\n");
	rewind(fp);
	Student *pstudents = (Student *) malloc(sizeof(Student));
	int len = 1;
	while(fread(&s, sizeof(Student), 1, fp)) {
		pstudents = (Student *) realloc(pstudents, sizeof(Student) * len);
		pstudents[len - 1] = s;
		len++;
	}

	len--;

	Student temp;
	for(int i = 0; i < len; i++){
		for(int j = i + 1; j < len; j++){
			if((pstudents + i)->yearOfBirth > (pstudents + j)->yearOfBirth){
			temp = *(pstudents + j);
			*(pstudents + j) = *(pstudents + i);
			*(pstudents + i) = temp;
		  }
		}
	}

	printHeader();
	for (int i = 0; i < len; i++) {
		printRecord(pstudents + i, i + 1);
	}

	pauseScreen();
}
