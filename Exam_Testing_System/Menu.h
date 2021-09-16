#pragma once

using namespace std;

struct Menu
{
	vector<string> menu;
private:
	size_t len;
	string st;
	void CreateArea(string title, size_t& x, size_t& y, size_t n) {
		int size = title.size();
		for (size_t i = 0; i < menu.size(); i++)
			if (size < menu[i].length())size = menu[i].length();
		size += 6;
		system("cls");
		SetColor(0, 8);
		for (size_t j = 0; j < n; j++) {
			for (size_t i = 0; i < menu.size() + 7; i++) {
				gotoxy(x + j, 2 + i + j + y);
				if (i == 0) { Symbol(201); Symbol(205, size); Symbol(187); }
				else
					if (i == menu.size() + 6) { Symbol(200); Symbol(205, size); Symbol(188); }
					else {
						Symbol(186); Symbol(' ', size); Symbol(186);
					}
			}
		}
		SetColor(8, 0);		gotoxy(x + n + 1, y + n + 3);		Symbol(' ', size - 2);
		SetColor(0, 8);		gotoxy(x + n + 2, y + n + 2);		Symbol(220, size - 4);
		SetColor(0, 8);		gotoxy(x + n + 2, y + n + 4);		Symbol(223, size - 4);
		SetColor(8, 0);		gotoxy(x + n + 3, y + n + 3);		ru(); cout << title; ru();
		SetColor(0, 8);		gotoxy(x + n, y + n + 5);			Symbol('`', size);
	}
public:
	size_t buttonSize = 0;
	int select_vertical(string title, size_t x = x, size_t y = y, size_t n = lvl) {
		this->x = x;
		this->y = y;
		if (n < 1) n = 1;
		this->lvl = n + 1;
		CreateArea(title, x, y, n);
		st.resize(buttonSize, ' ');
		char c;
		int pos = 0;
		do {
			ru();
			for (int i = 0; i < menu.size(); i++) {
				if (i == pos) {
					SetColor(0, 7);
					gotoxy(x + n + 2, y + n + 6 + i); cout << st;
					gotoxy(x + n + 2, y + n + 6 + i); cout << " " + menu[i] + " " << endl;
					SetColor(0, 9);
				}
				else {
					SetColor(7, 8);
					gotoxy(x + n + 2, y + n + 6 + i); cout << st;
					gotoxy(x + n + 2, y + n + 6 + i); cout << menu[i] + "  " << endl;
					SetColor(8, 7);
				}
			}
			c = _getch();
			switch (c)
			{
			case 72:
				if (pos > 0)
					pos--;
				break;
			case 80:
				if (pos < menu.size() - 1)
					pos++;
				break;
			case 13:
				break;

			default:
				break;
			}
			ru();
		} while (c != 13);
		SetColor(7, 0);
		return pos;
	}

	int select_gorizontal()
	{
		int max_len = 0;
		for (int i = 0; i < menu.size(); i++)
			max_len += menu[i].length();
		if (max_len > 80 - menu.size() - 1)
			int a = 1;
	}

	static size_t x, y, lvl;
};
size_t Menu::x = 0, Menu::y = 0, Menu::lvl = 1;

//¬о всех switch-ах меню (за исключением стартового) должна быть это строка  default: Menu::lvl -= 2; return;  дл€ красивой работы с приложением