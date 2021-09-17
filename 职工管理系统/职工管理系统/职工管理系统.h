#pragma once
#include<iostream>

using namespace std;

class WorkerManager {
public:
	//¹¹Ôìº¯Êý
	WorkerManager();
	~WorkerManager();

	void showMaue();
	void ExitSystem();
};

class worker {
public:
	virtual void showInfo() = 0;
	virtual void getDeptName() = 0;

	int m_ID;
	string m_Name;
	int m_DeptId;
};

class Employee:public worker {
	Employee(int id, string name, int did);
	
	void showInfo();

	string getDeptName();

};