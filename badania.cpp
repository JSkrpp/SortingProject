//
// Created by Admin on 18.04.2024.
//

#include <windows.h>
#include "badania.h"
#include "IntSorting.h"
#include "Generator.h"
#include "FloatSorting.h"
#include "DoubleSorting.h"
#include <vector>

using namespace std;

void Badania::QuickSortIntRand(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
        vector<int> vector1;
        for(int j = 1; j <= wielkosc; j++) {
            generator.GenVectorIntRand(arr, j * 100000);
            for (int i = 0; i < ilosc; i++) {
                vector1 = arr;
                LARGE_INTEGER frequency;
                LARGE_INTEGER start;
                LARGE_INTEGER end;

                QueryPerformanceFrequency(&frequency);
                QueryPerformanceCounter(&start);

                int size = arr.size();
                intSorting.QS(vector1, 0, size - 1);

                QueryPerformanceCounter(&end);
                double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
                totalTime += elapsedTime;
            }
            totalTime = totalTime / ilosc;
            cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
        }

}

void Badania::QuickSortInt50(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorInt50(arr, j * 100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            int size = arr.size();
            intSorting.QS(arr, 0, size - 1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }

}

void Badania::InsertionSortIntRand(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorIntRand(arr, j * 10000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.IS(arr);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "0000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::MergeSortIntRand(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        generator.GenVectorIntRand(arr, j * 100000);
        for (int i = 0; i < ilosc; i++) {
            vector1 = arr;
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            int size = arr.size();
            intSorting.MS(vector1, 0, size - 1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }

}

void Badania::HeapSortIntRand(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        generator.GenVectorIntRand(arr, j * 100000);
        for (int i = 0; i < ilosc; i++) {
            vector1 = arr;
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.HS(vector1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::MergeSortFloat(vector<float> &flo) {
    Generator generator;
    FloatSorting floatSorter;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorFloat(flo, j * 100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            int size = flo.size();
            floatSorter.MS(flo, 0, size - 1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::MergeSortDouble(vector<double> &dub) {
    Generator generator;
    DoubleSorting doubleSorter;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    for(int j = 1; j <= wielkosc; j++){
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorDouble(dub, j * 100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            int size = dub.size();
            doubleSorter.MS(dub, 0, size - 1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

int Badania::getAmount() {
    int wielkosc;
    cout << "Podaj ilosc iteracji wykonania badan (kazda iteracja zwieksza ilosc danych o 100000) " << endl;
    cin >> wielkosc;
    return wielkosc;
}

int Badania::getTestNumber() {
    int ilosc;
    cout << "Podaj ilosc badan: ";
    cin >> ilosc;
    return ilosc;
}

void Badania::InsertionSortInt50(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorInt50(arr, j * 10000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.IS(arr);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::InsertionSortIntSort(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        generator.GenVectorIntSort(arr, j*100000);
        for (int i = 0; i < ilosc; i++) {
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.IS(arr);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::HeapSortIntSort(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorIntSort(arr, j*100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.HS(arr);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::QuickSortIntSort(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorIntSort(arr, j*100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.QS(arr, 0, arr.size()-1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::MergeSortIntSort(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorIntSort(arr, j*100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.MS(arr, 0, arr.size()-1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::MergeSortInt50(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorInt50(arr, j*100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.MS(arr, 0, arr.size()-1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}

void Badania::HeapSortInt50(vector<int> &arr) {
    Generator generator;
    IntSorting intSorting;
    int wielkosc = getAmount();
    int ilosc = getTestNumber();
    double totalTime;
    vector<int> vector1;
    for(int j = 1; j <= wielkosc; j++) {
        for (int i = 0; i < ilosc; i++) {
            generator.GenVectorInt50(arr, j*100000);
            LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency);
            QueryPerformanceCounter(&start);

            intSorting.MS(arr, 0, arr.size()-1);

            QueryPerformanceCounter(&end);
            double elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart * 1000;
            totalTime += elapsedTime;
        }
        totalTime = totalTime / ilosc;
        cout << "Ilosc danych: " << j << "00000, sredni czas: " << totalTime << " ms." << endl;
    }
}




