//
// Created by Admin on 18.04.2024.
//

#include "Generator.h"
#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <fstream>
#include <iostream>

using namespace std;


void Generator::GenVectorIntRand(vector<int> &arr, int ilosc) {
    arr.clear();
    srand(time(nullptr));
    for (int i = 0; i < ilosc; i++){
        int liczba = rand() % (2147483645 - 0 + 1) + 0;
        arr.push_back(liczba);
    }
}

void Generator::GenVectorInt50(vector<int> &arr, int ilosc) {
    arr.clear();
    srand(time(NULL));
    for (int i = 0; i < ilosc; i++) {
        int liczba = rand() % (2147483645 - 0 + 1) + 0;
        arr.push_back(liczba);
        }
    int sortNum = arr.size()/2;
    sort(arr.begin(), arr.begin() + sortNum);
}

void Generator::GenVectorIntSort(vector<int> &arr, int ilosc) {
    arr.clear();
    srand(time(NULL));
    for (int i = 0; i < ilosc; i++) {
        int liczba = rand() % (2147483645 - 0 + 1) + 0;
        arr.push_back(liczba);
    }
    sort(arr.begin(), arr.end());
}

void Generator::GenVectorFloat(vector<float> &arr, int ilosc) {
    arr.clear();
    srand((unsigned)time(NULL));
    for (int i = 0; i < ilosc; i++){
            float liczba = GetRandomFloat();
            arr.push_back(liczba);
    }
}

void Generator::GenVectorDouble(vector<double> &arr, int ilosc) {
    arr.clear();
    double liczba;
    for (int i = 0; i < ilosc; i++){
        liczba = GetRandomDouble();
        arr.push_back(liczba);
    }
}

double Generator:: GetRandomDouble(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<uint64_t> dis(numeric_limits<uint64_t>::min(), numeric_limits<uint64_t>::max());
    uint64_t randomBits = dis(gen);
    double randomDouble = *reinterpret_cast<double*>(&randomBits);
    return randomDouble;
}

float Generator::GetRandomFloat() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<uint32_t> dis(numeric_limits<uint32_t>::min(), numeric_limits<uint32_t>::max());
    uint64_t randomBits = dis(gen);
    float randomFloat = *reinterpret_cast<float*>(&randomBits);
    return randomFloat;
}

void Generator::LoadDataFromFile(vector<int> &arr) {
    cout << "Podaj nazwe pliku" << endl;
    string filename;
    cin >> filename;
    ifstream file(filename);

    if(file.is_open()) {
        int size;
        file >> size;

        int num;
        for (int i = 0; i < size; i++) {
            file >> num;
            arr.push_back(num);
        }
    }
    else {
        cout<<"Blad odczytywania pliku! " << endl;
        return;
    }
    file.close();
}

void Generator:: SaveToFile(vector<int> &arr){
    string filename;
    cout << "Podaj nazwe pliku do zapisywania: " << endl;
    cin >> filename;
    ofstream file(filename);

    if(file.is_open()){
        file << arr.size() << endl;

        for (int i = 0; i < arr.size(); i++){
            file << arr[i] << endl;
        }
    }
    else{
        cout << "Blad otworzenia pliku!" << endl;
        return;
    }
    file.close();

}



