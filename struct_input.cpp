#include <iostream>
#include "head.h"


Student* inputStudents(Student *dataBase, int &dataBaseSize){
    if(dataBaseSize != 0){
        cout << "Вы уверены, что хотите перезаписать старый список?(y/n): ";
        string buffer; cin >> buffer;
        while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
            cout << "Введите только Y/y - да, N/n -нет: ";
            cin >> buffer;
        }
        if(buffer == "N" || buffer == "n")
            return dataBase;
        else{
               delete [] dataBase;
               dataBase = nullptr;
               dataBaseSize = 0;
        }
    }
    bool autoGroup = false;
    cout << "Желаете ли вы включить автоматичесое распределние по группам по среднему баллу?(y/n): ";
    string buffer; cin >> buffer;
    while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
        cout << "Введите только Y/y - да, N/n -нет: ";
            cin >> buffer;
    }
    if(buffer == "Y" || buffer == "y")
        autoGroup = true;
        
    cout << "\nВыберите способ ввода данных:\n";
    cout << "1. Ввод заранее заданного количества структур\n";
    cout << "2. Ввод до появления структуры с заданным признаком\n";
    cout << "3. Ввод с диалогом о необходимости продолжать ввод\n";
    int choice = readIntegerInLine();
    while ((choice != 1 && choice != 2 && choice != 3)) {
        if(choice != -INF)
            cout << "Некорректный ввод! Введите только 1,2 или 3: ";
        choice = readIntegerInLine();
    }

    if(choice == 1){
        cout << "Введите кол-во студентов: ";
        int N = readIntegerInLine();
        while ((N <= 0)) {
            if(N != -INF)
                cout << "Некорректный ввод! Введите натуральное число: ";
            N = readIntegerInLine();
        }

        Student *dataBase = new Student[N];

        for(int i = 0; i < N; ++i){
            cout << "Введите ФИО " << i+1 << " студента: ";
            cin.ignore();
            getline(cin, dataBase[i].FIO);
            cout << "Введите средний балл " << i+1 << " студента: ";
            dataBase[i].averageMark = readDoubleInLine();
            while(dataBase[i].averageMark < 0){
                if(dataBase[i].averageMark != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].averageMark = readDoubleInLine();
            }

            if(!autoGroup){
                cout << "Введите номер группы " << i+1 << " студента: ";
                dataBase[i].group = readIntegerInLine();
                while(dataBase[i].group < 0){
                    if(dataBase[i].group != -INF)
                        cout << "Некорректный ввод! Введите натуральное число: ";
                    dataBase[i].group = readIntegerInLine();
                }
            }else{
                dataBase[i].group = determineGroup(dataBase[i].averageMark);
            }

            cout << "Введите доход на члена семьи " << i+1 << " студента: ";
            dataBase[i].familyIncome.d = readDoubleInLine();
            while(dataBase[i].familyIncome.d < 0){
                if(dataBase[i].familyIncome.d != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].familyIncome.d = readDoubleInLine();
            }
            cout << "Есть ли льготы(y/n): ";
            string buffer; cin >> buffer;
            while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
                cout << "Введите только Y/y - да, N/n -нет: ";
                cin >> buffer;
            }
            if(buffer[0] == 'Y' || buffer[0] == 'y')
                dataBase[i].lgoti = true;
            else
                dataBase[i].lgoti = false;
        }
        dataBaseSize = N;
        return dataBase;
    }else if(choice == 2){
        int i = 0;
        while(true){
            Student B;
            cout << "Введите ФИО " << i+1 << " студента: ";
            cin.ignore();
            getline(cin, B.FIO);
            if(B.FIO == ""){
                cin.putback('\n');
                return dataBase;
            }
            cout << "Введите средний балл " << i+1 << " студента: ";
            B.averageMark = readDoubleInLine();
            while(B.averageMark < 0){
                if(B.averageMark != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.averageMark = readDoubleInLine();
            }

            if(!autoGroup){
                cout << "Введите номер группы " << i+1 << " студента: ";
                B.group = readIntegerInLine();
                while(B.group < 0){
                    if(B.group != -INF)
                        cout << "Некорректный ввод! Введите натуральное число: ";
                    B.group = readIntegerInLine();
                }
            }else{
                B.group = determineGroup(B.averageMark);
            }

            cout << "Введите доход на члена семьи " << i+1 << " студента: ";
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
            i++;
        }
    }else{
        dataBaseSize = 0;
        Student *dataBase = nullptr;
        while(true){
            cout << "Хотите ли вы добавить студента?(Y/N)";
            string buffer; cin >> buffer;
            while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
                cout << "Введите только Y/y - да, N/n -нет: ";
                cin >> buffer;
            }
                if(buffer[0] == 'Y' || buffer[0] == 'y'){
                    Student B;
                    cout << "Введите ФИО студента: ";
                    cin.ignore();
                    getline(cin, B.FIO);
                    cout << "Введите средний балл студента: ";
                    B.averageMark = readDoubleInLine();
                    while(B.averageMark < 0){
                        if(B.averageMark != -INF)
                            cout << "Некорректный ввод! Введите вещественное число > 0: ";
                        B.averageMark = readDoubleInLine();
                    }

                    if(!autoGroup){
                        cout << "Введите номер группы студента: ";
                        B.group = readIntegerInLine();
                        while(B.group < 0){
                            if(B.group != -INF)
                                cout << "Некорректный ввод! Введите натуральное число: ";
                            B.group = readIntegerInLine();
                        }
                    }else{
                        B.group = determineGroup(B.averageMark);
                    }

                    cout << "Введите доход на члена семьи студента: ";
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
                }else if(dataBaseSize == 0){
                    delete [] dataBase;
                    dataBase = nullptr;
                    return dataBase;
                }else{
                    return dataBase;
                }
        }
    }

}