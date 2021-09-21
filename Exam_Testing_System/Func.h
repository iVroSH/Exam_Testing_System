#pragma once
//////////////////////////////////////////////////////
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//////////////////////////////////////////////////////
void SetColor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
//////////////////////////////////////////////////////
void endl(int n = 1) {
	for (size_t i = 0; i < n; i++)
		cout << endl;
}
//////////////////////////////////////////////////////
void Symbol(int a, int b = 1) {
	for (size_t i = 0; i < b; i++)
		cout << (char)a;
}
//////////////////////////////////////////////////////
void CheckSymbols() {
	for (size_t i = 1; i <= 255; i++)
		cout << (char)i << " " << i << endl;
}
//////////////////////////////////////////////////////
void ru() {
	int a = GetConsoleCP(), b = GetConsoleOutputCP();
	if (a == 866 || b == 866) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		return;
	}
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
}
//////////////////////////////////////////////////////

void StringSymbolFilter(string& str, string filter= "!@#$%^&*()-=_+[]{};:\'\"\\|,./<>?`~") {
	bool flag;
	string buff = "";
	for (size_t i = 0; i < str.size(); i++) {
		flag = true;
		for (size_t j = 0; j < filter.size(); j++) {
			if (str[i] == filter[j]) {
				flag = false;
				break;
			}
		}
		if (flag)buff += str[i];
	}
	str = buff;
}
string getFixLenStr(int len, bool protect = 0) {
	string buff;
	bool stop = FALSE;
	char in;
	do {
		while (buff.size() < len) {
			in = _getch();
			if (in == 8) {
				if (buff.size() > 0)
				{
					buff.pop_back();
					SetColor(0, 7); cout << "\b \b";
				}
				else continue;
			}
			else {
				SetColor(0, 7);
				if (protect)cout << '*'; else cout << in;
				SetColor(7, 0);
				if (in == 13) {
					stop = TRUE; break;
				}
				buff.push_back(in);
			}
		}
	} while (!stop && _getch() != 13);
	return buff;
}

