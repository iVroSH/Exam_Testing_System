#pragma once

class Question {
public:
	int answer_count = 0, true_answer_count = 0;
	map<string, bool> answers;
	string str;
	Question(){}
	Question(string st):str(st) {}

	void insert_answer(string &&st, bool &&true_false) {
		answer_count++;
		true_answer_count += true_false;
		answers[st] = true_false;
	}

	void print() {
		cout << "________________________________" << endl;
		cout << str<<endl;
		cout << "--------------------------------" << endl;
		for (auto i : answers) {
			cout << i.first<<' '<<i.second << endl;
		}
		cout << "________________________________" << endl;
	}
};

class Test{
	
	
public:
	string str;
	int ticket = 0;
	Test(string&& st) :str(st) {}
	map<int, Question> questions;
	void insert_question(string &&st) {
		questions[ticket++] = st;
	}

	void print(int a) {
		cout << "================================" << endl;
		cout << str << endl;
		questions[a].print();
		cout << "================================" << endl;
	}
};
