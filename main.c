/*
 * main.c
 *
 *  Created on: Aug 9, 2022
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "FileManagement.h"
#include "StudentManagement.h"

int main() {
	fp = openFile();
	printMenu();
	closeFile(fp);
	return 0;
}
