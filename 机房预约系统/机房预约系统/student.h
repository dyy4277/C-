#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include"identity.h"
#include"computer.h"
#include"globalFile.h"
#include"orderFile.h"


using namespace std;

class Student :public identity {
public:
	Student();

	Student(int id, string name, string pwd);

	virtual void operMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancleOrder();

	int s_id;
	string name;
	string pwd;

	vector<Computer> vCom;
};