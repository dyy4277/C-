#include "structproj.h"

int main() {
	struct teacher tarr[3];
	//���������
	srand((unsigned int)time(NULL));
	nameSeed(tarr, 3);
	printInfo(tarr, 3);
}

void nameSeed(struct teacher tarr[], int len) {
	for (int i = 0; i < len; i++) {
		tarr[i].name = "Teacher_"+ to_string(i+1);

		for (int j=0; j < 5; j++) {
			tarr[i].sarr[j].name = "Student_" + to_string(i+1)+"_"+to_string(j+1);
			int randomage = rand() % 4 + 15;//15-18
			tarr[i].sarr[j].age = randomage;
			int random = rand() % 61 + 40;//40-100
			tarr[i].sarr[j].score = random;
		}
	}
}

void printInfo(struct teacher tarr[],int len) {
	for (int i = 0; i < len; i++) {
		cout << "��ʦ����:" << tarr[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\tѧ������:" << tarr[i].sarr[j].name << endl;
			cout << "\tѧ������:" << tarr[i].sarr[j].age << endl;
			cout << "\tѧ�����Է���:" << tarr[i].sarr[j].score << endl;
		}
	}
}