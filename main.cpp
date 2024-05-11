#include <iostream>
#include "Menu.h"
#include <vector>

using namespace std;

int main() {
    vector<int> arr;
    vector<float> flo;
    vector <double> dub;
    Menu menu;
    menu.Show(arr, flo, dub);
    return 0;
}
