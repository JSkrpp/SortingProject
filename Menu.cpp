//
// Created by Admin on 29.03.2024.
//

#include "Menu.h"
#include <iostream>
#include "IntSorting.h"
#include <vector>
#include "Generator.h"
#include "badania.h"
#include "FloatSorting.h"
#include "DoubleSorting.h"
using namespace std;

void Menu::Show(vector<int> &arr, vector <float> &flo, vector<double> &dub) {
        int choice;
        cout << "1. Zaladuj tablice" << endl;
        cout << "2. Generuj losowa tablice" << endl;
        cout << "3. Wyswietl tablice" << endl;
        cout << "4. Posortuj tablice" << endl;
        cout << "5. Przeprowadz badanie tablicy int w pelni losowej" << endl;
        cout << "6. Przeprowadz badanie tablicy int w 50%" << endl;
        cout << "7. Przeprowadz badanie tablicy int posortowanej" << endl;
        cout << "8. Przeprowadz badanie MergeSort tablicy float" << endl;
        cout << "9. Przeprowadz badanie MergeSort tablicy double" << endl;
        cout << "10. Wyjdz z programu" << endl;
        cin >> choice;
        Execute(choice, arr, flo, dub);
}


void Menu::Execute(int choice, vector<int> &arr, vector<float> &flo, vector<double> &dub) {
    Badania badanie;
    Generator generator;
    switch (choice) {
        case 1:
            generator.LoadDataFromFile(arr);
            Show(arr, flo, dub);
            break;
        case 2:
            GenTable(arr, flo, dub);
            Show(arr, flo, dub);
            break;
        case 3:
            printArray(arr, flo, dub);
            Show(arr, flo, dub);
            break;
        case 4:
            SortingMenu(arr, flo, dub);
            Show(arr, flo, dub);
            break;
        case 5:
            TestMenuIntRand(arr);
            Show(arr, flo, dub);
            break;
        case 6:
            TestMenuInt50(arr);
            Show(arr, flo, dub);
            break;
        case 7:
            TestMenuIntSort(arr);
            Show(arr, flo ,dub);
            break;
        case 8:
            badanie.MergeSortFloat(flo);
            Show(arr,flo,dub);
            break;
        case 9:
            badanie.MergeSortDouble(dub);
            Show(arr, flo, dub);
            break;
        case 10:
            SaveFile(arr);
            return;
        default:
            Show(arr, flo, dub);
            break;
    }
}


