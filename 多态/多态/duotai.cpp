#include "duotai.h"



int main() {
	/*
	��̬��̬��������
	1���м̳й�ϵ
	2��������д������麯��

	��̬��̬��ʹ��
		�����ָ������ã�ִ���������
	*/
	test();
	test01();

	system("pause");
	return 0;
}

void animal::speak() {
	cout << "������˵��" << endl;
}

void Cat::speak() {
	cout << "è�ڽ�" << endl;
}

void Dog::speak() {
	cout << "���ڽ�" << endl;
}

void DoSpeak(animal& A) {
	A.speak();
}

void test() {
	animal A;
	Cat C;
	Dog D;

	DoSpeak(C);
	DoSpeak(D);

	cout << sizeof(A) << endl;
	cout << sizeof(C) << endl;

	AddCalculator addCal;
	addCal.num1 = 99;
	addCal.num2 = 99;
	cout << Calculator(addCal) << endl;
	
}


int abstractCalculator::getResult() {
		return 0;
}


int MulCalculator::getResult() {
	return num1*num2;
}
int AddCalculator::getResult() {
	return num1 + num2;
}

int Calculator(abstractCalculator& absCal) {
	return absCal.getResult();
}
