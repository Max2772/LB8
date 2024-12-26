#pragma once
#include "task2.h"
#define Student Student2

using namespace std;

void saveDataBaseFromFile(Student* dataBase, const int &dataBaseSize, int startIdx, const string& path = "Task2.dat");
Student* loadDataBaseFromFileTask2(int& dataBaseSize, const std::string& path = "Task2.dat");

