#include "obj.h"


/*
���캯���ķ���͵���
��������:�вι�����޲ι���
�����ͷ�:��ͨ����Ϳ�������
�������캯�����÷�ʽ��
���ŷ�
��ʾ��
��ʽת����
*/
class Person {
	//���������ʱ���Զ����ã�����ֻ����һ��

public:
	int age;
	Person() {
		cout << "�޲ι��캯���ĵ���" << endl;
	}
	Person(int a) {
		cout << "�вι��캯��Person(int a)�ĵ���" << endl;
		age = a;
	}

	Person(const Person &p) {
		//������Ķ������ϵ��������Կ������Լ�����
		cout << "�������캯��Person(const Person &p)�ĵ���" << endl;
		age = p.age;
	}

	~Person() {
		cout << "���������ĵ���" << endl;
	}
};

int main()
{/*
	int i, j, sum;
	while (cin >> i >> j) {
		sum = i + j;
		cout << sum << endl;
	}*/
	//���ŷ�
	Person p;//Ĭ�Ͽ�����������
	Person p2(34);//�вι��캯������
	Person p3(p2);//�������캯������
	//ps:����Ĭ�Ϲ��캯����ʱ��Ҫ����()
	//��ʾ��
	cout << "p2������Ϊ:" << p2.age << endl;
	cout << "p3������Ϊ:" << p3.age << endl;

	Person(10);//�������� ��ǰ��ִ�н�����ϵͳ���������յ���������
	//��ʽת����

	//���������ĵ���
	return 0;
}

