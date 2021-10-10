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

		Manager* man = (Manager*)manager;//ǿתΪ����ָ��
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) {
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) {
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) {
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else {
			delete manager;
			cout << "ע���ɹ�" << endl;
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

		Student* stu = (Student*)student;//ǿתΪ����ָ��
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2) {
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3) {
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4) {
			cout << "ȡ��ԤԼ" << endl;
			stu->cancleOrder();
		}
		else {
			delete student;
			cout << "ע���ɹ�" << endl;
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

		Teacher* tea = (Teacher*)teacher;//ǿתΪ����ָ��
		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
		}
		else if (select == 2) {
			cout << "���ԤԼ" << endl;
			tea->validOrder();
		}
		else {
			delete teacher;
			cout << "ע���ɹ�" << endl;
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
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) {
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2) {
		cout << "���������ְ���ţ�" << endl;
		cin >> id;
	}

	cout << "����������û�����" << endl;
	cin >> name;
	cout << "������������룺" << endl;
	cin >> pwd;

	if (type == 1) {
		//ѧ����½��֤
		int fID;
		string fName;
		string fPwd;

		while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
			cout << fID << fName << fPwd << endl;
			if (id == fID && name == fName && pwd == fPwd) {
				cout << "ѧ����֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {
		//��ʦ��½��֤
		int fID;
		string fName;
		string fPwd;

		while (ifs >> fID && ifs >> fName && ifs >> fPwd) {
			cout << fID << fName << fPwd << endl;
			if (id == fID && name == fName && pwd == fPwd) {
				cout << "��ʦ��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {
		//����Ա��½��֤
		string fName;
		string fPwd;

		while (ifs >> fName && ifs >> fPwd) {
			cout << fName << fPwd << endl;
			if (name == fName && pwd == fPwd) {
				cout << "����Ա��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);//�������Ա�Ӳ˵�


				return;
			}
		}
	}

	cout << "��֤��½ʧ��" << endl;


	system("pause");
	system("cls");
	return;
}



int main() {
	int select;
	while (true) {
		cout << "=========  ��ӭʹ�û���ԤԼϵͳ  ==========" << endl;

		cout << "�������������" << endl;
		cout << "1. ѧ������" << endl;
		cout << "2. ��ʦ" << endl;
		cout << "3. ����Ա" << endl;
		cout << "4. �˳�" << endl;
		cout << "����ѡ���ǣ�" << endl;

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
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������� ������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}