#include <iostream>
#include <string>
using namespace std;

struct hero {
	string name;
	int age;
	string sex;
};

void sortHero(hero heroArr[], int len);
void printhero(hero heroArr[], int len);