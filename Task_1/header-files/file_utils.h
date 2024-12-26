#pragma once
#include "task1.h"

using namespace std;

void saveDataBaseFromFile(Student* dataBase, const int &dataBaseSize, int startIdx, const string& path = "Task1.dat");
Student* loadDataBaseFromFileTask1(int& dataBaseSize, const string& path);

