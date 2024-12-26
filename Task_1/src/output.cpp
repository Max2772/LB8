#include <iostream>

#include "../header-files/task1.h"

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"

void printMenu(){
        cout << "\n\t\t\tМеню Задание 1\n";
        cout << "1 - Создание списка студентов\n"; 
        cout << "2 - Просмотр списка\n";
        cout << "3 - Поиск студента по ФИО\n"; 
        cout << "4 - Редактирование списка\n"; 
        cout << "5 - Сортировать по доходу на члена семьи\n"; 
        cout << "6 - Вывести студентов, доход на члена семьи которых < 2 минимальных зарплат\n"; 
        cout << "7 - Автоматическое заполнение данных(Для отладки)\n"; 
        cout << "0 - Выход из Задания 1\n"; 
        cout << "Ввод: ";
}

void boolOutput(bool statement){
    cout << (statement ? "🗸" : "✘");
}

void showList(Student *dataBase, int size){
    cout << "\n№ | ФИО | Номер группы | Средний балл | Доход на члена семьи | Льготы\n";
    cout << "----------------------------------------------------------------------\n";
    for(int i = 0; i < size; ++i){
        cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].group << ", " << dataBase[i].averageMark <<
                    ", " << dataBase[i].familyIncome.d << " руб, "; boolOutput(dataBase[i].lgoti); cout << "\n";
    }
    cout << '\n';
}

void outputLessThanTwoIncome(Student *dataBase, int size, const int &minIncome){
    cout << "\nСтуденты с доходом на члена семьи меньше 2 минимальных зарплат(" << 2 * minIncome << " рублей):\n";
    bool found = false;
    for(int i = 0; i < size; ++i){
        if(dataBase[i].familyIncome.d < 2 * minIncome && !found){
           cout << "\n№ | ФИО | Номер группы | Средний балл | Доход на члена семьи | Льготы\n";
           cout << "----------------------------------------------------------------------\n";
           cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].group << ", " << dataBase[i].averageMark <<
                    ", " << dataBase[i].familyIncome.d << " руб, "; boolOutput(dataBase[i].lgoti); cout << "\n";
            found = true;
        }else if(dataBase[i].familyIncome.d < 2 * minIncome){
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].group << ", " << dataBase[i].averageMark <<
                ", " << dataBase[i].familyIncome.d << " руб, "; boolOutput(dataBase[i].lgoti); cout << "\n";   
        }
    }
    if(!found)
        cout << "Таковых студентов нет!\n";
    cout << '\n';
}