#pragma once
#define Student Student2

typedef struct Student{
    std::string FIO;
    double mark1;
    double mark2;
    double mark3;
    union{
    double d;
    int i;
    } mark4;
    double middleMark;
} Student;

void task2();


