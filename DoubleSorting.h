//
// Created by Admin on 26.04.2024.
//

#ifndef AIZO_1_DOUBLESORTING_H
#define AIZO_1_DOUBLESORTING_H
#include <vector>
using namespace std;


class DoubleSorting {
public:
    void MS(vector<double> &arr, int left, int right);

    void MergeSort(vector<double> &arr);

    void merge(vector<double> &arr, int left, int mid, int right);
};


#endif //AIZO_1_DOUBLESORTING_H
