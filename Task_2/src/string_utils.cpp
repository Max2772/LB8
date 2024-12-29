#include <iostream>
#include "../header-files/task2.h"

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"

void removeWhiteSpacesFromList(Student2 *dataBase, const int &dataBaseSize){
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

void removeWhiteSpacesFromFIO(Student2* dataBase, const int &idx){
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
