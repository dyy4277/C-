#include <iostream>
using namespace std;

class father {
public:
	int A = 10;
	static int B;
	void func() {
		cout << "爸爸" << endl;
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
		cout << "儿子" << endl;
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

	//1.通过对象访问
	s.father::funcB();
	s.funcB();
	cout << "father:" << s.father::B << endl;
	cout << "son:" << s.B << endl;
	////1.通过类名访问
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
		cout << "动物在说话" << endl;
	}
};

class sheep :public animal {
public:
	void speak() {
		cout << "羊在说话" << endl;
	}
};

class Camel :public animal {

};

class alpaca :public sheep, public Camel {

};

void dospeak(animal& an) {
	//传入对象地址并不能在调用dospeak前确定，所以是动态多态
	//需要运行后才知道执行函数地址
	an.speak();
}

void test2() {
	sheep sh;
	
	dospeak(sh);
}



//多态案例：电脑组装============================================================
//抽象CPU
class CPU {
	virtual void caculate() = 0;
};
//抽象显卡
class CideoCard {
	virtual void display() = 0;
};

//抽象内存
class Menory {
	virtual void storage() = 0;
};

class IntelCpu :public CPU {
	void calculate() {
		cout << "intel的CPU开始计算了" << endl;
	}
};