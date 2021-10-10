#include<iostream>
#include"globalFile.h"
#include"identity.h"
#include<fstream>
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"

using namespace std;

void managerMenu(identity* manager) {
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;//强转为子类指针
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void studentMenu(identity* student) {
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;//强转为子类指针
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2) {
			cout << "查看自身预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) {
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			cout << "取消预约" << endl;
			stu->cancleOrder();
		}
		else {
			delete student;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void teacherMenu(identity* teacher) {
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;//强转为子类指针
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "查看所有预约" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) {
			cout << "审核预约" << endl;
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void LoginIn(string fileName, int type) {
	identity* person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "请输入你的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入你的用户名：" << endl;
	cin >> name;
	cout << "请输入你的密码：" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生登陆验证
		int fID;
		string fName;
		string fPwd;

		while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
			cout << fID << fName << fPwd << endl;
			if (id == fID && name == fName && pwd == fPwd) {
				cout << "学生验证成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//教师登陆验证
		int fID;
		string fName;
		string fPwd;

		while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
			cout << fID << fName << fPwd << endl;
			if (id == fID && name == fName && pwd == fPwd) {
				cout << "教师验证成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登陆验证
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {
			cout << fName << fPwd << endl;
			if (name == fName && pwd == fPwd) {
				cout << "管理员验证成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);//进入管理员子菜单


				return;
			}
		}
	}

	cout << "验证登陆失败" << endl;


	system("pause");
	system("cls");
	return;
}



int main() {
	int select;
	while (true) {
		cout << "=========  欢迎使用机房预约系统  ==========" << endl;

		cout << "请输入您的身份" << endl;
		cout << "1. 学生代表" << endl;
		cout << "2. 老师" << endl;
		cout << "3. 管理员" << endl;
		cout << "4. 退出" << endl;
		cout << "您的选择是：" << endl;

		cin >> select;
		switch (select) {
		case 1:
			LoginIn(STUDENT_FILE,1);
			break;

		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 4:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误， 请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}