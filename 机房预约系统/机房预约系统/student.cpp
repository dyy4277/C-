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
	cout << "��ӭ" << this->name << "��½" << endl;
	cout << "1. ����ԤԼ" << endl;
	cout << "2. �鿴�ҵ�ԤԼ" << endl;
	cout << "3. �鿴����ԤԼ" << endl;
	cout << "4. ȡ��ԤԼ" << endl;
	cout << "0. ע���˺�" << endl;
	cout << endl;
}

void Student::applyOrder() {
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "��������ԤԼʱ��" << endl;
	cout << "1 ��һ" << endl;
	cout << "2 �ܶ�" << endl;
	cout << "3 ����" << endl;
	cout << "4 ����" << endl;
	cout << "5 ����" << endl;
	cout << "6 ����" << endl;
	cout << "7 ����" << endl;
	int date = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5) break;
		cout << "����ԤԼ��ʱ��" << endl;
	}

	cout << "��ѡ�����" << endl;
	cout << "1�Ż�������:" << vCom[0].MaxNum << endl;
	cout << "2�Ż�������:" << vCom[1].MaxNum << endl;
	cout << "3�Ż�������:" << vCom[2].MaxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3) {
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++) {
		//c_strΪstringתconst char*
		//atoiΪconst char*תint
		if (atoi(of.orderData[i]["stuId"].c_str()) == this->s_id) {
			cout << "ԤԼ���ڣ���" << of.orderData[i]["date"];
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
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder() {
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
}

void Student::cancleOrder() {
	OrderFile of;
	if (of.size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ������������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 1; i < of.size; i++) {
		if (atoi(of.orderData[i]["stuId"].c_str()) == this->s_id) {
			if ((of.orderData[i]["status"] == "1")|| (of.orderData[i]["status"] == "2") ){
				v.push_back(i);
				cout << index++ << " ";
				cout << "ԤԼ����:��" << of.orderData[i]["date"];
				cout << "����:" << of.orderData[i]["roomId"];
				string status = "״̬:";
				if (of.orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.orderData[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;

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
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}