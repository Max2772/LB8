#pragma once
#include "task2.h"

using namespace std;

void saveDataBaseFromFile(Student2* dataBase, const int &dataBaseSize, int startIdx, const string& path = "Task2.dat");
Student2* loadDataBaseFromFileTask2(int& dataBaseSize, const std::string& path = "Task2.dat");
