#pragma once


struct Account {
	string login;
	string pass;
	string FName;
	string Name;
	string Otchestvo;
	bool ADMIN = FALSE;
	void goToButton(Menu m, int pos) {}
public:
	Account() { fstream firstOpen("AccList.txt"); if (!firstOpen.is_open()) { ADMIN = TRUE; cout << "Create Admin Account :"; createAcc(); } }

	void Registration_Requests() {

	}

	void addAcc() {
		hash<string> Hash;
		long long key;
		ofstream out;
		out.open("AccList.txt", ios_base::app);
		out << login << endl;
		key = Hash(login);
		out.close();
		out.open(to_string(key) + ".txt", ios_base::app);
		out << key << endl;
		key = Hash(pass);
		out << to_string(key) << endl;
		out << FName << endl;
		out << Name << endl;
		out << Otchestvo;
		out.close();
	}
	void createAcc() {
		//-------------------------------//
		hash<string> Hash;
		long long key;
		string pass2, buff;
		vector<bool> verify{ 0,0,0,0,0,0 };
		//-------------------------------//
		vector<string> vectorCreateAcc = {
			"Введите логин      :",
			"Введите пароль     :",
			"Повторите пароль   :",
			"Введите фамилию    :",
			"Введите имя        :",
			"Введите отчество   :",
			"Создать аккаунт    :",
			"Exit"
		};
		Menu MenuCreateAcc;
		MenuCreateAcc.menu = vectorCreateAcc;
		do
		{
			//-------------------------------//
			int inPos = MenuCreateAcc.select_vertical("          Создание Аккаунта          ");
			switch (inPos) {
			case 0: {
				ifstream in;
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				login = getFixLenStr(15);
				key = Hash(login);
				buff = to_string(key);
				in.open(buff + ".txt");
				if (!in.is_open()) { Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + login; verify[inPos] = TRUE; }
				else { Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " Этот логин занят"; in.close(); verify[inPos] = FALSE; }
			}break;
			case 1: {
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				pass2 = getFixLenStr(15, 1); verify[inPos] = TRUE;
				string a; for (size_t i = 0; i < pass2.size(); i++) { a.push_back('*'); }
				Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + a;
			}break;
			case 2: {gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				pass = getFixLenStr(15, 1);
				string a; for (size_t i = 0; i < pass.size(); i++) { a.push_back('*'); }
				if (pass == pass2)verify[inPos] = TRUE; else { a = "Пароли не совпадают"; verify[inPos] = FALSE; }
				Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + a; } break;
			case 3: {
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				ru(); FName = getFixLenStr(15); ru(); verify[inPos] = TRUE;
				Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + FName;
			}break;
			case 4: {
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				ru(); Name = getFixLenStr(15); ru(); verify[inPos] = TRUE;
				Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + Name;
			}break;
			case 5: {
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				ru(); Otchestvo = getFixLenStr(15); ru(); verify[inPos] = TRUE;
				Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + Otchestvo;
			}break;
			case 6: {
				string a;  if (find(verify.begin(), verify.end(), 0) != verify.end()) a = "Неверные данные";
				else {
					if (ADMIN) {
						addAcc();
						system("cls"); ru(); cout << "Аккаунт администратора создан";
						Sleep(1000);
						exit(0);
					}
					else {
						ofstream out("Applications.txt");
						out << login << endl;
						out << pass << endl;
						out << FName << endl;
						out << Name << endl;
						out << Otchestvo;
						a = "Заявка отправлена";
						out.close();
					}
				}
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + a;
			}break;
			default: Menu::lvl -= 2; if (ADMIN) { system("cls"); exit(0); }return;
				break;
			}
		} while (true);
	}

	void loadAcc() {
		string str;
		hash<string> Hash;
		cin >> str;
		long long key = Hash(str), key2;
		ifstream in(key + ".txt");
		if (in.is_open()) {
			cin >> str;
			key2 = Hash(str);
			in >> key;
			if (key == key2) {

			}
			else cout << "Wrong password!!!";
		}
		else { cout << "Account not found!!!"; }
	}
	void menu() {
		ru();
		Menu MenuStart;
		MenuStart.menu = {
			"Создать аккаунт",
			"Войти в аккаунт",
			"Закрыть приложение",
		};
		ru();
		do {
			int inPos = MenuStart.select_vertical("Система тестирования", 45, 2, 1);
			switch (inPos)
			{
			case 0:createAcc(); break;
			case 1:loadAcc(); break;
			case 2: break;
			default:
				break;
			}

		} while (true);

	}

};
