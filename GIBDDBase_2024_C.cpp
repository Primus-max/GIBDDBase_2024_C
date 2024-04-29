

#include <iostream>
#include <windows.h>
#include "car.h"
#include "penaltyTypeStrings.h"
#include "menu.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    drawFrame(100, 10);
    drawButtons();
}
