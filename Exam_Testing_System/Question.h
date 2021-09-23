#pragma once

struct Answer {
	vector<string> answers;
	vector<int> value;
	void menu(string &exam,string &question, string &question2) {
		//-------------------------------//
		ifstream in(exam+question2 + "Answer.txt");
		//-------------------------------//
		char buff[64];
		in.get();
		while (!in.eof()) {
			in.getline(buff, 64);
			answers.push_back(buff);
			in.getline(buff, 64);
			value.push_back(atoi(buff));
		}
		answers.push_back("Exit");
		in.close();
		Menu MenuSelectExam;
		MenuSelectExam.textLeft = answers;
		do
		{
		ru();
		int inPos = MenuSelectExam.select_vertical("  "+question+"  ");
		if (inPos == answers.size() - 1) { Menu::lvl -= 2; ru(); return ; }
		ru();
		} while (true);
	}
};

struct Question {
	vector<string> questions;
	void menu(string& exam) {
		//-------------------------------//
		ifstream in(exam + "Questions.txt");
		//-------------------------------//
		char buff[64];
		in.get();
		while (!in.eof()) {
			in.getline(buff, 64);
			questions.push_back(buff);
		}
		in.close();
		Menu MenuSelectExam;
		for (size_t i = 0; i < questions.size(); i++)
		{
			MenuSelectExam.textLeft.push_back("Вопрос" + to_string(i + 1));
		}
		MenuSelectExam.textLeft.push_back("Exit");
		do
		{
		int inPos = MenuSelectExam.select_vertical("   "+exam+"   ");
		ru();
			Answer answer;
			if (inPos == MenuSelectExam.textLeft.size() - 1) { Menu::lvl -= 2; ru(); return; }
			answer.menu(exam,questions[inPos],MenuSelectExam.textLeft[inPos]);
		ru();
		Menu::lvl--;
		} while (true);
	}
};


struct Exam {
	vector<string> exams;
	
	void update() {
		ifstream in("Exams.txt");
		//-------------------------------//
		char buff[64];
		in.get();
		while (!in.eof()) {
			in.getline(buff, 64);
			exams.push_back(buff);
		}
		exams.push_back("Exit");
		in.close();
	}

	void addExam() {
		ofstream out("Exams.txt", ios_base::app);
		string buff;
		buff = getFixLenStr(30);
		ofstream in(buff+".txt");
		out << endl << buff;
		out.close();
		out.open(buff + ".txt");
		out.close();
		
		
	}

	void menu() {
		//-------------------------------//
		update();
		Menu MenuSelectExam;
		MenuSelectExam.textLeft = exams;

		do
		{
		ru();
		int inPos = MenuSelectExam.select_vertical("         Экзамены         ");
		gotoxy(MenuSelectExam.x + Menu::lvl + 23, MenuSelectExam.y + Menu::lvl + inPos + 5);
		if (inPos == exams.size() - 1) { ru(); return; }
			Question questions;
			questions.menu(exams[inPos]);
		ru();
		} while (true);
	}
};
