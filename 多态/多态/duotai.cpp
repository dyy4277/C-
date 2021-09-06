#include "duotai.h"



int main() {
	/*
	动态多态满足条件
	1，有继承关系
	2，子类重写父类的虚函数

	动态多态的使用
		父类的指针或引用，执行子类对象
	*/
	test();
	test01();

	system("pause");
	return 0;
}

void animal::speak() {
	cout << "动物在说话" << endl;
}

void Cat::speak() {
	cout << "猫在叫" << endl;
}

void Dog::speak() {
	cout << "狗在叫" << endl;
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
