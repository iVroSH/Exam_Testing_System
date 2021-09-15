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
	void createAcc() {
		//-------------------------------//
		string pass2, buff;
		hash<string> Hash;
		ifstream in;
		ofstream out;
		long long key;
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
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				login = getFixLenStr(15);
				key = Hash(login);
				buff = to_string(key);
				in.open(buff + ".txt");
				if (!in.is_open()) { Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + login; }
				else {
					Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " Этот логин занят"; in.close();
				}
			}break;
			case 1: {
				gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
				pass = getFixLenStr(15,1);
				string a; for (size_t i = 0; i < pass.size(); i++) { a.push_back('*'); }
				Menu::lvl--;  MenuCreateAcc.menu[inPos] = vectorCreateAcc[inPos] + " " + a;
			}
			case 2: break;
			default: Menu::lvl -= 2; return;
				break;
			}
			//-------------------------------//

			/*cin >> login;
			key = Hash(login);
			buff = to_string(key);
			in.open(buff + ".txt");
			if (!in.is_open()) {
				cin >> pass;
				cin >> pass2;
				if (pass == pass2) {


					cin >> FName;
					cin >> Name;
					cin >> Otchestvo;

					if (ADMIN) {
						out.open("AccList.txt", ios_base::app);
						out << login << endl;
						out.close();
						out.open(buff + ".txt");
					}
					else {
						out.open("Requests.txt", ios_base::app);
						out << key << endl;
					}
					out << (key = Hash(pass)) << endl << (key + (key = Hash(login))) + !ADMIN << endl << FName << endl << Name << endl << Otchestvo << endl;
					out.close();
				}

			}
			else {
				cout << "This login is taken !";
			}*/
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
