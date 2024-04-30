#include "menu.h"
#include <vector>

#define COLOR_BLUE "\033[94m"
#define COLOR_GREEN "\033[92m"
#define COLOR_RESET "\033[0m"

const string menuList[] =
{
	"�������� ����",
	"������� ����",
	"����� �� ������",
	"����� �� �����",
	"����������� �� ������",
	"����������� �� ��������",
	"����������� �� ������",
	"�������� �����",
	"������� �����",
	"������� ������ ����",
	"�������� ��� ������",
	"�������� ������",
	"�������� ������ � ���-��� �������"
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
	// ������� �������������� �����
	int half = (width - 2) / 2;
	const char* menu = { "����" };
	cout << '+';
	for (size_t i = 0; i < width - 2; ++i) {
		if (i == half) {
			cout << menu;
			i = i + 4;
		}
		cout << '-';
	}
	cout << '+' << endl;

	// ������������ �����

	for (size_t i = 0; i < height - 2; i++) {
		cout << '|';
		for (size_t j = 0; j < width - 2; ++j)
			cout << ' ';
		cout << '|' << endl;
	}

	// ������ �����
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

	// ��������� ����� ������ ������ �� ������� ������
	for (size_t i = 0; i < idx; i++)
		totalX += coords[i].size;

	const short plusSize = 4; // ����� ������, �����, �������
	const short margin = 4;

	// ���������, ���� ��� �������� ����, �� ��������� �� ����� ������
	if (index == half) {
		coord.x = 4; // �������� � ������ ������ ������
		coord.y = 4; // ��������� �� ����� ������
	}
	else {
		// ���� �� �������� ����, ���������� �� ������� ������
		coord.x = totalX == 0 ? 4 : totalX + plusSize * coords.size() + margin;
		// ��������� ������� ������ ��� ���������� y
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