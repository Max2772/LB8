#pragma once

using namespace std;

typedef struct{
    string FIO;
    int group;
    double averageMark;
    double familyIncome;
} Student;


constexpr const int INF = 2000000000;
int readIntegerInLine();
double readDoubleInLine();
int determineGroup(const double &averageMark);
Student* addElement(Student *dataBase, int &dataBaseSize, const Student &x);
Student* deleteElement(Student *dataBase, int &dataBaseSize, const int &index);
bool findInArray(int* resIndexes, const int &size, const int &x);
int findInListForIndex(Student *dataBase, const int &dataBaseSize);
string newStringInInterval(const string &str, const int & end);
void removeWhiteSpacesFromList(Student *dataBase, const int &dataBaseSize);
void printMenu();
void outputLessThanTwoIncome(Student *dataBase, int size, const int &minIncome);
void editElement(Student *dataBase, int idx);
Student* editList(Student *dataBase, int &dataBaseSize);
string russianStringToLower(const string &str);
void findInList(Student *dataBase, const int &dataBaseSize);
void showList(Student *dataBase, int size);
void swapStruct(Student &a, Student &b);
void sortByMinIncome(Student *a, const int &dataBasesize);
void waitForInput();
Student* inputStudents(Student *dataBase, int &dataBaseSize);
