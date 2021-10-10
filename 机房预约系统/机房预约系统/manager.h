#pragma once
#include<iostream>
#include"identity.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"computer.h"

using namespace std;

class Manager:public identity {
public:
	Manager();

	Manager(string name,string pwd);

	virtual void operMenu();

	void addPerson();

	void showPerson();

	void showComputer();

	void cleanFile();

	void initVector();

	bool checkRepeat(int id,int type);

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<Computer> vCom;
};