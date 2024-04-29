#pragma once
#include "penalty.h"
#include <string>
#include <vector>
using namespace std;

struct Car
{
    int id = 0;
    string brand = "";

    // �������������� ����������
    short length = 0;
    short clearance = 0;
    short engineCapacity = 0;
    short enginePower = 0;
    short wheelDiameter = 0;

    // ��������������� ������
    string number = "";
    short region = 0;

    // ���� ����������
    string carColor = "";

    // ������ �������
    vector<Penalty> penalties;
};