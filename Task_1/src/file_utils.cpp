#include <fstream>
#include <filesystem>

#include "../header-files/task1.h"

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"

using namespace std;

void saveDataBaseFromFile(Student* dataBase, const int &dataBaseSize, int startIdx, const string& path){
    ofstream out;

    if(startIdx == 0)
        out.open(path);
    else
        out.open(path, ios::app);

    if(!out)
        return;

    for(int i = startIdx; i < dataBaseSize; ++i){
        out<<dataBase[i].FIO <<'\n';
        out<<dataBase[i].group <<'\n';
        out<<dataBase[i].averageMark <<'\n';
        out<<dataBase[i].familyIncome.d << '\n';
        out<<dataBase[i].lgoti << '\n';
    }

    out.close();
}

Student* loadDataBaseFromFileTask1(int& dataBaseSize, const string& path){
    ifstream in(path);
    if (!in){
        dataBaseSize = 0;
        return nullptr;
    }

    int count = 0;
    string line;
    while(getline(in, line)){
        ++count;
    }
    in.clear();
    in.seekg(0, ios::beg);

    dataBaseSize = count / 5;

    Student* dataBase = new Student[dataBaseSize];

    for(int i = 0; i < dataBaseSize; ++i){
        getline(in, dataBase[i].FIO);
        in >> dataBase[i].group;  
        in >> dataBase[i].averageMark;
        in >> dataBase[i].familyIncome.d;
        in >> dataBase[i].lgoti;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    in.close();
    return dataBase;
}
