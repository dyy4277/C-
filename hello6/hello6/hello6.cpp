#include "hello6.h"

int main() {

	test();

	A a; cout << sizeof(a) << endl;
	cout << sizeof(a.a) << endl;
	cout << sizeof(a.b) << endl;
	cout << sizeof(a.c) << endl;
	cout << sizeof(a.d) << endl;
	cout << sizeof(a.e) << endl;
	cout << sizeof(a.f) << endl;
	cout << int(&a.a) << endl;
	cout << int(&a.b) << endl;
	cout << int(&a.c) << endl;
	cout << int(&a.d) << endl;
	cout << int(&a.e) << endl;
	cout << int(&a.f) << endl;

	alpaca al;
	al.sheep::age = 10;
	al.Camel::age = 102;
	cout<< al.sheep::age <<endl;
	cout<< al.Camel::age <<endl;
	cout << sizeof(al);

	sheep s;
	Camel C;
	s.age = 11;
	C.age = 12;
	cout << s.age << endl;
	cout << C.age << endl;

	test2();
	system("pause");
	return 0;
}

