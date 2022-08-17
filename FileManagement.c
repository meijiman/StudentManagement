/*
 * FileManagement.c
 *
 *  Created on: Aug 16, 2022
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include "FileManagement.h"

FILE *openFile(void) {
	FILE *fp = fopen(FILENAME, "r+b");
	if (fp == NULL) {
		fp = fopen(FILENAME, "w+b");
		if (fp == NULL) {
			printf("Cannot open file!");
			exit(1);
		}
	}
	return fp;
}

void closeFile(FILE *fp) {
	fclose(fp);
}
