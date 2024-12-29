#pragma once
#include <iostream>

typedef struct Student2{
    std::string FIO;
    double mark1;
    double mark2;
    double mark3;
    union{
    double d;
    int i;
    } mark4;
    double middleMark;
} Student2;

void task2();


