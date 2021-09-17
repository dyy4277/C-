#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
//容器嵌套容器

void vecinvec() {
	vector<vector<int>> v;
	//创建内部容器
	vector<int>v1; vector<int>v2; vector<int>v3; vector<int>v4; vector<int>v5; vector<int>v6; vector<int>v7;
	for (int i = 0; i < 3; i++) {
		v1.push_back(i);
		v2.push_back(i+4);
		v3.push_back(i+8);
		v4.push_back(i+12);
		v5.push_back(i+16);
		v6.push_back(i+24);
		v7.push_back(i+30);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	v.push_back(v6);
	v.push_back(v7);

	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		//*it 本身是个容器
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << endl;
		}
		cout << "==========================" << endl;
	}

	//查找和替换
}


void printVec(vector<int> v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << "\n";
}

//插入和删除
void test3() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);

	//遍历
	printVec(v);

	//尾删
	v.pop_back();
	printVec(v);

	v.insert(v.begin()+1,3, 99);
	printVec(v);
	v.insert(v.end(), 99);
	printVec(v);

	//v.erase(v.begin()+3);
	printVec(v);

	v.erase(v.begin() + 3, v.begin() + 5);//左闭右开，删除第4-5个数据
	printVec(v);
	v.clear();
	printVec(v);
}

//vector中的数据存取
//利用[]访问元素
void test4() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	//利用at方式访问元素
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;
	//获取第一个元素
	cout << "第一个元素为：" << v.front() << endl;
	//获取最后一个元素
	cout << "最后一个元素为：" << v.back() << endl;
}

//vector互换容器
//实现两个容器内元素进行互换

void test5() {
	cout << "交换前" << endl;
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	printVec(v);

	vector<int> v1;
	for (int i = 10; i < 25; i++) {
		v1.push_back(i);
	}

	printVec(v1);
	cout << "交换后" << endl;
	v.swap(v1);
	printVec(v);
	printVec(v1);

	vector<int> v2;
	for (int i = 10; i < 100000; i++) {
		v2.push_back(i);
	}
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;

	//v2.resize(10);
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;

	//使用swap收缩内存
	vector<int>(v2).swap(v2);
	cout << v2.size() << endl;
	cout << v2.capacity() << endl;
}


//vector预留空间
void test07() {
	int Num = 0;
	int* p = NULL;
	vector<int> v2;
	for (int i = 10; i < 100000; i++) {
		v2.push_back(i);
		if (p != &v2[0]) {
			p = &v2[0];
			cout<<"/t"<<v2.capacity()<<endl;
			Num++;
		}
	}
	cout << Num << endl;
}


#include <deque>

void printdeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << "\t";
	}
	cout << endl;
}

//deque构造函数
void deque1() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printdeque(d);
	deque<int> d1(d.begin(),d.end()-1);
	printdeque(d1);
	deque<int> d2(10, 100);
	printdeque(d2);
	deque<int> d3(d);
	printdeque(d3);
}

//deque赋值操作

void deque2() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printdeque(d);
	//operator = 
	deque<int> d1=d;
	printdeque(d1);

	//assign赋值
	deque<int> d2;
	d2.assign(10, 100);
	printdeque(d2);
}

//deque大小操作
void deque3() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	if (d.empty()) {
		cout << "为空" << endl;
	}
	else {
		cout << "为："<<d.size() << endl;
	}
	d.resize(20);

	printdeque(d);
	d.resize(22,2);

	printdeque(d);
	d.resize(2);
	printdeque(d);
}

//deque插入和删除

void deque4() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printdeque(d);
	////尾插
	//d.push_back(999);
	//printdeque(d);

	////头插
	//d.push_front(888);
	//printdeque(d);

	////尾删
	//d.pop_back();
	//printdeque(d);

	////头删
	//d.pop_front();
	//printdeque(d);

	////插入
	//d.insert(d.begin()+1,5678);
	//printdeque(d);

	//d.insert(d.begin() + 1,3, 7654);
	//printdeque(d);
	//d.insert(d.end(), 3, 5678);
	//printdeque(d);

	//d.insert(d.end(), d.begin(), d.end());
	//printdeque(d);

	d.erase(d.begin()+2);
	printdeque(d);

	d.erase(d.begin() + 2, d.begin() + 5);
	printdeque(d);

	d.clear();
	printdeque(d);
}

//deque容器数据存取
void deque5() {
	deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	//通过[]访问元素
	for (int i = 0; i < d.size(); i++) {
		cout << d[i] << " ";
	}
	cout << endl;


	//通过at方式访问
	for (int i = 0; i < d.size(); i++) {
		cout << d.at(i) << " ";
	}
	cout << endl;

	//访问前后元素
	cout << d.front() << endl;
	cout << d.back() << endl;
}


//deque排序
void deque6() {
	deque<int> d;
	for (int i = 0; i < 5; i++) {
		d.push_back(i);
	}

	for (int i = 54; i > 46; i--) {
		d.push_back(i);
	}
	printdeque(d);

	sort(d.begin(), d.end());//vector也可以利用sort排序
	printdeque(d);
	
	printdeque(d);
}

int main() {

	//vecinvec();
	/*test3();
	test4();
	test5();
	cout << "-----------------------------------------" << endl;
	test07();*/

	//deque1();
	//deque2();
	//deque4();
	//deque5();
	deque6();
	system("pause");
	return 0;
}




