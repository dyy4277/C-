#pragma once
#include<iostream>
using namespace std;


class abstractCalculator {
public:
	int num1;
	int num2;
	virtual int getResult();
};

class MulCalculator:public abstractCalculator {
public:
	int getResult();
};

class AddCalculator :public abstractCalculator {
public:
	int getResult();
};

int Calculator(abstractCalculator &abscul);

class base {
public:
	virtual void func() = 0;
};

class son :public base {
public:
	void func() {
		cout << "asd" << endl;
	}
};

//------------------------------------------------------------------------------------------
//多态案例--制作饮品
/*
*煮水，冲泡，倒入杯中，加入辅料
子类:制作咖啡和泡茶
*/

class AbstractDrinking {
public:
	//煮水
	virtual void Boid() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSome() = 0;
	//制作饮品
	void makeDrink() {
		Boid();
		Brew();
		PourInCup();
		PutSome();
	}
};

class Coffee :public AbstractDrinking {
public:
	void Boid() {
		cout << "煮水" << endl;
	}

	void Brew() {
		cout << "冲泡咖啡" << endl;
	}

	void PourInCup() {
		cout << "倒入杯中" << endl;
	}

	void PutSome() {
		cout << "加奶加糖" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	void Boid() {
		cout << "煮水" << endl;
	}

	void Brew() {
		cout << "冲泡茶叶" << endl;
	}

	void PourInCup() {
		cout << "倒入杯中" << endl;
	}

	void PutSome() {
		cout << "加鸭屎" << endl;
	}
};

void doWork(AbstractDrinking *Drink) {
	Drink->makeDrink();
	delete Drink;
}

void test01() {
	doWork(new Coffee);

	doWork(new Tea);
}

//=================================================
/*
虚析构和纯虚析构

多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为虚析构或者纯虚析构

虚析构和纯虚析构的共性：
	可以使父类指针释放子类对象

区别：
	纯虚析构的类属于抽象类，无法实例化

虚析构语法：virtual ~类名(){}

虚析构或者纯虚析构就是用来解决通过父类指针释放子类对象的问题
如果子类中没有堆区数据，可以不写为虚析构或者纯虚析构
用于纯虚析构函数的类也属于抽象类
*/

class animal {
public:
	virtual void speak();
	virtual ~animal() {
		cout << "animal虚析构函数" << endl;
	}
};

class Cat :public animal {
public:
	string *m_name;
	void speak();
	Cat(string name) {
		m_name = new string(name);
	}

	~Cat() {
		if(m_name != NULL){
			delete m_name;
			m_name = NULL;
		}
	}
};

class Dog :public animal {
public:
	void speak();

	virtual ~Dog() {
		cout << "animal虚析构函数" << endl;
	}
};

void DoSpeak(animal& A);

void test();