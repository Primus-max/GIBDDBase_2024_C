#pragma once
#include <string>
#include <iostream>
using namespace std;

struct  ButtonCoord
{
	short x = 0;
	short y = 0;
};

void drawFrame(int width, int height);
void drawButtons();
ButtonCoord calcCoordMenuItem(string& menuItem, int lastSize, int index);