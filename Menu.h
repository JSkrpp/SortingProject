//
// Created by Admin on 29.03.2024.
//

#ifndef AIZO_1_MENU_H
#define AIZO_1_MENU_H
#include <iostream>
#include <vector>
using namespace std;

class Menu {
    public:
        void Show(vector<int> &arr, vector<float> &flo, vector<double> &dub);

    public:
        void Execute(int choice, vector<int>&arr, vector <float> &flo, vector<double> &dub);

        void printArray (vector<int> &arr, vector<float> &flo, vector<double> &dub);

    void SortingMenu(vector<int> &arr, vector<float> &flo, vector<double> &dub);

    void ChooseSort(vector<int> &arr, int choice, vector<float> &flo, vector<double> &dub);

    void GenTable(vector<int> &arr, vector<float> &flo, vector <double> &dub);

    void TestMenuIntRand(vector<int> &arr);

    void ChooseTestIntRand(vector<int> &arr, int choice);

    void ChooseTestInt50(vector<int> &arr, int choice);

    void TestMenuInt50(vector<int> &arr);

    void ChooseTestIntSort(vector<int> &arr, int choice);

    void TestMenuIntSort(vector<int> &arr);

    template <typename T> void isSorted(vector<T> &arr);

    void SaveFile(vector<int> &arr);

};


#endif //AIZO_1_MENU_H
