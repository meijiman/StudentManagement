cmake_minimum_required(VERSION 3.23)
project(StudentManagement C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(StudentManagement
        FileManagement.c
        FileManagement.h
        main.c
        SearchStudent.c
        SearchStudent.h
        SortStudent.c
        SortStudent.h
        StudentManagement.c
        StudentManagement.h
        UI.c
        UI.h
        Util.c
        Util.h)
