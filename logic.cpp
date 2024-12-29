#include <iostream>
#include "head.h"

double getMiddle(const Student2 B){
    double res = (B.mark1 + B.mark2 + B.mark3 + B.mark4.d) / 4;
    return res;
}

double getMiddleForList(const Student2 *dataBase, const int &dataBaseSize){
    double res = 0;
    for(int i = 0; i < dataBaseSize; ++i)
        res += getMiddle(dataBase[i]);
    return (res / dataBaseSize);
}