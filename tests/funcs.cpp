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
    return b;
}

bool findInArray(int* resIndexes, int size, int x){
    bool isFound = false;
    for(int i = 0; i < size; ++i){
        if(resIndexes[i] == x)
            return true;
    }
    if(!isFound)
        false;
}

int findInListForIndex(Student *dataBase, const int &dataBaseSize){
    cout << "Введите ФИО студента для удаления из списка: ";
    string deleteName; cin >> deleteName;
    bool elementFound = false, moreThanOne = false;
    int resIndex, tmp = 0;
    int* resIndexes = new int[dataBaseSize];
    for(int i = 0; i < dataBaseSize; ++i){
        if(dataBase[i].FIO == deleteName && elementFound == false){
            elementFound = true;
            resIndex = i;
            resIndexes[tmp] = i;
            ++tmp;
        }else if(dataBase[i].FIO == deleteName && elementFound == true){
            moreThanOne = true;
            resIndexes[tmp] = i;
            ++tmp;
        }
    }

    if(!elementFound){
        cout << "Студент не найден! Удаление дальше невозмоно.\n";
        return -INF;
    }else if(!moreThanOne && elementFound){
        return resIndex;
    }else{
        cout << "Найдены " << tmp << " студентов с данным ФИО, выберите номер определнного студента с данной фамилией для удаления: ";
        for(int i = 0; i < tmp; ++i){
            if(i == tmp - 1)
                cout << resIndexes[i] + 1;
            else
                cout << resIndexes[i] + 1 << ", ";
        }
        cout << "\nВвод: ";
        int N = readIntegerInLine() - 1;
        while(N == -INF && !(findInArray(resIndexes, tmp, N))){
            if(N != -INF)
                cout << "Некорректный ввод! Введите только предложенный номер: ";
            N = readIntegerInLine();
        }
        return N;
    }
}



void printMenu(){
        cout << "\n\t\t\tМеню Задание 1\n";
        cout << "1 - Создание списка студентов\n"; 
        cout << "2 - Просмотр списка\n";
        cout << "3 - Поиск студента по ФИО\n"; 
        cout << "4 - Редактирование списка\n"; 
        cout << "5 - Сортировать по доходу на члена семьи\n"; 
        cout << "6 - Вывести студентов, доход на члена семьи которых < 2 минимальных зарплат\n"; 
        cout << "0 - Выход из Задания 1\n"; 
        cout << "Ввод: ";
}

Student* editList(Student *dataBase, int &dataBaseSize){
    cout << "Введите + для добавления, - для удаления студента(+/-): ";
    string buffer; cin >> buffer;
    while(buffer != "+" && buffer != "-"){
        cout << "Введите только + или - : ";
        cin >> buffer;
    }
    if(buffer == "+"){
        Student B;
        cout << "Введите ФИО новго студента: ";
        cin.ignore();
        getline(cin, B.FIO);
        cout << "Введите номер группы нового студента: ";
        B.group = readIntegerInLine();
        while(B.group < 0){
            if(B.group != -INF)
                cout << "Некорректный ввод! Введите натуральное число: ";
            B.group = readIntegerInLine();
        }
        cout << "Введите средний балл нового студента: ";
        B.averageMark = readDoubleInLine();
        while(B.averageMark < 0){
            if(B.averageMark != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.averageMark = readDoubleInLine();
        }
        cout << "Введите доход на члена семьи нового студента: ";
        B.familyIncome = readDoubleInLine();
        while(B.familyIncome < 0){
            if(B.familyIncome != -INF)
                cout << "Некорректный ввод! Введите вещественное число > 0: ";
            B.familyIncome = readDoubleInLine();
        }
        dataBase = addElement(dataBase, dataBaseSize, B);
        return dataBase;
    }else{
        int index = findInListForIndex(dataBase, dataBaseSize);
        if(index != -INF){
            dataBase = deleteElement(dataBase, dataBaseSize, index);
        }
        return dataBase;
    }
}



void findInList(Student *dataBase, const int &dataBaseSize){
    cout << "\nВведите ФИО студента(Учитывая все пробелы): ";
    string buffer; cin >> buffer;
    bool elementFound = false;
    for(int i = 0; i < dataBaseSize; ++i){
        if(dataBase[i].FIO == buffer){
            elementFound = true;
            cout << dataBase[i].FIO << ", группа " << dataBase[i].group << " , средний балл: " << dataBase[i].averageMark <<
            " , доход на члена семьи " << dataBase[i].familyIncome << '\n';
        }
    }

    if(!elementFound)
        cout << "Студент не найден!\n";
}

void showList(Student *dataBase, int size){
    cout << '\n';
    for(int i = 0; i < size; ++i){
        cout << dataBase[i].FIO << ", группа " << dataBase[i].group << " , средний балл: " << dataBase[i].averageMark <<
        " , доход на члена семьи " << dataBase[i].familyIncome << '\n';
    }
    cout << '\n';
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

void waitForInput() {
    cout << "Нажмите ENTER, чтобы продолжить...";
    cin.ignore();
    cin.get();
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
            dataBase[i].familyIncome = readDoubleInLine();
            while(dataBase[i].familyIncome < 0){
                if(dataBase[i].familyIncome != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                dataBase[i].familyIncome = readDoubleInLine();
            }
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
            cout << "Введите номер группы " << i+1 << " студента: ";
            B.group = readIntegerInLine();
            while(B.group < 0){
                if(B.group != -INF)
                    cout << "Некорректный ввод! Введите натуральное число: ";
                B.group = readIntegerInLine();
            }
            cout << "Введите средний балл " << i+1 << " студента: ";
            B.averageMark = readDoubleInLine();
            while(B.averageMark < 0){
                if(B.averageMark != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.averageMark = readDoubleInLine();
            }
            cout << "Введите доход на члена семьи " << i+1 << " студента: ";
            B.familyIncome = readDoubleInLine();
            while(B.familyIncome < 0){
                if(B.familyIncome != -INF)
                    cout << "Некорректный ввод! Введите вещественное число > 0: ";
                B.familyIncome = readDoubleInLine();
            }
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
                    cout << "Введите ФИО"  << " студента: ";
                    cin.ignore();
                    getline(cin, B.FIO);
                    cout << "Введите номер группы студента: ";
                    B.group = readIntegerInLine();
                    while(B.group < 0){
                        if(B.group != -INF)
                            cout << "Некорректный ввод! Введите натуральное число: ";
                        B.group = readIntegerInLine();
                    }
                    cout << "Введите средний балл студента: ";
                    B.averageMark = readDoubleInLine();
                    while(B.averageMark < 0){
                        if(B.averageMark != -INF)
                            cout << "Некорректный ввод! Введите вещественное число > 0: ";
                        B.averageMark = readDoubleInLine();
                    }
                    cout << "Введите доход на члена семьи студента: ";
                    B.familyIncome = readDoubleInLine();
                    while(B.familyIncome < 0){
                        if(B.familyIncome != -INF)
                            cout << "Некорректный ввод! Введите вещественное число > 0: ";
                        B.familyIncome = readDoubleInLine();
                    }
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