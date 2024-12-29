#pragma once
#include "constants.h"
#include <iostream>

using namespace std;

int readCharToStringForType(char* input);
int readCharToStringForChoice(char* input);
string newStringInInterval(const string &str, const int & end);
string russianStringToLower(const string &str);

inline bool findInArray(int* resIndexes, const int &size, const int &x){
    for(int i = 0; i < size; ++i){
        if(resIndexes[i] == x)
            return true;
    }
    return false;
};

inline int charToInteger(char* type){  
    return *type - '0';
};

inline void delete1DMatrix(char* mtrx){
        delete [] mtrx;
        mtrx = NULL;
};

inline int getIntegerForType(){
        char* type = new char[80];
        while(readCharToStringForType(type) == -INF);
        int type_int = charToInteger(type);
        delete1DMatrix(type);
        return type_int;
};

inline int getIntegerForChoice(){
        char* choice = new char[80];
        while(readCharToStringForChoice(choice) == -INF);
        int choice_int = charToInteger(choice);
        delete1DMatrix(choice);
        return choice_int;
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


