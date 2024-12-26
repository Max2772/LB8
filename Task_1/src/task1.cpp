#include <iostream>

#include "../header-files/task1.h"
#include "../header-files/file_utils.h"
#include "../header-files/output.h"
#include "../header-files/struct_input.h"
#include "../header-files/search_sort.h"
#include "../header-files/array_utils.h"

#include "../../general/header-files/funcs.h"
#include "../../general/header-files/constants.h"


using namespace std;

void task1(){
    setlocale(LC_ALL, "");
    cout << "Введите миниальную зарплату в рублях 2024 год: ";
    double minIncome = readDoubleInLine();
    while ((minIncome <= 0)) {
        if(minIncome != -INF)
            cout << "Некорректный ввод! Введите натуральное число: ";

        minIncome = readDoubleInLine();
    }

    
    Student* dataBase = nullptr;
    int dataBaseSize = 0;
    dataBase = loadDataBaseFromFile(dataBaseSize, "Task1.dat");

    while(true){
        waitForInput();
        printMenu();
        int choice = readIntegerInLine();
        while(choice < 0 || choice > 7){
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
                return;

            case 1:
                dataBase = inputStudents(dataBase, dataBaseSize);
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
                sortByMinIncome(dataBase, dataBaseSize);
                break;
            case 6:
                outputLessThanTwoIncome(dataBase, dataBaseSize, minIncome);
                break;
            case 7:
                dataBase = autoInput(dataBase, dataBaseSize);
                break;
            
        }
    }
    if(dataBase != nullptr || dataBaseSize != 0){
        delete [] dataBase;
        dataBase = nullptr;
    }
    return;
}