//
// Created by Admin on 18.04.2024.
//

#ifndef AIZO_1_BADANIA_H
#define AIZO_1_BADANIA_H

#endif //AIZO_1_BADANIA_H
#include <iostream>
#include <vector>
#include "IntSorting.h"
#include "Generator.h"


class Badania {
public:
    void QuickSortIntRand(vector<int> &arr);

    void QuickSortInt50(vector<int> &arr);

    int getAmount();

    int getTestNumber();

    void InsertionSortIntRand(vector<int> &arr);

    void InsertionSortInt50(vector<int> &arr);

    void InsertionSortIntSort(vector<int> &arr);

    void MergeSortIntRand(vector<int> &arr);

    void HeapSortIntRand(vector<int> &arr);

    void MergeSortFloat(vector<float> &flo);

    void MergeSortDouble(vector<double> &dub);

    void HeapSortIntSort(vector<int> &arr);

    void QuickSortIntSort(vector<int> &arr);

    void MergeSortIntSort(vector<int> &arr);

    void MergeSortInt50(vector<int> &arr);

    void HeapSortInt50(vector<int> &arr);
};