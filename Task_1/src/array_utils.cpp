#include <iostream>

#include "../header-files/task1.h"
#include "../header-files/file_utils.h"
#include "../header-files/string_utils.h"
#include "../header-files/search_sort.h"
#include "../header-files/output.h"

#include "../../general/header-files/funcs.h"
#include "../../general/header-files/constants.h"

Student* addElement(Student *dataBase, int &dataBaseSize, const Student &x){
    Student *b = new Student[dataBaseSize + 1];
    for(int i = 0; i < dataBaseSize; ++i){
        b[i] = dataBase[i];
    }

    delete [] dataBase;

    b[dataBaseSize] = x;
    dataBaseSize++;
    return b;
}

Student* deleteElement(Student *dataBase, int &dataBaseSize, const int &index){
    Student *b = new Student[dataBaseSize - 1];
    int i = 0, j = 0;
    for(;i != index && i < dataBaseSize; ++i, ++j){
        b[j] = dataBase[i];
    }
    ++i;
    for(;i != index && i < dataBaseSize; ++i, ++j){
        b[j] = dataBase[i];
    }

    delete [] dataBase;
    dataBaseSize--;
    saveDataBaseToBinary(b, dataBaseSize, 0);
    return b;
}

void editElement(Student *dataBase, int idx){
    cout << dataBase[idx].FIO << ", группа " << dataBase[idx].group << ", средний балл: " << dataBase[idx].averageMark <<
                ", доход на члена семьи " << dataBase[idx].familyIncome.d << " руб, "; boolOutput(dataBase[idx].lgoti);
            cout << "\nПерепишите новые данные студента:\n";

            Student B;
            cout << "Введите новое ФИО студента: ";
            cin.ignore();
            getline(cin, B.FIO);
            cout << "Введите новый средний балл студента: ";
            B.averageMark = readDoubleInLine();
            while(B.averageMark < 0){
                if(B.averageMark != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.averageMark = readDoubleInLine();
            }
            cout << "Введите новый номер группы студента: ";
            B.group = readIntegerInLine();
            while(B.group < 0){
                if(B.group != -INF)
                    cout << "Некорректный ввод! Введите натуральное число: ";
                B.group = readIntegerInLine();
            }
            cout << "Введите новый доход на члена семьи студента: ";
            B.familyIncome.d = readDoubleInLine();
            while(B.familyIncome.d < 0){
                if(B.familyIncome.d != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.familyIncome.d = readDoubleInLine();
            }

            cout << "Есть ли льготы(y/n): ";
            string buffer; cin >> buffer;
            while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
                cout << "Введите только Y/y - да, N/n -нет: ";
                cin >> buffer;
            }
            if(buffer[0] == 'Y' || buffer[0] == 'y')
                B.lgoti = true;
            else
                B.lgoti = false;

            dataBase[idx] = B;
}


Student* editList(Student *dataBase, int &dataBaseSize){
    cout << "Введите + для добавления, - для удаления студента, * - для редактирования информации студента(+/-/*): ";
    string buffer; cin >> buffer;
    while(buffer != "+" && buffer != "-" && buffer != "*"){
        cout << "Введите только +, - или * : ";
        cin >> buffer;
    }
    if(buffer == "+"){
        Student B;
        cout << "Введите ФИО новго студента: ";
        cin.ignore();
        getline(cin, B.FIO);
        cout << "Введите средний балл нового студента: ";
        B.averageMark = readDoubleInLine();
        while(B.averageMark < 0){
            if(B.averageMark != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.averageMark = readDoubleInLine();
        }
        cout << "Введите номер группы нового студента: ";
        B.group = readIntegerInLine();
        while(B.group < 0){
            if(B.group != -INF)
                cout << "Некорректный ввод! Введите натуральное число: ";
            B.group = readIntegerInLine();
        }
        cout << "Введите доход на члена семьи нового студента: ";
        B.familyIncome.d = readDoubleInLine();
        while(B.familyIncome.d < 0){
            if(B.familyIncome.d != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.familyIncome.d = readDoubleInLine();
        }
        cout << "Есть ли льготы(y/n): ";
        string buffer; cin >> buffer;
        while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
            cout << "Введите только Y/y - да, N/n -нет: ";
            cin >> buffer;
        }
        if(buffer[0] == 'Y' || buffer[0] == 'y')
            B.lgoti = true;
        else
            B.lgoti = false;

        dataBase = addElement(dataBase, dataBaseSize, B);
        removeWhiteSpacesFromFIO(dataBase, dataBaseSize-1);
        saveDataBaseToBinary(dataBase, dataBaseSize, dataBaseSize-1);
        return dataBase;
    }else if(buffer == "-"){
        cout << "Введите ФИО студента для удаления из списка: ";
        int index = findInListForIndex(dataBase, dataBaseSize);
        if(index != -INF){
            dataBase = deleteElement(dataBase, dataBaseSize, index);
        }
        return dataBase;
    }else{
        cout << "Введите полное ФИО студента, информацию которого хотели бы редактировать: ";
        int index = findInListForIndex(dataBase, dataBaseSize);
        if(index != -INF){
            editElement(dataBase, index);
            removeWhiteSpacesFromFIO(dataBase, index);
            saveDataBaseToBinary(dataBase, dataBaseSize, index);
        }
        return dataBase;
    }
}
