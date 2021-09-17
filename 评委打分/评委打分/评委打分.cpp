#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;



class person{
public:
	person(string name, int score) {
		this->name = name;
		this->score = score;
	}

	string name;
	int score;
};

void createPerson(vector<person>& v) {
	for (int i = 1; i < 6; i++) {
		string name = "选手";
		name += "_" + to_string(i);

		int score = 0;

		person p(name,score);
		v.push_back(p);
	}
}

void showperson(vector<person> &v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "姓名:	" << (*it).name << "	分数:	" << (*it).score << endl;
	}
}

void setScore(vector<person> &v) {
	for (vector<person>::iterator it = v.begin(); it != v.end(); it++) {
		deque<int> d;
		for (int i = 0; i < 10; i++) {
			int score = rand() % 41 + 60;//60-100
			d.push_back(score);
		}
		/*cout << it->name << "的打分为:" << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			cout << *dit << " ";
		}
		cout << endl;*/
		//排序
		sort(d.begin(), d.end());

		//去除最低最高分
		d.pop_back();
		d.pop_front();

		int sum = 0;

		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++) {
			sum += *dit;
		}
		int vag = sum / d.size();

		it->score = vag;
	}
}

int main() {
	system("chcp 65001 && cls");
	//需要加个随机数种子,使得每次获取的随机数不一样

	srand((unsigned int)time(NULL));

	vector<person> v;
	createPerson(v);

	setScore(v);
	showperson(v);
	system("pause");
	return 0;
}