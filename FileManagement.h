/*
 * FileManagement.h
 *
 *  Created on: Aug 16, 2022
 *      Author: root
 */

#include "StudentManagement.h"

#define FILENAME "data.bin"

#ifndef FILEMANAGEMENT_H_
#define FILEMANAGEMENT_H_

FILE *fp;

FILE *openFile();
void closeFile(FILE *fp);

#endif /* FILEMANAGEMENT_H_ */
