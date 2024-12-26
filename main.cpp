#include <iostream>
#include "general/header-files/funcs.h"
#include "general/header-files/constants.h"
// includes for Tasks
#include "./Task_1/header-files/task1.h"
#include "./Task_2/header-files/task2.h"

using std::cout;
using std::cin;

int main(){
    cout << "#########################################################################LABWORK8#########################################################################\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = getIntegerForType();
        if(type == 2){
            break;
        }
        else if(type != 1 && type != 2){
            continue;
        }
        
        cout << "Выберите задание для запуска:\n";
        cout << "Задание 1(Введите 1)\n";
        cout << "Задание 2(Введите 2)\n";
        cout << "Ввод: ";
        int choice = getIntegerForChoice();
        switch(choice){
            case 1:
                task1();
                std::cin.ignore();
                continue;
            case 2:
                task2();
                std::cin.ignore();
                continue;
        }

    }
    return 0;
}