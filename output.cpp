#include <iostream>
#include "head.h"

void printMenu(){
        cout << "\n\t\t\tМеню Задание 1\n";
        cout << "1 - Создание списка студентов\n"; 
        cout << "2 - Просмотр списка\n";
        cout << "3 - Поиск студента по ФИО\n"; 
        cout << "4 - Редактирование списка\n"; 
        cout << "5 - Сортировать по доходу на члена семьи\n"; 
        cout << "6 - Вывести студентов, доход на члена семьи которых < 2 минимальных зарплат\n"; 
        cout << "0 - Выход из Задания 1\n"; 
        cout << "Ввод: ";
}

void showList(Student *dataBase, int size){
    cout << '\n';
    for(int i = 0; i < size; ++i){
        cout << dataBase[i].FIO << ", группа " << dataBase[i].group << " , средний балл: " << dataBase[i].averageMark <<
        " , доход на члена семьи " << dataBase[i].familyIncome << '\n';
    }
    cout << '\n';
}

void outputLessThanTwoIncome(Student *dataBase, int size, const int &minIncome){
    cout << "\nСтуденты с доходом на члена семьи меньше 2 минимальных зарплат(" << 2 * minIncome << " рублей):\n";
    bool found = false;
    for(int i = 0; i < size; ++i){
        if(dataBase[i].familyIncome < 2 * minIncome){
            cout << dataBase[i].FIO << ", группа " << dataBase[i].group << " , средний балл: " << dataBase[i].averageMark <<
            " , доход на члена семьи " << dataBase[i].familyIncome << '\n';
            found = true;
        }
    }
    if(!found)
        cout << "Таковых студентов нет!\n";
    cout << '\n';
}