#pragma once
#include "task1.h"
using namespace std;

Student* addElement(Student *dataBase, int &dataBaseSize, const Student &x);
Student* deleteElement(Student *dataBase, int &dataBaseSize, const int &index);
void editElement(Student *dataBase, int idx);
Student* editList(Student *dataBase, int &dataBaseSize);
