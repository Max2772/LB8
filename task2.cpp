#include <iostream>
#include "head.h"

/*
#include "array_utils.cpp"
#include "logic.cpp"
#include "output.cpp"
#include "search_sort.cpp"
#include "string_utils.cpp"
#include "struct_input.cpp"
#include "file_utils.cpp"
#include "funcs.cpp"

*/

using namespace std;

int main(){
    setlocale(LC_ALL, "");
    cout << "\t\t\t\t|-----------------------------------------------------|\n"
            "\t\t\t\t| База данных абитуриентов, поступающих в БГУИР(2024) |\n"
            "\t\t\t\t|-----------------------------------------------------|\n\n\n";
    cin.putback('\n');
    
    Student2* dataBase = nullptr;
    int dataBaseSize = 0;
    dataBase = loadDataBaseFromFileTask2(dataBaseSize, "Task2.dat");

    while(true){
        waitForInput();
        printMenuTask2();
        int choice = readIntegerInLine();
        while(choice < 0 || choice > 6){
            if(choice != -INF)
                cout << "Некорректный ввод! Введите опцию из списка!\n";
            choice = readIntegerInLine();
        }
        switch(choice){
            case 0:
                if(dataBase != nullptr){
                    delete [] dataBase;
                    dataBase = nullptr;
                    dataBaseSize = 0;
                }
                return 0;

            case 1:
                dataBase = inputStudents2(dataBase, dataBaseSize);
                break;

            case 2:
                if(dataBase == nullptr || dataBaseSize == 0){
                    cout << "Список студентов пуст! Добавьте сначала студентов.\n";
                }else{
                    showList(dataBase, dataBaseSize);
                    }
                break;
            case 3:
                findInList(dataBase, dataBaseSize);
                break;
            case 4:
                dataBase = editList(dataBase, dataBaseSize);
                break;
            case 5:
                outputHigherMiddleUniversity(dataBase, dataBaseSize);
                break;
            case 6:
                dataBase = autoInput(dataBase, dataBaseSize);
                break;
            
        }
    }
    if(dataBase != nullptr || dataBaseSize != 0){
        delete [] dataBase;
        dataBase = nullptr;
    }
    return 0;
}