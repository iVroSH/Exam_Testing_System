using namespace std;
#include<iostream>
#include<string>
#include<list>
#include<map>
#include"Menu.h"
#include"Question.h"

int main() {

	Test t("Math");

	t.insert_question("2+2=?");
	t.questions[0].insert_answer("11", 0);
	t.questions[0].insert_answer("1", 0);
	t.questions[0].insert_answer("2", 1);
	t.questions[0].insert_answer("3", 0);

	t.insert_question("99-100=?");
	t.questions[1].insert_answer("-1", 1);
	t.questions[1].insert_answer("199", 0);
	t.questions[1].insert_answer("13", 0);
	t.questions[1].insert_answer("-17", 0);

	t.insert_question("10/2=5?");
	t.questions[2].insert_answer("Yes", 1);
	t.questions[2].insert_answer("No", 0);

	t.insert_question("44+?=100");
	t.questions[3].insert_answer("64", 0);
	t.questions[3].insert_answer("78", 0);
	t.questions[3].insert_answer("66", 0);
	t.questions[3].insert_answer("56", 1);


	Menu in;
	vector <string> logInMenu;
	for (auto i:t.questions)
	{
		logInMenu.push_back(i.second.str);
	}
	system("cls");
	int inPos = in.select_vertical(logInMenu);
	while (true)
	{
		
		system("cls");
		t.print(inPos);

		Menu in2;
		vector <string> logInMenu2;
		for (auto j : t.questions[inPos].answers)
		{
			logInMenu2.push_back(j.first);
		}
		system("cls");
		int inPos2 = in2.select_vertical(logInMenu2);
		system("cls");
		
		inPos++;
	}


}