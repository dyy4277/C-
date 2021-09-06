#include <iostream>
#include <string> 
using namespace std;

struct student {
	string name;
	int age;
	int score;
};

struct teacher {
	string name;
	struct student sarr[5];
};

void nameSeed(struct teacher tarr[], int len);
void printInfo(struct teacher tarr[], int len);