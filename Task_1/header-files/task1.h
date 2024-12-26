#pragma once

typedef struct Student1{
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


