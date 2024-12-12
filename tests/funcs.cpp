#include <iostream>
#include "head.h"

using namespace std;

int readIntegerInLine() { // O(n), n - длина ввода; 
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

string readStringForReverse(){ // O(n), n - длина строки;
    string input; cin >> input;
    bool invalidInput = false;
    for(int i = 0; i < input.length(); ++i){
        if(input[i] != '1' && input[i] != '0'){
            invalidInput = true;
            cout << "Ошибка ввода. Введите только число в обратной форме(без пробелов): ";
            return INFSTRING;
        }
    }
    return input;
}

void reverseBitsInString(string &input){ // O(n), n - длина строки;
    for(int i = 1; i < input.length(); ++i){
        if(input[i] == '1')
            input[i] = '0';
        else
            input[i] = '1';
    }
}

int pow(int a, int b){ // O(b), b - показатель степени;
    int num = 1;
    for(int i = 0; i < b; ++i)
        num *= a; 

    return num;
}

int binaryStringToDecimal(string input){ // O(n * b), n - длина строки, b - степень;
    int num = 0, length = input.length();
    for(int i = 1; i < length; ++i){
        if(input[i] == '1')
            num += pow(2, length - i - 1);
    }

    if(input[0] == '1')
        num *= -1;

    return num;
}