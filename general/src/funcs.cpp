#include <iostream>
#include <locale>
#include <codecvt>

#include "../../Task_1/header-files/task1.h"
#include "../../Task_2/header-files/task2.h"

#include "../header-files/constants.h"
#include "../header-files/funcs.h"

using namespace std;

int readCharToStringForChoice(char* input){  
    bool invalidInput = false;
    bool tooLongInput = true;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(input[i] != '1' && input[i] != '2' && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n'){
            tooLongInput = false;
            break;
        }
    }

    if(tooLongInput){
        cout << "Ввод слишком длинный, введите только 1 или 2: ";
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput || (input[1] != '\n')){
        cout << "Некорректный ввод, введите только 1 или 2: ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

int readCharToStringForType(char* input){  
    bool invalidInput = false;
    bool tooLongInput = true;
    for(int i = 0; i < 80; ++i){
        input[i] = getchar();
        if(input[i] != '1' && input[i] != '2' && input[i] != '\n'){
            invalidInput = true;
        }
        if(input[i] == '\n'){
            tooLongInput = false;
            break;
        }
    }

    if(tooLongInput){
        cout << "Ввод слишком длинный, введите только 1 или 2: ";
        while((getchar()) != '\n');
        return -INF;
    }

    if(invalidInput || (input[1] != '\n')){
        cout << "Некорректный ввод, введите только 1 или 2: ";
        return -INF;
    }else if(input[0] == '\n')
        return -INF;

    return 1;
}

string newStringInInterval(const string &str, const int & end){
    string newStr;
    for(int i = 0;i < end; ++i){
        newStr += str[i];
    }
    return newStr;
}

string russianStringToLower(const string &str){ // Uses locale and codecvt, used for tolower();
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
    wstring wide_str = converter.from_bytes(str);

    for (wchar_t &ch : wide_str) {
        ch = towlower(ch);
    }

    return converter.to_bytes(wide_str);
}
/*
void removeWhiteSpacesFromList(Student *dataBase, const int &dataBaseSize){
    for(int i = 0; i < dataBaseSize; ++i){
        string str = dataBase[i].FIO;
        if(str[str.length() - 1] == ' ' || str[str.length() - 1] == '\t'){
            int j = str.length() - 1;
            while(str[j] == ' ' || str[j] == '\t'){
                j--;
            }
            str = newStringInInterval(str, j+1);
            dataBase[i].FIO = str;
        }
    }
}

void removeWhiteSpacesFromFIO(Student* dataBase, const int &idx){
    string str = dataBase[idx].FIO;
    if(str[str.length() - 1] == ' ' || str[str.length() - 1] == '\t'){
    int j = str.length() - 1;
    while(str[j] == ' ' || str[j] == '\t'){
        j--;
    }
    str = newStringInInterval(str, j+1);
    dataBase[idx].FIO = str;
    }
}
*/