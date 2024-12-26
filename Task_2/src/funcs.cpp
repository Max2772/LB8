#include <iostream>

#include "../../general/header-files/constants.h"
using namespace std;

void reverseBitsInString(string &input){ // O(m), m - длина строки; 
    for(int i = 1; i < input.length(); ++i){
        if(input[i] == '1')
            input[i] = '0';
        else
            input[i] = '1';
    }
}

string makeEqualSize(string str, int new_size){ // (k + m), k - разница длин 1-ой и 2-ой строки, m - длина большей строки;
    int tmp = new_size - str.length();
    string zeroPart = "";
    if(str[0] == '0'){
    for(int i = 0; i < tmp; ++i) zeroPart += '0';
    }else{
    for(int i = 0; i < tmp; ++i) zeroPart += '1';
    }

    string res = zeroPart + str;
    return res;
}

string reverseToAdditional(string str){ // O(m), m - длина строки;
        int i = str.length() - 1;
        bool secondSum = true;
        while(secondSum && i >= 0){
            int tmp = str[i] - '0' + 1;
            if(tmp == 1){
                secondSum = false;
                str[i] = '1';
            }else{
                str[i] = '0';
            }
            --i;
        }

        if(secondSum){
            cout << "Переполнение! Невозможно проведение операциц!\n";
            return INFSTRING;
        }
    return str;
}


string sumBackwardsCode(string a, string b){ // O(k + m), k - ∣a.length()−b.length()∣, m - max(a.length(),b.length());
    int a_size = a.length(), b_size = b.length();
    if(a_size != b_size){
        if(a_size > b_size){
            b = makeEqualSize(b, a_size);
        }else{
            a = makeEqualSize(a, b_size);
        }
    }

    int size = a_size >= b_size ? a_size : b_size;

    string res = "";
    for(int i = 0; i < size; ++i){
        res += '0';
    }

    bool secondSum = false;
    for(int i = size - 1; i >= 0; --i){
        int tmp = a[i] - '0' + b[i] - '0';
        
        if((secondSum == true && i == 0 && tmp == 0) || (secondSum == false && i == 0 && tmp == 2))
        {
            cout << "Переполнение! Невозможно проведение операциц!\n";
            return INFSTRING;
            break;
        }
        else if((tmp == 0 && secondSum == false) || (tmp == 1 && secondSum == true)){
            res[i] = '0';
        }else if((tmp == 1 && secondSum == false) || (tmp == 2 && secondSum == true))
            res[i] = '1';   
        else if(tmp == 0 && secondSum == true){
            res[i] = '1';
            secondSum = false;
        }else{
            secondSum = true;
            res[i] = '0';
        }
    }

    if(secondSum){
        res = reverseToAdditional(res);
    }
    
    return res;
}