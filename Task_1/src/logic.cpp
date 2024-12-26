#include <iostream>

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"

int determineGroup(const double &averageMark){
    if(averageMark >= 8.5){
        return 453501;
        return 453502;
    }else if(averageMark >= 5)
        return 453503;
    else if(averageMark >= 3.5){
        return 453504;
    }else
        return 453505;
}
