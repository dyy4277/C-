#include"student.h"

Student::Student() {
	
}
Student::Student(int id, string name, string pwd) {
	this->s_id = id;
	this->name = name;
	this->pwd = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	Computer C;
	while (ifs >> C.comId && ifs >> C.MaxNum) {
		this->vCom.push_back(C);
	}

	ifs.close();
}

void Student::operMenu() {
	cout << "欢迎" << this->name << "登陆" << endl;
	cout << "1. 申请预约" << endl;
	cout << "2. 查看我的预约" << endl;
	cout << "3. 查看所有预约" << endl;
	cout << "4. 取消预约" << endl;
	cout << "0. 注销账号" << endl;
	cout << endl;
}

void Student::applyOrder() {
	cout << "机房开放时间为周一至周五" << endl;
	cout << "输入申请预约时间" << endl;
	cout << "1 周一" << endl;
	cout << "2 周二" << endl;
	cout << "3 周三" << endl;
	cout << "4 周四" << endl;
	cout << "5 周五" << endl;
	cout << "6 周六" << endl;
	cout << "7 周日" << endl;
	int date = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5) break;
		cout << "不可预约该时间" << endl;
	}

	cout << "请选择机房" << endl;
	cout << "1号机房容量:" << vCom[0].MaxNum << endl;
	cout << "2号机房容量:" << vCom[1].MaxNum << endl;
	cout << "3号机房容量:" << vCom[2].MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	
	ofs << "date:" << date << " ";
	ofs << "stuId:" << this->s_id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << " ";

	ofs.close();

	system("pause");
	system("cls");
}

void Student::showMyOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		//c_str为string转const char*
		//atoi为const char*转int
		if (atoi(of.orderData[i]["stuId"].c_str()) == this->s_id) {
			cout << "预约日期：周" << of.orderData[i]["date"];
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
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder() {
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
}

void Student::cancleOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者预约成功的记录可以取消，轻松输入取消的记录" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 1; i < of.size; i++) {
		if (atoi(of.orderData[i]["stuId"].c_str()) == this->s_id) {
			if ((of.orderData[i]["status"] == "1")|| (of.orderData[i]["status"] == "2") ){
				v.push_back(i);
				cout << index++ << " ";
				cout << "预约日期:周" << of.orderData[i]["date"];
				cout << "机房:" << of.orderData[i]["roomId"];
				string status = "状态:";
				if (of.orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.orderData[i]["status"] == "2") {
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;

	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= v.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已取消预约" << endl;
				break;
			}
		}
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}