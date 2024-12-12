#include <iostream>
#include "tests/head.h"
#include "tests/funcs.cpp"

using namespace std;

int main(){
    cout << "Программа, для перевода числа из обратного кода в естественную форму для целых чисел\n";
    cout << "Выполнил Бибиков Максим, группа 453502\n";
    while(true){
        cout << "Введите 1, если хотите выполнить программу, или 2, если хотите завершить работу программы\n";
        int type = readIntegerInLine();
        while ((type != 1 && type != 2)) {
            cout << "Некорректный ввод! Введите либо 1, либо 2: ";
            type = readIntegerInLine();
        }
        if(type == 2)
            break;
        else if(type != 1 && type != 2)
            continue;


        
        
        cout << "Введите обратный код: ";
        string input = readStringForReverse();
        while(input == INFSTRING)
            input = readStringForReverse();
        
        if(input[0] == '1')
            reverseBitsInString(input);

        int result = binaryStringToDecimal(input);
        cout << "Полученное число: " << result << '\n';

    }
    return 0;
}