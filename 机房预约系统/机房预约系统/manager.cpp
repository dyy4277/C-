#include"manager.h"
#include<fstream>
#include"globalFile.h"


using namespace std;

Manager::Manager() {
};

Manager::Manager(string name, string pwd) {
	this->name = name;
	this->pwd = pwd;

	this->initVector();

	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	Computer C;
	while (ifs >> C.comId && ifs >> C.MaxNum) {
		this->vCom.push_back(C);
	}
	cout << "��ǰ��������Ϊ:" << vCom.size() << endl;

	ifs.close();
};

void Manager::operMenu() {
	cout << "��ӭ����Ա" << this->name << "��½" << endl;
	cout << "1. ����˺�"<< endl;
	cout << "2. �鿴�˺�" << endl;
	cout << "3. �鿴����" << endl;
	cout << "4. ���ԤԼ" << endl;
	cout << "0. ע���˺�" << endl;
	cout << endl;
};

void Manager::addPerson() {
	cout << "����������˺�����" << endl;
	cout << "1 ���ѧ��" << endl;
	cout << "2 �����ʦ" << endl;

	string filename;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������:";
	}
	else if (select == 2) {
		filename = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������:";
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true) {
		cin >> id;
		if (this->checkRepeat(id, select)) {
			cout << errorTip << endl;
		}
		else
		{
			break;
		};
	}
	cout << "����������" << endl;
	cin >> name;
	cout << "����������" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
};

void Manager::showPerson() {
	for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++) {
		cout << "ѧ�ţ�" << (*it).s_id << "   ������" << (*it).name << "   ����" << (*it).pwd << endl;
	}

	cout << endl;
	for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++) {
		cout << "ְ���ţ�" << (*it).empId<< "\t������" << (*it).name << "\t����" << (*it).pwd << endl;
	}
};

void Manager::showComputer() {
	cout << "������Ϣ����:" << endl;
	for (vector<Computer>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout <<" ������ţ�" << (*it).comId << "   �����������" << (*it).MaxNum << endl;
	}
	system("pause");
	system("cls");
};


void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
};

void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs>>s.s_id&&ifs>>s.name&&ifs>>s.pwd){
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ:" << vStu.size() << endl;
	ifs.close();//ѧ����ʼ��

	ifs.open(TEACHER_FILE,ios::in);

	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs >> t.pwd) {
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ:" << vTea.size() << endl;
	ifs.close();//��ʦ��ʼ��
};

bool Manager::checkRepeat(int id, int type) {
	if (type == 1) {
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {
			if (id == it->s_id) {
				return true;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {
			if (id == it->empId) {
				return true;
			}
		}
	}

	return false;
};