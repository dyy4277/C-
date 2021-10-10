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
	cout << "当前机房数量为:" << vCom.size() << endl;

	ifs.close();
};

void Manager::operMenu() {
	cout << "欢迎管理员" << this->name << "登陆" << endl;
	cout << "1. 添加账号"<< endl;
	cout << "2. 查看账号" << endl;
	cout << "3. 查看机房" << endl;
	cout << "4. 清空预约" << endl;
	cout << "0. 注销账号" << endl;
	cout << endl;
};

void Manager::addPerson() {
	cout << "请输入添加账号类型" << endl;
	cout << "1 添加学生" << endl;
	cout << "2 添加老师" << endl;

	string filename;
	string tip;
	string errorTip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	if (select == 1) {
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入:";
	}
	else if (select == 2) {
		filename = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入:";
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
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
	this->initVector();
};

void Manager::showPerson() {
	for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++) {
		cout << "学号：" << (*it).s_id << "   姓名：" << (*it).name << "   密码" << (*it).pwd << endl;
	}

	cout << endl;
	for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++) {
		cout << "职工号：" << (*it).empId<< "\t姓名：" << (*it).name << "\t密码" << (*it).pwd << endl;
	}
};

void Manager::showComputer() {
	cout << "机房信息如下:" << endl;
	for (vector<Computer>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++) {
		cout <<" 机房编号：" << (*it).comId << "   机房最大容量" << (*it).MaxNum << endl;
	}
	system("pause");
	system("cls");
};


void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
};

void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs>>s.s_id&&ifs>>s.name&&ifs>>s.pwd){
		vStu.push_back(s);
	}
	cout << "当前学生数量为:" << vStu.size() << endl;
	ifs.close();//学生初始化

	ifs.open(TEACHER_FILE,ios::in);

	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs >> t.pwd) {
		vTea.push_back(t);
	}
	cout << "当前教师数量为:" << vTea.size() << endl;
	ifs.close();//教师初始化
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