#include <iostream>

#include "../header-files/task2.h"
#include "../header-files/string_utils.h"
#include "../header-files/file_utils.h"
#include "../header-files/output.h"

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"

int findInListForIndex(Student2 *dataBase, const int &dataBaseSize){
    string name;
    cin.ignore();
    getline(cin, name);
    cin.putback('\n');
    bool elementFound = false, moreThanOne = false;
    int resIndex, tmp = 0;
    int* resIndexes = new int[dataBaseSize];
    for(int i = 0; i < dataBaseSize; ++i){
        if(dataBase[i].FIO == name && elementFound == false){
            elementFound = true;
            resIndex = i;
            resIndexes[tmp] = i;
            ++tmp;
        }else if(dataBase[i].FIO == name && elementFound == true){
            moreThanOne = true;
            resIndexes[tmp] = i;
            ++tmp;
        }
    }

    if(!elementFound){
        cout << "Студент не найден! Проведение операции невозмоно.\n";
        delete [] resIndexes;
        resIndexes = nullptr;
        return -INF;
    }else if(!moreThanOne && elementFound){
        delete [] resIndexes;
        resIndexes = nullptr;
        return resIndex;
    }else{
        cout << "Найдены " << tmp << " студентов с данным ФИО, выберите номер определнного студента с данным ФИО: ";
        for(int i = 0; i < tmp; ++i){
            if(i == tmp - 1)
                cout << resIndexes[i] + 1;
            else
                cout << resIndexes[i] + 1 << ", ";
        }
        cout << "\nВвод: ";
        while(true){
            int N = readIntegerInLine() - 1;
            if(N == (-INF - 1))
                continue;

            if(findInArray(resIndexes, tmp, N)){
                delete [] resIndexes;
                resIndexes = nullptr;
                return N;
            }

            cout << "Некорректный ввод! Введите только предложенные номера: ";
        }
    }
}

void findInList(Student2 *dataBase, const int &dataBaseSize){
    cout << "\nВведите ФИО студента: ";
    string buffer;
    cin.ignore();
    getline(cin,buffer);
    cin.putback('\n');
    buffer = russianStringToLower(buffer);
    bool elementFound = false;
    for(int i = 0; i < dataBaseSize; ++i){
        string lowerFIO = dataBase[i].FIO;
        lowerFIO = russianStringToLower(lowerFIO);
        if(lowerFIO.find(buffer) != string::npos && !elementFound){
            elementFound = true;
            cout << "\n№ | ФИО | Математика | Язык | Физика | Аттестат | Средний\n";
            cout << "------------------------------------------------------------\n";
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].mark1 << ", " << dataBase[i].mark2 <<
            ", " << dataBase[i].mark3 << ", " << dataBase[i].mark4.d << ", " << dataBase[i].middleMark << '\n';
        }else if(lowerFIO.find(buffer) != string::npos && elementFound){
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].mark1 << ", " << dataBase[i].mark2 <<
            ", " << dataBase[i].mark3 << ", " << dataBase[i].mark4.d << ", " << dataBase[i].middleMark << '\n';
        }
    }

    if(!elementFound)
        cout << "Студент не найден!\n";
}