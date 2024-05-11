//
// Created by Admin on 25.04.2024.
//

#include <windows.h>
#include <iostream>
#include <vector>
#include "FloatSorting.h"

using namespace std;


void FloatSorting::MS(vector<float> &arr, int left, int right) {
    if(left < right){
        int mid = left + (right - left) /2;

        MS(arr, left, mid);
        MS(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

}

void FloatSorting::MergeSort(vector<float> &arr) {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    MS(arr, 0, arr.size()-1);

    QueryPerformanceCounter(&end);
    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;

    cout << "Czas sortowania: " << elapsedTime << " ms" << endl;
}

void FloatSorting::merge(vector<float> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<float> L(n1), R(n2);

    for (int i = 0; i < n1; i++){
        L[i] = arr[left+i];
    }
    for (int j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
