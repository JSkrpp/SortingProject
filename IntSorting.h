//
// Created by Admin on 16.04.2024.
//

#ifndef AIZO_1_INTSORTING_H
#define AIZO_1_INTSORTING_H
#include <vector>
#include <iostream>
using namespace std;


class IntSorting {
public:
    int partition (vector<int>& arr, int low, int high);

    void swap (vector<int>& arr, int i, int j);

    void QS(vector<int> &arr, int low, int high);

    vector<int>QuickSort(vector<int> &arr);

    void IS(vector<int> &arr);

    void InsertionSort(vector<int> &arr);

    void MS(vector<int> &arr, int left, int right);

    void MergeSort(vector<int> &arr);

    void merge(vector<int> &arr, int left, int mid, int right);

    void heapify(vector<int>&arr, int n, int i);

    void HS(vector<int> &arr);

    void HeapSort(vector<int> &arr);
};


#endif //AIZO_1_INTSORTING_H
