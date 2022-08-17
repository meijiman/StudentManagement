/*
 * Student.c
 *
 *  Created on: Aug 16, 2022
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include "StudentManagement.h"
#include "FileManagement.h"
#include "Util.h"

void addStudent() {
	clearScreen();
	printf("******* Add new student *******\n");
	printf("Enter Student ID: ");
	fflush(stdin);

	int id;
	scanf("%d", &id);

	int found = isExist(id);
	if (found == 0) {
		s.id = id;
		printf("Enter Full Name: ");
		fflush(stdin);
		scanf("%[^\n]s", s.fullName);

		printf("Enter Year of Birth: ");
		scanf("%d", &s.yearOfBirth);

		printf("Enter Place of Birth: ");
		fflush(stdin);
		scanf("%[^\n]s", s.placeOfBirth);

		printf("Enter Department: ");
		fflush(stdin);
		scanf("%[^\n]s", s.department);

		printf("Enter Major: ");
		fflush(stdin);
		scanf("%[^\n]s", s.major);

		printf("Enter Entry Score: ");
		fflush(stdin);
		scanf("%f", &s.entryScore);

		printf("Enter GPA: ");
		fflush(stdin);
		scanf("%f", &s.gpa);

		printf("\n\n");
		printf("Added successfully!\n");
		printf("\n\n");

		printHeader();

		printRecord(&s, 1);

		fwrite(&s, sizeof(Student), 1, fp);
	} else {
		printf("Record existed!");
	}
	pauseScreen();
}

void removeStudent() {
	clearScreen();
	printf("******* Remove student *******\n");
	printf("Enter Student ID to remove: ");
	fflush(stdin);

	int id;
	scanf("%d", &id);

	FILE *ft = fopen("temp.bin", "wb");
	rewind(fp);

	int found = 0;

	while (fread(&s, sizeof(Student), 1, fp)) {
		if (s.id == id) {
			found = 1;
			printf("Record to be removed:\n");
			printHeader();
			printRecord(&s, 1);
			break;
		}
	}

	if (found == 1) {
		rewind(fp);
		while (fread(&s, sizeof(Student), 1, fp)) {
			if (s.id != id) {
				fwrite(&s, sizeof(Student), 1, ft);
			}
		}

		fclose(fp);
		fclose(ft);

		remove(FILENAME);
		rename("temp.bin", FILENAME);

		fp = fopen(FILENAME, "r+b");

		printf("Removed successfully!");
	} else {
		printf("Record not found!");
	}

	pauseScreen();
}

void modifyStudent() {
	clearScreen();
	printf("******* Modify student *******\n");
	printf("Enter Student ID to modify: ");
	fflush(stdin);

	int id;
	scanf("%d", &id);

	int found = isExist(id);
	if (found == 1) {
		rewind(fp);
		while(fread(&s, sizeof(Student), 1, fp)) {
			if (s.id == id) {
				printf("Enter New Full Name (%s): ", s.fullName);
				fflush(stdin);
				scanf("%[^\n]s", s.fullName);

				printf("Enter New Year of Birth (%d): ", s.yearOfBirth);
				fflush(stdin);
				scanf("%d", &s.yearOfBirth);

				printf("Enter New Place of Birth (%s): ", s.placeOfBirth);
				fflush(stdin);
				scanf("%[^\n]s", s.placeOfBirth);

				printf("Enter New Department (%s): ", s.department);
				fflush(stdin);
				scanf("%[^\n]s", s.department);

				printf("Enter New Major (%s): ", s.major);
				fflush(stdin);
				scanf("%[^\n]s", s.major);

				printf("Enter Entry Score (%.2f): ", s.entryScore);
				fflush(stdin);
				scanf("%f", &s.entryScore);

				printf("Enter GPA (%.2f): ", s.gpa);
				fflush(stdin);
				scanf("%f", &s.gpa);
				break;
			}
		}
		printf("\n\n");
		printf("Modified successfully!\n");
		printf("\n\n");
		printHeader();
		printRecord(&s, 1);
		fseek(fp, -sizeof(Student), SEEK_CUR);
		fwrite(&s, sizeof(Student), 1, fp);
	} else {
		printf("Record not found!\n");
	}
	pauseScreen();
}

void displayStudents() {
	clearScreen();
	rewind(fp);
	printHeader();
	int i = 1;
	while(fread(&s, sizeof(Student), 1, fp)) {
		printRecord(&s, i);
		i++;
	}
	pauseScreen();
}

void createSampleData() {
	Student s1 = {2020600, "Barzdukas Gytis", 2005, "Alabama", "Engineering", "Electronic", 25.0, 2.95};
	fwrite(&s1, sizeof(Student), 1, fp);

	Student s2 = {2020601, "Justice Peggy", 2001, "Alaska", "Science", "Biology", 20.0, 3.17};
	fwrite(&s2, sizeof(Student), 1, fp);

	Student s3 = {2020602, "Li Yan", 2002, "California", "Economics", "Finance", 21.0, 2.5};
	fwrite(&s3, sizeof(Student), 1, fp);

	Student s4 = {2020603, "Norman Laura", 2003, "Colorado", "Engineering", "Mechanical", 19.5, 3.0};
	fwrite(&s4, sizeof(Student), 1, fp);

	Student s5 = {2020604, "Olivotto Nino", 2005, "Florida", "Engineering", "Biomedical", 26.5, 2.8};
	fwrite(&s5, sizeof(Student), 1, fp);

	Student s6 = {2020605, "Tang Wayne", 2005, "Georgia", "Business", "Accounting", 28.25, 3.2};
	fwrite(&s6, sizeof(Student), 1, fp);

	Student s7 = {2020606, "Alonso Meredith", 2002, "Hawaii", "Education", "Mathematics", 24.75, 2.5};
	fwrite(&s7, sizeof(Student), 1, fp);

	Student s8 = {2020607, "Lopez Sophia", 2004, "Kansas", "Science", "Biochemistry", 23.5, 3.4};
	fwrite(&s8, sizeof(Student), 1, fp);

	Student s9 = {2020608, "Browning Meredith", 2000, "Michigan", "Education", "Chemistry", 20.5, 3.9};
	fwrite(&s9, sizeof(Student), 1, fp);

	Student s10 = {2020609, "Anand Arturo", 2003, "New York", "Education", "Physics", 18.75, 2.1};
	fwrite(&s10, sizeof(Student), 1, fp);
}

void cleanupData() {
	closeFile(fp);
	remove(FILENAME);
	openFile(FILENAME);
	printf("Cleanup data successfully!\n");
	pauseScreen();
}

int isExist(int id) {
	int found = 0;
	rewind(fp);
	while (fread(&s, sizeof(Student), 1, fp)) {
		if (s.id == id) {
			found = 1;
			break;
		}
	}
	return found;
}

