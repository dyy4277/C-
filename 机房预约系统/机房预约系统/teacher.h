#pragma once
#include<iostream>
#include"identity.h"
#include<vector>
#include<fstream>
#include"computer.h"
#include"globalFile.h"
#include"orderFile.h"

using namespace std;

class Teacher :public identity {
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	void showAllOrder();

	void validOrder();
	int empId;
	string name;
	string pwd;
};
