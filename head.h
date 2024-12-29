#pragma once
#include <iostream> 
using namespace std;

typedef struct Student2{
    std::string FIO;
    double mark1;
    double mark2;
    double mark3;
    union{
    double d;
    int i;
    } mark4;
    double middleMark;
} Student2;


constexpr const int INF = 2000000000;

Student2* addElement(Student2 *dataBase, int &dataBaseSize, const Student2 &x);
Student2* deleteElement(Student2 *dataBase, int &dataBaseSize, const int &index);
void editElement(Student2 *dataBase, int idx);
Student2* editList(Student2 *dataBase, int &dataBaseSize);

void saveDataBaseFromFile(Student2* dataBase, const int &dataBaseSize, int startIdx, const string& path = "Task2.dat");
Student2* loadDataBaseFromFileTask2(int& dataBaseSize, const std::string& path = "Task2.dat");

double getMiddle(const Student2 B);
double getMiddleForList(const Student2 *dataBase, const int &dataBaseSize);

void printMenuTask2();
void showList(Student2 *dataBase, int size);
void outputHigherMiddleUniversity(Student2 *dataBase, const int &dataBaseSize);

int findInListForIndex(Student2 *dataBase, const int &dataBaseSize);
void findInList(Student2 *dataBase, const int &dataBaseSize);

void removeWhiteSpacesFromList(Student2 *dataBase, const int &dataBaseSize);
void removeWhiteSpacesFromFIO(Student2* dataBase, const int &idx);

Student2* autoInput(Student2 *dataBase, int &dataBaseSize);
Student2* inputStudents2(Student2 *dataBase, int &dataBaseSize);

string newStringInInterval(const string &str, const int & end);
string russianStringToLower(const string &str);

string newStringInInterval(const string &str, const int & end);
string russianStringToLower(const string &str);

inline bool findInArray(int* resIndexes, const int &size, const int &x){
    for(int i = 0; i < size; ++i){
        if(resIndexes[i] == x)
            return true;
    }
    return false;
};

inline int readIntegerInLine(){
    int number;
    if(!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод! Введите заново: ";
        return -INF;
    }
    return number;
};

inline double readDoubleInLine(){
    double number;
    if(!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод! Введите заново: ";
        return -INF;
    }
    
    return number;
};

inline void waitForInput(){
    cout << "Нажмите ENTER, чтобы продолжить...";
    cin.ignore();
    cin.get();
};


