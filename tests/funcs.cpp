#include <iostream>
#include "head.h"

using namespace std;

int readIntegerInLine() {
    int number;
    if(!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод! Введите заново: ";
        return -INF;
    }

    return number;
}

double readDoubleInLine() {
    double number;
    if(!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Некорректный ввод! Введите заново: ";
        return -INF;
    }

    return number;
}

void printMenu(){
        cout << "\n\t\t\tМеню Задание 1\n";
        cout << "1 - Добавление списка студентов\n"; 
        cout << "2 - Просмотр списка\n";
        cout << "3 - Поиск студентапо ФИО\n"; 
        cout << "4 - Редактирование списка\n"; 
        cout << "5 - Сортировать по доходу на члена семьи\n"; 
        cout << "6 - Вывести студентов, доход на члена семьи которых < 2 минимальных зарплат\n"; 
        cout << "0 - Выход из Задания 1\n"; 
        cout << "Ввод: ";
}

void swapStruct(Student &a, Student &b){
    Student temp = a;
    a = b;
    b = temp;
}  

void sortByMinIncome(Student *a, int size){
    for(int i = 0; i < size; ++i){
        int min = i;
        for(int j = i + 1; j < size; ++j){
            if(a[j].familyIncome < a[min].familyIncome)
                min = j;
        }
        if(min != i)
            swapStruct(a[i], a[min]);
    }
}

void addElement(Student *a, int size, Student x){
    Student *b = new Student[size + 1];
    for(int i = 0; i < size; ++i){
        b[i] = a[i];
    }
    b[size] = x;
    delete [] a;
    a = b;
}

int readCharToStringForChoice(char* input){  
    bool invalidInput = false;
    bool tooLongInput = true;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(input[i] != 'y' && input[i] != 'Y' && input[i] != 'n' && input[i] != 'N' && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n'){
            tooLongInput = false;
            break;
        }
    }

    if(tooLongInput){
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput || (input[1] != '\n')){
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

Student* inputStudents(){
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
        cin.ignore();

        Student *dataBase = new Student[N];

        for(int i = 0; i < N; ++i){
            cout << "Введите ФИО " << i+1 << " студента: ";
            getline(cin, dataBase[i].FIO);
            cout << "Введите номер группы " << i+1 << " студента: ";
            dataBase[i].group = readIntegerInLine();
            while(dataBase[i].group < 0){
                if(dataBase[i].group != -INF)
                    cout << "Некорректный ввод! Введите натуральное число: ";
                dataBase[i].group = readIntegerInLine();
            }
            cout << "Введите средний балл " << i+1 << " студента: ";
            dataBase[i].averageMark = readDoubleInLine();
            while(dataBase[i].averageMark < 0){
                if(dataBase[i].averageMark != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].averageMark = readDoubleInLine();
            }
            cout << "Введите доход на члена семьи " << i+1 << " студента: ";
            while(dataBase[i].familyIncome < 0){
                if(dataBase[i].familyIncome != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].familyIncome = readDoubleInLine();
            }
        }
        return dataBase;
    }else if(choice == 2){

    }else{
        int size = 0;
        Student *dataBase = new Student[size];
        while(true){
            cout << "Хотите ли вы добавить студента?(Y/N)";
            char* buffer = new char[80];
            while(readCharToStringForChoice(buffer) == -INF);
                if(buffer[0] == 'Y' || buffer[0] == 'y'){
                    Student B;
                    cout << "Введите ФИО"  << " студента: ";
                    getline(cin, B.FIO);
                    cout << "Введите номер группы студента: ";
                    cin >> B.group;
                    cout << "Введите средний балл студента: ";
                    cin >> B.averageMark;
                    cout << "Введите доход на члена семьи студента: ";
                    cin >> B.familyIncome;
                    cin.ignore(); size++;
                    addElement(dataBase, size, B);
                }else{
                    return dataBase;
                }
        }
    }

}











