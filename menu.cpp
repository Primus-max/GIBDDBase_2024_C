#include "menu.h"

#define COLOR_BLUE "\033[94m"
#define COLOR_GREEN "\033[92m"
#define COLOR_RESET "\033[0m"

const string menuList[] =
{
	"Добавить авто",
	"Удалить авто",
	"Найти по номеру",
	"Найти по цвету",
	"Сортировать по объёму",
	"Сортировать по мощности",
	"Сортировать по номеру",
	"Добавить штраф",
	"Удалить штраф",
	"Считать штрафы авто",
	"Показать все машины",
	"Показать машину",
	"Показать машины с кол-вом штрафов"
};



void drawFrame(int width, int height){

	cout << COLOR_BLUE;
	// Верхняя горизонтальная линия
	int half = (width - 2) / 2;
	const char*  menu = { "Меню" };
	cout << '+';
	for (size_t i = 0; i < width - 2; ++i) {
		if (i == half) {
			cout << menu;
			i = i + 4;
		}
		cout << '-';
	}		
	cout << '+' << endl;

	// Вертикальные линии
	
	for (size_t i = 0; i < height - 2; i++)	{
		cout << '|';
		for (size_t j = 0; j < width - 2; ++j)
			cout << ' ';
		cout << '|' << endl;
	}

	// Нижняя линия
	cout << '+';
	for (size_t i = 0; i < width - 2; i++)
		cout << '-';
	cout << '+' << endl;

	cout << COLOR_RESET;
}

void drawButtons(){
	
	for (rsize_t i = 0; i < menuList->length(); ++i) {
		string item = menuList[i];
		ButtonCoord coord = calcCoordMenuItem(item, menuList[i - 1].length(), i);
		cout << "\033[" << coord.y << ";" << coord.x << "H";
		cout << COLOR_GREEN << "[" << COLOR_RESET << (i + 1) << ". " << item << COLOR_GREEN "]" << COLOR_RESET;
	}	
}

ButtonCoord calcCoordMenuItem(string& menuItem, int lastSize, int index)
{
	ButtonCoord coord;
	const short plusSize = 4; // Длина скобок, точки, пробела
	short sizeButton = menuItem.length() + (index + 1) + plusSize;
	coord.x =  lastSize == 0 ? 4 : lastSize + sizeButton + 1; // 1 - это пробел между кнопками
	size_t half = menuList->length() / 2;
	coord.y = index == half ? 4 : 2;
	
	return coord;
}

