#include "hero.h"

int main() {
	hero heroArr[5] = {
		{"����",44,"Ů"},
		{"����",34,"Ů"},
		{"����",41,"Ů"},
		{"С��",24,"Ů"},
		{"����",31,"Ů"}
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
		cout << "����:" << heroArr[i].name << "\t ����:" << heroArr[i].age << "\t�Ա�:" << heroArr[i].sex << endl;
	}
}