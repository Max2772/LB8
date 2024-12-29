#pragma once
#include <iostream>
#include "task1.h"

using std::string;

void saveDataBaseToBinary(Student* dataBase, const int& dataBaseSize, int startIdx, const string& path = "Task1.bin");
Student* loadDataBaseFromBinary(int& dataBaseSize, const string& path = "Task1.bin");