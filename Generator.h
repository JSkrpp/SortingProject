//
// Created by Admin on 18.04.2024.
//

#ifndef AIZO_1_GENERATOR_H
#define AIZO_1_GENERATOR_H
#include <vector>
#include <iostream>
using namespace std;


class Generator {
public:
    void GenVectorIntRand(vector<int> &arr, int ilosc);

    void GenVectorInt50(vector<int> &arr, int ilosc);

    void GenVectorIntSort(vector <int> &arr, int ilosc);

    void GenVectorFloat(vector<float> &arr, int ilosc);

    void GenVectorDouble(vector<double> &arr, int ilosc);

    double GetRandomDouble();

    float GetRandomFloat();

    void LoadDataFromFile(vector<int> &arr);

    void SaveToFile(vector<int> &arr);
};


#endif //AIZO_1_GENERATOR_H
