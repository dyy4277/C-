#include <iostream>
using namespace std;

class father {
public:
	int A = 10;
	static int B;
	void func() {
		cout << "�ְ�" << endl;
	};
	static void funcB() {
		B = 190;
		cout << B << endl;
	};
};
int father::B = 88;

class son :public father {
public:
	static int B;
	void func() {
		A = 100;
		cout << "����" << endl;
	};

	static void funcB() {
		B += 1990;
		cout << B << endl;
	};
};
int son::B = 999;

void test() {

	son s;
	cout << "father:" << s.father::A << endl;
	cout << "son:" << s.son::A << endl;

	//1.ͨ���������
	s.father::funcB();
	s.funcB();
	cout << "father:" << s.father::B << endl;
	cout << "son:" << s.B << endl;
	////1.ͨ����������
}

class A
{
public:
	double a;
	float b;
	char c;
	int d;
	char e;
	int f;
};

class animal {
public:
	int age;
	int ag;

	void virtual speak() {
		cout << "������˵��" << endl;
	}
};

class sheep :public animal {
public:
	void speak() {
		cout << "����˵��" << endl;
	}
};

class Camel :public animal {

};

class alpaca :public sheep, public Camel {

};

void dospeak(animal& an) {
	//��������ַ�������ڵ���dospeakǰȷ���������Ƕ�̬��̬
	//��Ҫ���к��֪��ִ�к�����ַ
	an.speak();
}

void test2() {
	sheep sh;
	
	dospeak(sh);
}



//��̬������������װ============================================================
//����CPU
class CPU {
	virtual void caculate() = 0;
};
//�����Կ�
class CideoCard {
	virtual void display() = 0;
};

//�����ڴ�
class Menory {
	virtual void storage() = 0;
};

class IntelCpu :public CPU {
	void calculate() {
		cout << "intel��CPU��ʼ������" << endl;
	}
};