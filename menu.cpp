#include "menu.h"
#include <vector>

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

vector<Button> coords;

void initMenu()
{
	for (size_t i = 0; i < menuList->length(); i++){
		string button = menuList[i];


		Button coord = calcCoordMenuItem(button, i);
		coords.push_back(coord);
		drawButton(coord.x, coord.y, button);
	}
}

void drawFrame(int width, int height) {

	cout << COLOR_BLUE;
	// Верхняя горизонтальная линия
	int half = (width - 2) / 2;
	const char* menu = { "Меню" };
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

	for (size_t i = 0; i < height - 2; i++) {
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

void drawButton(int x, int y, string& menuItem) {
	cout << "\033[" << y << ";" << x << "H";
	cout << COLOR_GREEN << "[" << COLOR_RESET << menuItem << COLOR_GREEN "]" << COLOR_RESET;

}

Button calcCoordMenuItem(string& menuItem, int index) {
	Button coord;
	int totalX = 0;

	size_t half = menuList->length() / 2;
	int idx = index >= half ? 0 : index;

	// Вычисляем общую ширину кнопок на текущей строке
	for (size_t i = 0; i < idx; i++)
		totalX += coords[i].size;

	const short plusSize = 4; // Длина скобок, точки, пробела
	const short margin = 4;

	// Проверяем, если это половина меню, то переходим на новую строку
	if (index == half) {
		coord.x = 4; // Начинаем с самого начала строки
		coord.y = 4; // Переходим на новую строку
	}
	else {
		// Если не половина меню, продолжаем на текущей строке
		coord.x = totalX == 0 ? 4 : totalX + plusSize * coords.size() + margin;
		// Учитываем текущую строку для координаты y
		coord.y = coords.empty() ? 2 : coords.back().y;
	}

	coord.id = index;
	coord.size = menuItem.length();

	return coord;
}



void drawMenu() {

	drawFrame(100, 10);

	int totalLength = 0;
	int halfMenu = menuList->length() / 2;

	for (size_t i = 0; i < menuList->length(); i++)	{
		

		string button = menuList[i];
		totalLength += i == 0 ? 0 : menuList[i - 1].length() + 4;

		Button coord = calcCoordMenuItem(button, i);
		
		drawButton(coord.x, coord.y, button);

		if (i == halfMenu) {
			i = 0;
			totalLength = 0;
		}
	}
}