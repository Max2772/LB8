#include <iostream>
#include "head.h"

//
#include "input.cpp"
#include "array_utils.cpp"
#include "logic.cpp"
#include "output.cpp"
#include "search_sort.cpp"
#include "string_utils.cpp"
#include "struct_input.cpp"

//

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

/*
    Student* dataBase = new Student[10] {
    {"Иванов Иван Сергеевич", 101, 4.5, 50000.75, true},
    {"Петрова Мария Алексеевна", 102, 3.8, 35000, false},
    {"Сидоров Алексей Викторович", 101, 4.2, 45000.5, true},
    {"Смирнова Ольга Дмитриевна", 103, 3.9, 40000, false},
    {"Фролов Сергей Владимирович", 102, 4.8, 52000.1, true},
    {"Иванова Анна Андреевна", 104, 4.1, 30000, false},
    {"Попов Дмитрий Олегович", 101, 3.7, 47000.3, true},
    {"Орлова Наталья Петровна", 103, 4.6, 38000, false},
    {"Козлов Игорь Александрович", 104, 4.4, 55000.9, true},
    {"Лебедева Елена Сергеевна", 102, 3.5, 32000, false}
};
    int dataBaseSize = 10; 
*/

    Student* dataBase = nullptr;
    int dataBaseSize = 0;
    while(true){
        waitForInput();
        printMenu();
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

                dataBase = inputStudents(dataBase, dataBaseSize);
                removeWhiteSpacesFromList(dataBase, dataBaseSize);
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
            
        }
    }
    if(dataBase != nullptr || dataBaseSize != 0){
        delete [] dataBase;
        dataBase = nullptr;
    }
    return 0;
}