#include <iostream>
#define Student Student2

#include "../header-files/task2.h"
#include "../header-files/file_utils.h"
#include "../header-files/string_utils.h"
#include "../header-files/search_sort.h"
#include "../header-files/output.h"
#include "../header-files/logic.h"

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
    saveDataBaseFromFile(b, dataBaseSize, 0);
    return b;
}

void editElement(Student *dataBase, int idx){
    cout << dataBase[idx].FIO << ", " << dataBase[idx].mark1 << ", " << dataBase[idx].mark2 <<
    ", " << dataBase[idx].mark3 << ", " << dataBase[idx].mark4.d << ", " << dataBase[idx].middleMark << '\n';
    cout << "Перепишите новые данные студента:\n";

    Student B;
    cout << "Введите новое ФИО студента: ";
    cin.ignore();
    getline(cin, B.FIO);

    cout << "Введите балл за экзамен по математике: ";
    B.mark1 = readDoubleInLine();
    while(B.mark1 < 0){
        if(B.mark1 != -INF)
            cout << "Некорректный ввод! Введите вещественное число > 0: ";
        B.mark1 = readDoubleInLine();
    }

    cout << "Введите балл за экзамен по языку: ";
    B.mark2 = readDoubleInLine();
    while(B.mark2 < 0){
        if(B.mark2 != -INF)
            cout << "Некорректный ввод! Введите вещественное число > 0: ";
        B.mark2 = readDoubleInLine();
    }

    cout << "Введите балл за экзамен по физике: ";
    B.mark3 = readDoubleInLine();
    while(B.mark3 < 0){
        if(B.mark3 != -INF)
            cout << "Некорректный ввод! Введите вещественное число > 0: ";
        B.mark3 = readDoubleInLine();
    }

    cout << "Введите балл аттестата за 11 класс: ";
    B.mark4.d = readDoubleInLine();
    while(B.mark4.d < 0){
        if(B.mark4.d != -INF)
            cout << "Некорректный ввод! Введите вещественное число > 0: ";
        B.mark4.d = readDoubleInLine();
    }

    B.middleMark = getMiddle(B);

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

        cout << "Введите балл за экзамен по математике: ";
        B.mark1 = readDoubleInLine();
        while(B.mark1 < 0){
            if(B.mark1 != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.mark1 = readDoubleInLine();
        }

        cout << "Введите балл за экзамен по языку: ";
        B.mark2 = readDoubleInLine();
        while(B.mark2 < 0){
            if(B.mark2 != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.mark2 = readDoubleInLine();
        }

        cout << "Введите балл за экзамен по физике: ";
        B.mark3 = readDoubleInLine();
        while(B.mark3 < 0){
            if(B.mark3 != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.mark3 = readDoubleInLine();
        }

        cout << "Введите балл аттестата за 11 класс: ";
        B.mark4.d = readDoubleInLine();
        while(B.mark4.d < 0){
            if(B.mark4.d != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.mark4.d = readDoubleInLine();
        }

        B.middleMark = getMiddle(B);

        dataBase = addElement(dataBase, dataBaseSize, B);
        removeWhiteSpacesFromFIO(dataBase, dataBaseSize-1);
        saveDataBaseFromFile(dataBase, dataBaseSize, dataBaseSize-1);
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
            saveDataBaseFromFile(dataBase, dataBaseSize, index);
        }
        return dataBase;
    }
}
