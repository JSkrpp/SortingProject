//
// Created by Admin on 16.04.2024.
//

#include <windows.h>
#include "IntSorting.h"
#include <iostream>
#include <vector>


using namespace std;

void IntSorting:: QS(vector<int>& arr, int low, int high){
    if (low < high){
        int pivot = partition(arr, low, high);

        QS(arr, low, pivot - 1);
        QS(arr, pivot + 1, high);
    }
}

void IntSorting:: swap(vector<int>& arr, int i, int j) {

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int IntSorting::partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = high;

        for(int j = high; j > low; j--){
            if (arr[j] > pivot){
                swap(arr, i , j);
                i--;
            }
        }
        swap (arr, low, i);
        return i;
}

vector<int> IntSorting::QuickSort(vector<int> &arr) {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

        int size = arr.size();
        QS(arr, 0, size -1);

    QueryPerformanceCounter(&end);
    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;

    cout << "Czas sortowania: " << elapsedTime << " ms" << endl;

    return arr;

}

void IntSorting::IS(vector<int> &arr) {
    int n = arr.size();
    int key, j;
    for (int i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void IntSorting::InsertionSort(vector<int> &arr) {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    IS(arr);

    QueryPerformanceCounter(&end);
    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;

    cout << "Czas sortowania: " << elapsedTime << " ms" << endl;

}

void IntSorting::MS(vector<int> &arr, int left, int right) {
    if(left < right){
        int mid = left + (right - left) /2;

        MS(arr, left, mid);
        MS(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

}

void IntSorting::MergeSort(vector<int> &arr) {
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

void IntSorting::merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

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

void IntSorting::HS(vector<int> &arr) {
    int n = arr.size();
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--){
        swap (arr, 0, i);
        heapify(arr, i, 0);
    }
}

void IntSorting::heapify(vector<int> &arr, int n, int i) {
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[max]){
        max = l;
    }

    if(r < n && arr[r] > arr[max]){
        max = r;
    }

    if(max != i){
        swap(arr, i, max);

        heapify(arr, n, max);
    }
}

void IntSorting::HeapSort(vector<int> &arr) {
    LARGE_INTEGER frequency;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    HS(arr);

    QueryPerformanceCounter(&end);
    double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;

    cout << "Czas sortowania: " << elapsedTime << " ms" << endl;
}
