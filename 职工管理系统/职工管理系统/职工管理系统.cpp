#include "ְ������ϵͳ.h"

int main() {
	WorkerManager WM;
	
	int choice = 0;
	while (true) {
		WM.showMaue();
		cout << "��������ѡ��" << endl;
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

	cout << two << "    " << "��ӭʹ��ְ������ϵͳ" << "    " << two << endl;

	cout << three << "\t" << "0.�˳�����ϵͳ" << "\t" << three << endl;
	cout << three << "\t" << "1.���Ա����Ϣ" << "\t" << three << endl;
	cout << three << "\t" << "2.��ʾְ����Ϣ" << "\t" << three << endl;
	cout << three << "\t" << "3.ɾ����ְԱ��" << "\t" << three << endl;
	cout << three << "\t" << "4.�޸�Ա����Ϣ" << "\t" << three << endl;
	cout << three << "\t" << "5.����ְ����Ϣ" << "\t" << three << endl;
	cout << three << "\t" << "6.���ձ������" << "\t" << three << endl;
	cout << three << "\t" << "7.��������ĵ�" << "\t" << three << endl;

	cout << i << endl;
}

void WorkerManager::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
};

Employee::Employee(int id, string name, int did) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptId = did;
}

void Employee::showInfo() {
	cout << "ְ�����:" << this->m_ID
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��: ��ɾ�����������"<<endl;
}

string Employee::getDeptName() {
	return string("Ա��");
}