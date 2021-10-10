#include "teacher.h"

Teacher::Teacher() {
};

Teacher::Teacher(int empId, string name, string pwd) {
	this->empId = empId;
	this->name = name;
	this->pwd = pwd;
};

void Teacher::operMenu() {
	cout << "欢迎" << this->name << "登陆" << endl;
	cout << "1. 查看所有预约" << endl;
	cout << "2. 审核预约" << endl;
	cout << "0. 注销账号" << endl;
	cout << endl;
};

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		cout << "预约日期:周" << of.orderData[i]["date"];
		cout << "学号:" << of.orderData[i]["stuId"];
		cout << "姓名:" << of.orderData[i]["stuName"];
		cout << "机房:" << of.orderData[i]["roomId"];
		string status = "状态:";
		if (of.orderData[i]["status"] == "1") {
			status += "审核中";
		}
		else if (of.orderData[i]["status"] == "2") {
			status += "预约成功";
		}
		else if (of.orderData[i]["status"] == "-1") {
			status += "预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
};

void Teacher::validOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的预约记录如下:" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 1; i < of.size; i++) {
		if ((of.orderData[i]["status"] == "1")) {
			v.push_back(i);
			cout << index++ << " ";
			cout << "预约日期:周" << of.orderData[i]["date"];
			cout << "机房:" << of.orderData[i]["roomId"];
			string status = "状态:";
			if (of.orderData[i]["status"] == "1") {
				status += "审核中";
			}
			cout << status << endl;
		}
	}
	cout<<"请输入审核的预约记录，0代表返回" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "请输入审核结果:" << endl;
				cout << "1 通过" << endl;
				cout << "2 不通过" << endl;
				cin >> ret;
				if (ret == 1) {
					of.orderData[v[select - 1]]["status"] == "2";
				}
				else {
					of.orderData[v[select - 1]]["status"] == "-1";
				}
				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
};