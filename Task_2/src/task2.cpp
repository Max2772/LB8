#include <iostream>

#include "../header-files/funcs.h"

#include "../../general/header-files/funcs.h"
#include "../../general/header-files/constants.h"

using std::cout;
using std::cin;
using std::string;


void task2(){
        cout << "Введите 1-ое число в прямом коде: ";
        string a = readStringForReverse();
        while(a == INFSTRING)
            a = readStringForReverse();

        cout << "Введите 2-ое число в прямом коде: ";
        string b = readStringForReverse();
        while(b == INFSTRING)
            b = readStringForReverse();

        if(a[0] == '1')
            reverseBitsInString(a);

        if(b[0] == '1')
            reverseBitsInString(b);

        cout << "1-ое число в обратном коде: " << a << '\n';
        cout << "2-ое число в обратном коде: " << b << '\n';

        string res = sumBackwardsCode(a,b);
        if(res == INFSTRING)
            cout << "Переполнение! Невозможно проведение операциц!\n";
        else{
            cout << "Результат сложения в обратном коде: " << res << '\n';
            cout << "Результат сложения в дополнительном коде: ";
            if(res[0] == '0')
                cout << res << '\n';
            else{
                res = reverseToAdditional(res);
                cout << res << '\n';
               }
        }

    }