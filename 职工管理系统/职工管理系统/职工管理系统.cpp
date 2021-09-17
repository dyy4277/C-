#include "职工管理系统.h"

int main() {
	WorkerManager WM;
	
	int choice = 0;
	while (true) {
		WM.showMaue();
		cout << "请输出你的选择" << endl;
		cin >> choice;

		switch (choice) {
		case 0:
			WM.ExitSystem();
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:

			break;
		}
	}


	system("pause");
	return 0;
}

WorkerManager::WorkerManager() {

};

WorkerManager::~WorkerManager() {

};

void WorkerManager::showMaue() {
	string i(60, '*');
	string two(16, '*');
	string three(20, '*');
	cout << i << endl;

	cout << two << "    " << "欢迎使用职工管理系统" << "    " << two << endl;

	cout << three << "\t" << "0.退出管理系统" << "\t" << three << endl;
	cout << three << "\t" << "1.添加员工信息" << "\t" << three << endl;
	cout << three << "\t" << "2.显示职工信息" << "\t" << three << endl;
	cout << three << "\t" << "3.删除离职员工" << "\t" << three << endl;
	cout << three << "\t" << "4.修改员工信息" << "\t" << three << endl;
	cout << three << "\t" << "5.查找职工信息" << "\t" << three << endl;
	cout << three << "\t" << "6.按照编号排序" << "\t" << three << endl;
	cout << three << "\t" << "7.清空所有文档" << "\t" << three << endl;

	cout << i << endl;
}

void WorkerManager::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
};

Employee::Employee(int id, string name, int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

void Employee::showInfo() {
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责: 完成经理交代的任务"<<endl;
}

string Employee::getDeptName() {
	return string("员工");
}