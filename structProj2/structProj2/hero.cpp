#include "hero.h"

int main() {
	hero heroArr[5] = {
		{"刘备",44,"女"},
		{"赵云",34,"女"},
		{"关于",41,"女"},
		{"小乔",24,"女"},
		{"貂蝉",31,"女"}
	};
	sortHero(heroArr, 5);
	printhero(heroArr,5);
	
}

void sortHero(hero heroArr[], int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (heroArr[j].age > heroArr[j + 1].age) {
				hero temp = heroArr[j];
				heroArr[j] = heroArr[j + 1];
				heroArr[j + 1] = temp;
			}
		}
	}
}

void printhero(hero heroArr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << "姓名:" << heroArr[i].name << "\t 年龄:" << heroArr[i].age << "\t性别:" << heroArr[i].sex << endl;
	}
}