#pragma once
#include "penalty.h"
#include <string>
#include <vector>
using namespace std;

struct Car
{
    int id = 0;
    string brand = "";

    // Характеристики автомобиля
    short length = 0;
    short clearance = 0;
    short engineCapacity = 0;
    short enginePower = 0;
    short wheelDiameter = 0;

    // Регистрационные данные
    string number = "";
    short region = 0;

    // Цвет автомобиля
    string carColor = "";

    // Список штрафов
    vector<Penalty> penalties;
};