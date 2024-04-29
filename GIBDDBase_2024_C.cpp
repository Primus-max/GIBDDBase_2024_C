

#include <iostream>
#include <windows.h>
#include "car.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Car car;
    Penalty penl;
    car.penalties.push_back(penl);

    cout << "Hello World!\n";
}
