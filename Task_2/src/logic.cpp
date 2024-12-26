#include <iostream>
#define Student Student2

#include "../header-files/task2.h"

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"

double getMiddle(const Student B){
    double res = (B.mark1 + B.mark2 + B.mark3 + B.mark4.d) / 4;
    return res;
}

double getMiddleForList(const Student *dataBase, const int &dataBaseSize){
    double res = 0;
    for(int i = 0; i < dataBaseSize; ++i)
        res += getMiddle(dataBase[i]);
    return (res / dataBaseSize);
}