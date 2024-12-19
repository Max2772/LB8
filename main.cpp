#include <iostream>
#include "tests/head.h"
#include "tests/funcs.cpp"

using namespace std;

int main(){
    cout << "Введите миниальную зарплату в рублях 2024 год: ";
    double minIncome = readDoubleInLine();
    while ((minIncome <= 0)) {
        if(minIncome != -INF)
            cout << "Некорректный ввод! Введите натуральное число: ";

        minIncome = readDoubleInLine();
    }

    
    while(true){
        printMenu();
        int choice = readIntegerInLine();
        while(choice < 0 || choice > 6){
            if(choice != -INF)
                cout << "Некорректный ввод! Введите опцию из списка!\n";
            choice = readIntegerInLine();
        }
        switch(choice){
            case 0:
                return 0;
            case 1:
                Student* dataBase = inputStudents();
                break;
            
        }
    }
    return 0;
}