#pragma once

struct Answer {
public:
	Answer(string st, size_t val) :str(st), value(val) {}
	Answer(){}
	string str;
	size_t value;
};

class Question {
public:
	string str;
	bool flag = false;
	int answer_count = 0, true_answer_count = 0;
	map<int, Answer> answers;
	Question(){}
	Question(string st):str(st) {}

	void insert_answer(string &&st, size_t &&val) {
		answer_count++;
		true_answer_count += (val)?val:0;
		answers[answer_count] = Answer(st,val);
	}

	void print() {
		cout << "________________________________" << endl;
		cout << str<<endl;
		cout << "--------------------------------" << endl;
		for (auto i : answers) {
			cout << i.first<<") "<<i.second.str << endl;
		}
		cout << "________________________________" << endl;
	}
};

class Theme{
public:
	string str;
	int qCount = 0;
	Theme(string&& st) :str(st) {}
	map<int, Question> questions;
	void insert_question(string &&st) {
		questions[qCount++] = st;
		qCount++;
	}

	void print(int a) {
		cout << "================================" << endl;
		cout << str << endl;
		questions[a].print();
		cout << "================================" << endl;
	}
};

class Subject {
	string str;
	map<int, Theme> themes;
	size_t tCount;
};

class Exam {
	vector<Theme> subjects;
	size_t sCount;
};
