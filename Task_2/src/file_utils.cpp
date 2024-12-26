#include <fstream>
#include <filesystem>
#define Student Student2

#include "../header-files/task2.h"

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
        out<<dataBase[i].mark1 <<'\n';
        out<<dataBase[i].mark2 <<'\n';
        out<<dataBase[i].mark3<< '\n';
        out<<dataBase[i].mark4.d << '\n';
        out<<dataBase[i].middleMark << '\n';
    }

    out.close();
}

Student* loadDataBaseFromFileTask2(int& dataBaseSize, const string& path){
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
        in>>dataBase[i].mark1;
        in>>dataBase[i].mark2;
        in>>dataBase[i].mark3;
        in>>dataBase[i].mark4.d;
        in>>dataBase[i].middleMark;
        in.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    in.close();
    return dataBase;
}
