#pragma once
#include<iostream>
using namespace std;

//身份抽象类
class identity {
public:
	virtual void operMenu() = 0;
	string name;
	string pwd;
};