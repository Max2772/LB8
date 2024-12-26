#pragma once
#include "task2.h"
#define Student Student2

using namespace std;
Student* addElement(Student *dataBase, int &dataBaseSize, const Student &x);
Student* deleteElement(Student *dataBase, int &dataBaseSize, const int &index);
void editElement(Student *dataBase, int idx);
Student* editList(Student *dataBase, int &dataBaseSize);
