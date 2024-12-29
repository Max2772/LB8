#pragma once
#include <iostream>

typedef struct Student{
    std::string FIO;
    int group;
    double averageMark;
    union{
    double d;
    int i;
    } familyIncome;
    bool lgoti;
} Student;

void task1();


