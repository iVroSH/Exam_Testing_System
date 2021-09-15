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
string getFixLenStr(int len, bool protect = 0) {
	string buff;
	bool stop = 0;
	char in;
	do {
		while (buff.size() < len) {
			in = _getch();
			SetColor(0, 8);
			if (protect)cout << '*'; else cout << in;
			SetColor(7, 0);
				if (in == 13) {
					stop = 1; break;
				}
			buff.push_back(in);
		}
	} while (!stop && _getch() != 13);
	return buff;
}

