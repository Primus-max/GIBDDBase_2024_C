#pragma once
#include <string>
#include <iostream>
using namespace std;

struct  Button
{
	short id = 0;
	short x = 0;
	short y = 0;
	short size = 0;
};

void initMenu();
void drawFrame(int width, int height);
void drawButton(int x, int y, string& menuItem);
void drawMenu();

Button calcCoordMenuItem(string& menuItem, int index);