#include <iostream>
#define Student Student2

#include "../header-files/task2.h"
#include "../header-files/file_utils.h"
#include "../header-files/logic.h"
#include "../header-files/string_utils.h"
#include "../header-files/array_utils.h"

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"


Student* autoInput(Student *dataBase, int &dataBaseSize){
        if(dataBaseSize != 0 || dataBase != nullptr){
        cout << "Вы уверены, что хотите перзаписать старый список стандартной таблицой для отладки?(y/n): ";
        string buffer; cin >> buffer;
        while(buffer != "Y" && buffer != "y" && buffer != "N" && buffer != "n"){
            cout << "Введите только Y/y - да, N/n -нет: ";
            cin >> buffer;
        }
        if(buffer == "N" || buffer == "n"){
            return dataBase;
        }
            delete [] dataBase;
            dataBase = nullptr;
            dataBaseSize = 0;
        }
        Student* newDataBase = new Student[10]{
        {"Иванов Иван Сергеевич", 4.5, 4.7, 4.8, {4.6}, 4.65},
        {"Петрова Мария Алексеевна", 3.8, 4.0, 3.7, {3.9}, 3.85},
        {"Сидоров Алексей Викторович", 4.2, 4.4, 4.3, {4.5}, 4.35},
        {"Смирнова Ольга Дмитриевна", 3.9, 4.1, 4.0, {4.2}, 4.05},
        {"Фролов Сергей Владимирович", 4.8, 4.9, 5.0, {4.7}, 4.85},
        {"Иванова Анна Андреевна", 4.1, 3.9, 4.0, {3.8}, 3.95},
        {"Попов Дмитрий Олегович", 3.7, 4.2, 4.1, {4.0}, 4.0},
        {"Орлова Наталья Петровна", 4.6, 4.5, 4.4, {4.7}, 4.55},
        {"Козлов Игорь Александрович", 4.4, 4.3, 4.5, {4.6}, 4.45},
        {"Лебедева Елена Сергеевна", 3.5, 3.6, 3.7, {3.0}, 3.45}
    };
        dataBaseSize = 10;
        saveDataBaseFromFile(newDataBase, dataBaseSize, 0);
    return newDataBase;
}

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
            cout << "Введите балл за экзамен по математике " << i+1 << " студента: ";
            dataBase[i].mark1 = readDoubleInLine();
            while(dataBase[i].mark1 < 0){
                if(dataBase[i].mark1 != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].mark1 = readDoubleInLine();
            }

            cout << "Введите балл за экзамен по языку " << i+1 << " студента: ";
            dataBase[i].mark2 = readDoubleInLine();
            while(dataBase[i].mark2 < 0){
                if(dataBase[i].mark2 != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].mark2 = readDoubleInLine();
            }

            cout << "Введите балл за экзамен по физике " << i+1 << " студента: ";
            dataBase[i].mark3 = readDoubleInLine();
            while(dataBase[i].mark3 < 0){
                if(dataBase[i].mark3 != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].mark3 = readDoubleInLine();
            }

            cout << "Введите балл аттестата за 11 класс " << i+1 << " студента: ";
            dataBase[i].mark4.d = readDoubleInLine();
            while(dataBase[i].mark4.d < 0){
                if(dataBase[i].mark4.d != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].mark4.d = readDoubleInLine();
            }

            dataBase[i].middleMark = getMiddle(dataBase[i]);

            removeWhiteSpacesFromFIO(dataBase, i); // Необязательная фича, она просто удаляет лишние символы после ФИО
            dataBaseSize++;
            saveDataBaseFromFile(dataBase, dataBaseSize, i);
        }
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

            cout << "Введите балл за экзамен по математике " << i+1 << " студента: ";
            B.mark1 = readDoubleInLine();
            while(B.mark1 < 0){
                if(B.mark1 != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.mark1 = readDoubleInLine();
            }

            cout << "Введите балл за экзамен по языку " << i+1 << " студента: ";
            B.mark2 = readDoubleInLine();
            while(B.mark2 < 0){
                if(B.mark2 != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.mark2 = readDoubleInLine();
            }

            cout << "Введите балл за экзамен по физике " << i+1 << " студента: ";
            B.mark3 = readDoubleInLine();
            while(B.mark3 < 0){
                if(B.mark3 != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.mark3 = readDoubleInLine();
            }

            cout << "Введите балл аттестата за 11 класс " << i+1 << " студента: ";
            B.mark4.d = readDoubleInLine();
            while(B.mark4.d < 0){
                if(B.mark4.d != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.mark4.d = readDoubleInLine();
            }

            B.middleMark = getMiddle(B);

            dataBase = addElement(dataBase, dataBaseSize, B);
            removeWhiteSpacesFromFIO(dataBase, i); 
            saveDataBaseFromFile(dataBase, dataBaseSize, i);
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
                }else if(dataBaseSize == 0){ // Можно оптимизировать здесь
                    delete [] dataBase;
                    dataBase = nullptr;
                    return dataBase;
                }else{
                    return dataBase;
                }
        }
    }

}