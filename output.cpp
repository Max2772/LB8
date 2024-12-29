#include <iostream>
#include "head.h"

void printMenuTask2(){
        cout << "\n\t\t\tМеню Задание 2\n";
        cout << "1 - Создание списка студентов\n"; 
        cout << "2 - Просмотр списка\n";
        cout << "3 - Поиск студента по ФИО\n"; 
        cout << "4 - Редактирование списка\n"; 
        cout << "5 - Вывести студентов, средний балл которых выше по университету\n"; 
        cout << "6 - Автоматическое заполнение данных(Для отладки)\n"; 
        cout << "0 - Выход из Задания 2\n"; 
        cout << "Ввод: ";
}

void showList(Student2 *dataBase, int size){
    cout << "\n№ | ФИО | Математика | Язык | Физика | Аттестат | Средний\n";
    cout << "------------------------------------------------------------\n";
    for(int i = 0; i < size; ++i){
        cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].mark1 << ", " << dataBase[i].mark2 <<
                    ", " << dataBase[i].mark3 << ", " << dataBase[i].mark4.d << ", " << dataBase[i].middleMark << '\n';
    }
    cout << '\n';
}


void outputHigherMiddleUniversity(Student2 *dataBase, const int &dataBaseSize){
    double middleUniversity = getMiddleForList(dataBase, dataBaseSize);
    cout << "\nСтуденты с средним баллом выше среднего по университету(" << middleUniversity << " баллов):\n";
    bool found = false;
    for(int i = 0; i < dataBaseSize; ++i){ // Все на 5
        if(dataBase[i].middleMark == 5 && !found){
            found = true;
            cout << "\n№ | ФИО | Математика | Язык | Физика | Аттестат | Средний\n";
            cout << "------------------------------------------------------------\n";
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].mark1 << ", " << dataBase[i].mark2 <<
            ", " << dataBase[i].mark3 << ", " << dataBase[i].mark4.d << ", " << dataBase[i].middleMark << '\n';
        }else if(dataBase[i].middleMark == 5){
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].mark1 << ", " << dataBase[i].mark2 <<
            ", " << dataBase[i].mark3 << ", " << dataBase[i].mark4.d << ", " << dataBase[i].middleMark << '\n';
        }
    }

    for(int i = 0; i < dataBaseSize; ++i){ // Все выше среднего
        if(dataBase[i].middleMark > middleUniversity && dataBase[i].middleMark != 5 && !found){
            found = true;
            cout << "\n№ | ФИО | Математика | Язык | Физика | Аттестат | Средний\n";
            cout << "------------------------------------------------------------\n";
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].mark1 << ", " << dataBase[i].mark2 <<
            ", " << dataBase[i].mark3 << ", " << dataBase[i].mark4.d << ", " << dataBase[i].middleMark << '\n';
        }else if(dataBase[i].middleMark > middleUniversity && dataBase[i].middleMark != 5){
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].mark1 << ", " << dataBase[i].mark2 <<
            ", " << dataBase[i].mark3 << ", " << dataBase[i].mark4.d << ", " << dataBase[i].middleMark << '\n';
        }
    }

    if(!found)
        cout << "Таковых студентов нет!\n";
    cout << '\n';
}