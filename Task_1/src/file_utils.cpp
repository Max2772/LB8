#include <fstream>
#include <filesystem>

#include "../header-files/task1.h"

#include "../../general/header-files/constants.h"
#include "../../general/header-files/funcs.h"

using namespace std;

void saveDataBaseToBinary(Student* dataBase, const int& dataBaseSize, int startIdx, const string& path) {
    ofstream out;

    if (startIdx == 0)
        out.open(path, ios::binary);
    else
        out.open(path, ios::binary | ios::app);

    if (!out) return;

    for (int i = startIdx; i < dataBaseSize; ++i) {
        size_t fioLength = dataBase[i].FIO.size();
        out.write(reinterpret_cast<const char*>(&fioLength), sizeof(fioLength));
        out.write(dataBase[i].FIO.c_str(), fioLength);

        out.write(reinterpret_cast<const char*>(&dataBase[i].group), sizeof(dataBase[i].group));
        out.write(reinterpret_cast<const char*>(&dataBase[i].averageMark), sizeof(dataBase[i].averageMark));
        out.write(reinterpret_cast<const char*>(&dataBase[i].familyIncome.d), sizeof(dataBase[i].familyIncome.d));
        out.write(reinterpret_cast<const char*>(&dataBase[i].lgoti), sizeof(dataBase[i].lgoti));
    }

    out.close();
}

Student* loadDataBaseFromBinary(int& dataBaseSize, const string& path) {
    ifstream in(path, ios::binary);
    if (!in) {
        dataBaseSize = 0;
        return nullptr;
    }

    in.seekg(0, ios::end);
    size_t fileSize = in.tellg();
    in.seekg(0, ios::beg);

    size_t currentPosition = 0;
    int count = 0;

    while (currentPosition < fileSize) {
        size_t fioLength;
        in.read(reinterpret_cast<char*>(&fioLength), sizeof(fioLength));
        in.seekg(fioLength + sizeof(int) + sizeof(double) + sizeof(double) + sizeof(bool), ios::cur);
        currentPosition += sizeof(fioLength) + fioLength + sizeof(int) + sizeof(double) + sizeof(double) + sizeof(bool);
        ++count;
    }

    in.clear();
    in.seekg(0, ios::beg);

    dataBaseSize = count;
    Student* dataBase = new Student[dataBaseSize];

    for (int i = 0; i < dataBaseSize; ++i) {
        size_t fioLength;
        in.read(reinterpret_cast<char*>(&fioLength), sizeof(fioLength));

        char* fioBuffer = new char[fioLength + 1];
        in.read(fioBuffer, fioLength);
        fioBuffer[fioLength] = '\0';
        dataBase[i].FIO = string(fioBuffer);
        delete[] fioBuffer;

        in.read(reinterpret_cast<char*>(&dataBase[i].group), sizeof(dataBase[i].group));
        in.read(reinterpret_cast<char*>(&dataBase[i].averageMark), sizeof(dataBase[i].averageMark));
        in.read(reinterpret_cast<char*>(&dataBase[i].familyIncome.d), sizeof(dataBase[i].familyIncome.d));
        in.read(reinterpret_cast<char*>(&dataBase[i].lgoti), sizeof(dataBase[i].lgoti));
    }

    in.close();
    return dataBase;
}
