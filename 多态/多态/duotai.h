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
//��̬����--������Ʒ
/*
*��ˮ�����ݣ����뱭�У����븨��
����:�������Ⱥ��ݲ�
*/

class AbstractDrinking {
public:
	//��ˮ
	virtual void Boid() = 0;
	//����
	virtual void Brew() = 0;
	//���뱭��
	virtual void PourInCup() = 0;
	//���븨��
	virtual void PutSome() = 0;
	//������Ʒ
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
		cout << "��ˮ" << endl;
	}

	void Brew() {
		cout << "���ݿ���" << endl;
	}

	void PourInCup() {
		cout << "���뱭��" << endl;
	}

	void PutSome() {
		cout << "���̼���" << endl;
	}
};

class Tea :public AbstractDrinking {
public:
	void Boid() {
		cout << "��ˮ" << endl;
	}

	void Brew() {
		cout << "���ݲ�Ҷ" << endl;
	}

	void PourInCup() {
		cout << "���뱭��" << endl;
	}

	void PutSome() {
		cout << "��Ѽʺ" << endl;
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
�������ʹ�������

��̬ʹ��ʱ����������������Կ��ٵ���������ô����ָ�����ͷ�ʱ�޷����õ��������������

�����ʽ���������е�����������Ϊ���������ߴ�������

�������ʹ��������Ĺ��ԣ�
	����ʹ����ָ���ͷ��������

����
	���������������ڳ����࣬�޷�ʵ����

�������﷨��virtual ~����(){}

���������ߴ������������������ͨ������ָ���ͷ�������������
���������û�ж������ݣ����Բ�дΪ���������ߴ�������
���ڴ���������������Ҳ���ڳ�����
*/

class animal {
public:
	virtual void speak();
	virtual ~animal() {
		cout << "animal����������" << endl;
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
		cout << "animal����������" << endl;
	}
};

void DoSpeak(animal& A);

void test();