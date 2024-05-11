//
// Created by Admin on 25.04.2024.
//

#ifndef AIZO_1_FLOATSORTING_H
#define AIZO_1_FLOATSORTING_H
#include <vector>
using namespace std;


class FloatSorting {
public:
    void MS(vector<float> &arr, int left, int right);

    void MergeSort(vector<float> &arr);

    void merge(vector<float> &arr, int left, int mid, int right);
};


#endif //AIZO_1_FLOATSORTING_H