void Menu::printArray(vector<int> &arr, vector<float> &flo, vector<double> &dub) {
    int choice;
    cout << "1. int" << endl;
    cout << "2. float" << endl;
    cout << "3. double" << endl;
    cin >> choice;
    switch (choice) {
        case 1:
            for (int i: arr) {
                cout << i << " ";
            }
            cout << endl;
            isSorted(arr);
            break;
        case 2:
            for (int i = 0; i<flo.size(); i++) {
                cout << flo[i] << " ";
            }
            cout << endl;
            isSorted(flo);
            break;
        case 3:
            for (int i = 0; i<dub.size(); i++){
                cout << dub[i] << " ";
            }
            cout << endl;
            isSorted(dub);
            break;
        default:
            printArray(arr, flo, dub);
            break;

    }
}

    void Menu::SortingMenu(vector<int> &arr, vector<float> &flo, vector<double> &dub) {
        int choice;
        cout << "1. Sortowanie Szybkie" << endl;
        cout << "2. Sortowanie przez kopcowanie" << endl;
        cout << "3. Sortowanie przez wstawienie" << endl;
        cout << "4. Sortowanie przez scalanie" << endl;
        cout << "5. Sortowanie float przez scalanie" << endl;
        cout << "6. Sortowanie double przez scalanie" << endl;
        cin >> choice;
        ChooseSort(arr, choice, flo, dub);
    }

    void Menu::ChooseSort(vector<int> &arr, int choice, vector<float> &flo, vector<double> &dub) {
        IntSorting intSorter;
        FloatSorting floatSorter;
        DoubleSorting doubleSorter;
        switch (choice) {
            case 1:
                intSorter.QuickSort(arr);
                isSorted(arr);
                break;
            case 2:
                intSorter.HeapSort(arr);
                isSorted(arr);
                break;
            case 3:
                intSorter.InsertionSort(arr);
                isSorted(arr);
                break;
            case 4:
                intSorter.MergeSort(arr);
                isSorted(arr);
                break;
            case 5:
                floatSorter.MergeSort(flo);
                isSorted(flo);
                break;
            case 6:
                doubleSorter.MergeSort(dub);
                isSorted(dub);
                break;
            default:
                SortingMenu(arr, flo, dub);
        }
    }
    void Menu::GenTable(vector<int> &arr, vector<float> &flo, vector<double> &dub) {
        Generator generator;
        int ilosc;
        int type;
        cout << "Podaj dlugosc tabeli: ";
        cin >> ilosc;
        cout << "1. Tablica int losowa. " << endl;
        cout << "2. Tablica int 50%. " << endl;
        cout << "3. Tablica int posortowana. " << endl;
        cout << "4. Tablica float losowa. " << endl;
        cout << "5. Tablica double losowa. " << endl;
        cout << "Podaj typ tablcy: " << endl;
        cin >> type;

        switch (type) {
            case 1:
                generator.GenVectorIntRand(arr, ilosc);
                break;
            case 2:
                generator.GenVectorInt50(arr, ilosc);
                break;
            case 3:
                generator.GenVectorIntSort(arr, ilosc);
                break;
            case 4:
                generator.GenVectorFloat(flo, ilosc);
                break;
            case 5:
                generator.GenVectorDouble(dub, ilosc);
                break;
        }
    }

    void Menu::TestMenuIntRand(vector<int> &arr) {
        int choice;
        cout << "1. Sortowanie Szybkie" << endl;
        cout << "2. Sortowanie przez kopcowanie" << endl;
        cout << "3. Sortowanie przez wstawienie" << endl;
        cout << "4. Sortowanie przez scalanie" << endl;
        cin >> choice;
        ChooseTestIntRand(arr, choice);
    }

    void Menu::ChooseTestIntRand(vector<int> &arr, int choice) {
        Badania badanie;
        switch (choice) {
            case 1:
                badanie.QuickSortIntRand(arr);
                break;
            case 2:
                badanie.HeapSortIntRand(arr);
                break;
            case 3:
                badanie.InsertionSortIntRand(arr);
                break;
            case 4:
                badanie.MergeSortIntRand(arr);
                break;
        }
    }

    void Menu::TestMenuInt50(vector<int> &arr) {
        int choice;
        cout << "1. Sortowanie Szybkie" << endl;
        cout << "2. Sortowanie przez kopcowanie" << endl;
        cout << "3. Sortowanie przez wstawienie" << endl;
        cout << "4. Sortowanie przez scalanie" << endl;
        cin >> choice;
        ChooseTestInt50(arr, choice);
    }

    void Menu::ChooseTestInt50(vector<int> &arr, int choice) {
        Badania badanie;
        switch (choice) {
            case 1:
                badanie.QuickSortInt50(arr);
                break;
            case 2:
                badanie.HeapSortInt50(arr);
                break;
            case 3:
                badanie.InsertionSortInt50(arr);
                break;
            case 4:
                badanie.MergeSortInt50(arr);
                break;
        }
    }

void Menu::TestMenuIntSort(vector<int> &arr) {
    int choice;
    cout << "1. Sortowanie Szybkie" << endl;
    cout << "2. Sortowanie przez kopcowanie" << endl;
    cout << "3. Sortowanie przez wstawienie" << endl;
    cout << "4. Sortowanie przez scalanie" << endl;
    cin >> choice;
    ChooseTestIntSort(arr, choice);
}

void Menu::ChooseTestIntSort(vector<int> &arr, int choice) {
    Badania badanie;
    switch (choice) {
        case 1:
            badanie.QuickSortIntSort(arr);
            break;
        case 2:
            badanie.HeapSortIntSort(arr);
            break;
        case 3:
            badanie.InsertionSortIntSort(arr);
            break;
        case 4:
            badanie.MergeSortIntSort(arr);
            break;
    }
}

void Menu::SaveFile(vector<int> &arr) {
    Generator generator;
    int choice1;
    cout << "Czy chcesz zapisac dane do pliku? " << endl;
    cin >> choice1;

    switch (choice1){
        case 1:
            generator.SaveToFile(arr);
            break;
        case 2:
            return;
        default:

            SaveFile(arr);
    }
}

template <typename T> void Menu ::isSorted(vector<T> &arr){
    bool issort = true;
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] < arr[i-1]){
            issort = false;
        }
    }
    if (!issort){
        cout << "Nieposortowana" << endl;
    }
    else cout << "Posortowana" << endl;
}

