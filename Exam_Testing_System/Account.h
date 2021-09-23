#pragma once


struct Account {
	string login;
	string pass;
	string FName;
	string Name;
	string Otchestvo;
	bool ADMIN = FALSE;
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
		out.close();
		key = Hash(login);
		out.open(to_string(key) + ".txt");
		out << key << endl;
		key = Hash(pass);
		out << to_string(key) << endl;
		key = Hash(to_string(ADMIN));
		out << key << endl;
		out << FName << endl;
		out << Name << endl;
		out << Otchestvo << endl;
		out.close();
	}
	void createAcc() {
		//-------------------------------//
		hash<string> Hash;
		long long key;
		string pass2, buff, text;
		vector<bool> verify{ 0,0,0,0,0,0 };
		//-------------------------------//
		Menu MenuCreateAcc;
		MenuCreateAcc.textLeft = {
			"Введите логин      :",
			"Введите пароль     :",
			"Повторите пароль   :",
			"Введите фамилию    :",
			"Введите имя        :",
			"Введите отчество   :",
			"Создать аккаунт    :",
			"Exit"
		};
		do
		{
			int inPos = MenuCreateAcc.select_vertical("          Создание Аккаунта          ");
			text = "";
			gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
			SetColor(0, 7);
			for (size_t i = 0; i < 15; i++)
				cout << ' ';
			for (size_t i = 0; i < 15; i++)
				cout << "\b \b";
			ru();
			switch (inPos) {
				//-------------------------------//
			case 0:
			{
				ifstream in;
				login = getFixLenStr(15);
				key = Hash(login);
				buff = to_string(key);
				in.open(buff + ".txt");
				if (!in.is_open()) { text = login; verify[inPos] = TRUE; }
				else { text = " Этот логин занят"; in.close(); verify[inPos] = FALSE; }
			}break;
			//-------------------------------//
			case 1:
			{
				pass2 = getFixLenStr(15, 1); verify[inPos] = TRUE;
				for (size_t i = 0; i < pass2.size(); i++) { text.push_back('*'); }
			}break;
			//-------------------------------//
			case 2:
			{
				pass = getFixLenStr(15, 1);
				for (size_t i = 0; i < pass.size(); i++) { text.push_back('*'); }
				if (pass == pass2)verify[inPos] = TRUE; else { text = "Пароли не совпадают"; verify[inPos] = FALSE; }
			}break;
			//-------------------------------//
			case 3:
			{
				FName = getFixLenStr(15); verify[inPos] = TRUE;
				text = FName;
			}break;
			//-------------------------------//
			case 4:
			{
				Name = getFixLenStr(15); verify[inPos] = TRUE;
				text = Name;
			}break;
			//-------------------------------//
			case 5:
			{
				Otchestvo = getFixLenStr(15); verify[inPos] = TRUE;
				text = Otchestvo;
			}break;
			//-------------------------------//
			case 6:
			{
				SetColor(7, 0);
				if (find(verify.begin(), verify.end(), 0) != verify.end()) text = "Неверные данные";
				else {
					if (ADMIN) {
						addAcc();
						system("cls"); cout << "Аккаунт администратора создан";
						Sleep(1000);
						exit(0);
					}
					else {
						ofstream out("Applications.txt", ios_base::app);
						out << login << endl;
						out << pass << endl;
						out << FName << endl;
						out << Name << endl;
						out << Otchestvo << endl;
						text = "Заявка отправлена";
						out.close();
					}
				}
			}break;
			//-------------------------------//
			default:
			{
				Menu::lvl--; if (ADMIN) { system("cls"); exit(0); } ru(); return;
			}break;

			}//switch
			ru();
			MenuCreateAcc.textRight[inPos] = text;
			Menu::lvl--;
		} while (true);
	}

	void loadAcc() {
		//-------------------------------//
		hash<string> Hash;
		long long key;
		string str, buff, textLogin,textPass;
		vector<bool> verify{ 0,0 };
		//-------------------------------//
		Menu MenuCreateAcc;
		MenuCreateAcc.textLeft = {
			"Введите логин      :",
			"Введите пароль     :",
			"Exit"
		};
		ifstream in;
			textLogin = "";
			textPass = "";
		do
		{
			int inPos = MenuCreateAcc.select_vertical("          Вход в аккаунт          ");
			gotoxy(MenuCreateAcc.x + Menu::lvl + 23, MenuCreateAcc.y + Menu::lvl + inPos + 5);
			SetColor(0, 7);
			for (size_t i = 0; i < 15; i++)
				cout << ' ';
			for (size_t i = 0; i < 15; i++)
				cout << "\b \b";
			ru();
			switch (inPos) {
			case 0: {
				in.close();
				login = getFixLenStr(15);
				key = Hash(login);
				in.open(to_string(key) + ".txt");
				if (in.is_open()) {
					textLogin = login;
					verify[inPos] = TRUE; }
				else { textLogin = "Неверый логин"; verify[inPos] = FALSE; }
			}break;
			case 1: {
				if (!in.is_open()) { textLogin = "Неверый логин"; verify[0] = FALSE; }
				else {
					pass = getFixLenStr(15, 1);
					key = Hash(pass);
					in >> buff;
					in >> buff;
					if (to_string(key) == buff) {
						in >> buff;
						if (buff == (string)"873244444") ADMIN = TRUE;
						else ADMIN = FALSE;
						in >> FName;
						in >> Name;
						in >> Otchestvo;

						Exam exam;
						exam.menu();
						ru();
					return;
					}
					else
						textPass = "Неверный пароль";
				}
			}break;
			default:
			{
				in.close();
				Menu::lvl--; ru(); return;
			}break;
			}//switch
			SetColor(7, 0);
			MenuCreateAcc.textRight[0] = textLogin;
			MenuCreateAcc.textRight[1] = textPass;
			ru();
			Menu::lvl--;
		} while (true);
	}
	void menu() {
		ru();
		Menu MenuStart;
		MenuStart.textLeft = {
			"Создать аккаунт",
			"Войти в аккаунт",
			"Закрыть приложение",
		};
		ru();
		do {
			SetColor(7, 0);
			int inPos = MenuStart.select_vertical("Система тестирования", 45, 2, 1);
			switch (inPos)
			{
			case 0:createAcc(); break;
			case 1:loadAcc(); break;
			case 2:exit(0); break;
			default:
				break;
			}

		} while (true);

	}

};
