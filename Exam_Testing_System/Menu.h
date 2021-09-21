#pragma once

using namespace std;

struct Menu
{
	vector<string> textLeft;
	vector<string> textRight;
private:
	string width;
	size_t pos=0;
	size_t size;
	void CreateArea(string title, size_t& x, size_t& y, size_t n) {
		size = 0;
		size = title.size();
		for (size_t i = 0; i < textLeft.size(); i++)
			if (size < textLeft[i].length())size = textLeft[i].length();
		size += 6;
		system("cls");
		SetColor(0, 8);
		for (size_t j = 0; j < n; j++) {
			for (size_t i = 0; i < textLeft.size() + 7; i++) {
				gotoxy(x + j, 2 + i + j + y);
				if (i == 0) { Symbol(201); Symbol(205, size); Symbol(187); }
				else
					if (i == textLeft.size() + 6) { Symbol(200); Symbol(205, size); Symbol(188); }
					else {
						Symbol(186); Symbol(' ', size); Symbol(186);
					}
			}
		}
		SetColor(8, 0);		gotoxy(x + n + 1, y + n + 3);		Symbol(' ', size - 2);
		/*           */		gotoxy(x + n + 3 + ((size - title.size()) - 6) / 2, y + n + 3);		ru(); cout << title; ru();
		SetColor(0, 8);		gotoxy(x + n + 2, y + n + 2);		Symbol(220, size - 4);
		/*           */		gotoxy(x + n + 2, y + n + 4);		Symbol(223, size - 4);
		/*           */		gotoxy(x + n, y + n + 5);			Symbol('`', size);
	}
public:
	int select_vertical(string title, size_t x = x, size_t y = y, size_t n = lvl) {
		textRight.resize(textLeft.size(), "");
		this->x = x;
		this->y = y;
		if (n < 1) n = 1;
		this->lvl = n + 1;
		CreateArea(title, x, y, n);
		width.resize(size - 4, ' ');
		
		char c;
		do {
			Sleep(1);
			ru();
			for (int i = 0; i < textLeft.size(); i++) {
				if (i == pos) {
					SetColor(0, 7);
					gotoxy(x + n + 2, y + n + 6 + i); cout << width;
					gotoxy(x + n + 2, y + n + 6 + i); cout << " " + textLeft[i] + " "+textRight[i] << endl;
					SetColor(0, 9);
				}
				else {
					SetColor(7, 8);
					gotoxy(x + n + 2, y + n + 6 + i); cout << width;
					gotoxy(x + n + 2, y + n + 6 + i); cout << textLeft[i] +" " + textRight[i] << endl;
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
				if (pos < textLeft.size() - 1)
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
	//------------------------------------------------------------------------------------------------------------------//
	static size_t x, y, lvl;
};
size_t Menu::x = 0, Menu::y = 0, Menu::lvl = 1;

//¬о всех switch-ах меню (за исключением стартового) должна быть это строка  default: Menu::lvl -= 2; return;  дл€ красивой работы с приложением