#pragma once

using namespace std;

typedef struct Student{
    string FIO;
    int group;
    double averageMark;
    union{
    double d;
    int i;
    } familyIncome;
    bool lgoti;
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
Student* autoInput(Student *dataBase, int &dataBaseSize);
Student* inputStudents(Student *dataBase, int &dataBaseSize);
void boolOutput(bool statement);

void saveDataBaseToBinary(Student* dataBase, const int& dataBaseSize, int startIdx, const string& path = "Task1.dat");
Student* loadDataBaseFromBinary(int& dataBaseSize, const string& path = "Task1.dat");
void removeWhiteSpacesFromFIO(Student* dataBase, const int &idx);
