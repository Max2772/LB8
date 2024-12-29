#pragma once
#include "task2.h"

using namespace std;
Student2* addElement(Student2 *dataBase, int &dataBaseSize, const Student2 &x);
Student2* deleteElement(Student2 *dataBase, int &dataBaseSize, const int &index);
void editElement(Student2 *dataBase, int idx);
Student2* editList(Student2 *dataBase, int &dataBaseSize);
