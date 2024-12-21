#include <iostream>
#include "head.h"

int readIntegerInLine(){
    int number;
    if(!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод! Введите заново: ";
        return -INF;
    }
    return number;
}

double readDoubleInLine(){
    double number;
    if(!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод! Введите заново: ";
        return -INF;
    }
    
    return number;
}

void waitForInput(){
    cout << "Нажмите ENTER, чтобы продолжить...";
    cin.ignore();
    cin.get();
}