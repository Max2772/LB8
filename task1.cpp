#include <iostream>
#include "head.h"

/*                                If you want to run and debug in IDE uncomment this
#include "input.cpp"
#include "array_utils.cpp"
#include "logic.cpp"
#include "output.cpp"
#include "search_sort.cpp"
#include "string_utils.cpp"
#include "struct_input.cpp"
#include "file_utils.cpp"
*/


using namespace std;

int main(){
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
                return 0;

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
    return 0;
}