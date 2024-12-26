#include <iostream>
#include "../header-files/constants.h"
#include "../header-files/funcs.h"

using std::cout;

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