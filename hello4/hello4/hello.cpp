#include "obj.h"


/*
构造函数的分类和调用
按参数分:有参构造和无参构造
按类型分:普通构造和拷贝构造
拷贝构造函数调用方式：
括号法
显示法
隐式转换法
*/
class Person {
	//创建对象的时候自动调用，而且只调用一次

public:
	int age;
	Person() {
		cout << "无参构造函数的调用" << endl;
	}
	Person(int a) {
		cout << "有参构造函数Person(int a)的调用" << endl;
		age = a;
	}

	Person(const Person &p) {
		//将传入的对象身上的所有属性拷贝到自己身上
		cout << "拷贝构造函数Person(const Person &p)的调用" << endl;
		age = p.age;
	}

	~Person() {
		cout << "析构函数的调用" << endl;
	}
};

int main()
{/*
	int i, j, sum;
	while (cin >> i >> j) {
		sum = i + j;
		cout << sum << endl;
	}*/
	//括号法
	Person p;//默认拷贝函数调用
	Person p2(34);//有参构造函数调用
	Person p3(p2);//拷贝构造函数调用
	//ps:调用默认构造函数的时候不要加上()
	//显示法
	cout << "p2的年龄为:" << p2.age << endl;
	cout << "p3的年龄为:" << p3.age << endl;

	Person(10);//匿名对象 当前行执行结束后，系统会立即回收掉匿名对象
	//隐式转换法

	//拷贝函数的调用
	return 0;
}

