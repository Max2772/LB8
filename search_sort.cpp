#include <iostream>
#include "head.h"


bool findInArray(int* resIndexes, const int &size, const int &x){
    for(int i = 0; i < size; ++i){
        if(resIndexes[i] == x)
            return true;
    }
    return false;
}

int findInListForIndex(Student *dataBase, const int &dataBaseSize){
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

void findInList(Student *dataBase, const int &dataBaseSize){
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
            cout << "\n№ | ФИО | Номер группы | Средний балл | Доход на члена семьи | Льготы\n";
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].group << ", " << dataBase[i].averageMark <<
                 ", " << dataBase[i].familyIncome.d << " руб, "; boolOutput(dataBase[i].lgoti); cout << "\n";
        }else if(lowerFIO.find(buffer) != string::npos && elementFound){
            cout << i+1 << ".  " << dataBase[i].FIO << ", " << dataBase[i].group << ", " << dataBase[i].averageMark <<
                 ", " << dataBase[i].familyIncome.d << " руб, "; boolOutput(dataBase[i].lgoti); cout << "\n";
        }
    }

    if(!elementFound)
        cout << "Студент не найден!\n";
}


void swapStruct(Student &a, Student &b){
    Student temp = a;
    a = b;
    b = temp;
}  

void sortByMinIncome(Student *a, const int &dataBasesize){
    cout << "Вы уверены, что хотите отсортировать список по возврастанию по параметру «Доход на члена семьи» ?(y/n): ";
        string buffer; cin >> buffer;
        while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
            cout << "Введите только Y/y - да, N/n -нет: ";
            cin >> buffer;
        }
    if(buffer == "Y" || buffer == "y"){
        for(int i = 0; i < dataBasesize; ++i){
            int min = i;
            for(int j = i + 1; j < dataBasesize; ++j){
                if(a[j].familyIncome.d < a[min].familyIncome.d)
                    min = j;
            }
            if(min != i)
                swapStruct(a[i], a[min]);
        }
        saveDataBaseToBinary(a, dataBasesize, 0);
    }
}