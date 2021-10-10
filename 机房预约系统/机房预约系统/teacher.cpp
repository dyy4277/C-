#include "teacher.h"

Teacher::Teacher() {
};

Teacher::Teacher(int empId, string name, string pwd) {
	this->empId = empId;
	this->name = name;
	this->pwd = pwd;
};

void Teacher::operMenu() {
	cout << "��ӭ" << this->name << "��½" << endl;
	cout << "1. �鿴����ԤԼ" << endl;
	cout << "2. ���ԤԼ" << endl;
	cout << "0. ע���˺�" << endl;
	cout << endl;
};

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		cout << "ԤԼ����:��" << of.orderData[i]["date"];
		cout << "ѧ��:" << of.orderData[i]["stuId"];
		cout << "����:" << of.orderData[i]["stuName"];
		cout << "����:" << of.orderData[i]["roomId"];
		string status = "״̬:";
		if (of.orderData[i]["status"] == "1") {
			status += "�����";
		}
		else if (of.orderData[i]["status"] == "2") {
			status += "ԤԼ�ɹ�";
		}
		else if (of.orderData[i]["status"] == "-1") {
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
};

void Teacher::validOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵�ԤԼ��¼����:" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 1; i < of.size; i++) {
		if ((of.orderData[i]["status"] == "1")) {
			v.push_back(i);
			cout << index++ << " ";
			cout << "ԤԼ����:��" << of.orderData[i]["date"];
			cout << "����:" << of.orderData[i]["roomId"];
			string status = "״̬:";
			if (of.orderData[i]["status"] == "1") {
				status += "�����";
			}
			cout << status << endl;
		}
	}
	cout<<"��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int ret = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽��:" << endl;
				cout << "1 ͨ��" << endl;
				cout << "2 ��ͨ��" << endl;
				cin >> ret;
				if (ret == 1) {
					of.orderData[v[select - 1]]["status"] == "2";
				}
				else {
					of.orderData[v[select - 1]]["status"] == "-1";
				}
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
};