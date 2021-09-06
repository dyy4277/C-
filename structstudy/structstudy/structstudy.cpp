#include "structstudy.h"
/*
�ṹ�������û��Զ�����������ͣ������û��洢��ͬ����������
*/
int main() {
	//�﷨:struct �ṹ����{�ṹ���Ա�б�};
	/*
	ͨ���ṹ�崴�������ķ�ʽ������:
	struct �ṹ���� ������;
	struct �ṹ���� ������ = {��Ա1ֵ����Ա2ֵ��...}
	����ṹ����˳�㴴������
	*/
	//��һ��
	struct student s1;
	s1.name = "������";
	s1.age = 22;
	s1.score = 99;
	cout << s1.name <<" " << s1.age <<" " << s1.score << endl;

	//�ڶ���
	struct student s2 = { "С����",18,77 };
	cout << s2.name << " " << s2.age << " " << s2.score << endl;
	
	s3.name = "����";
	s3.age = 22;
	s3.score = 99;
	s1.name = "������";
	s1.age = 22;
	s1.score = 99;
	cout << s1.name << " " << s1.age << " " << s1.score << endl;


	//�ṹ�����飺struct �ṹ���� ������{Ԫ�ظ���} = {{},{},{},{}...}
	struct student stuArr[3] = {
		{"������",12,33},
		{"����",23,55},
		{"������",22,66}
	};
	stuArr[1].name = "С����";
	cout << stuArr[1].name << " " << stuArr[1].age << " " << stuArr[1].score << endl;


	//�ṹ��ָ��
	//���ò�����->����ͨ�����ʽṹ��ָ����ʽṹ������
	struct student stu = { "�����䰡",18,99 };
	struct student* p = &stu;
	//ͨ��ָ����ʽṹ������е�����
	cout << p->name << " " << p->age << " " << p->score << endl;

	
	//�ṹ��Ƕ�׽ṹ��
	struct teacher {
		int id;
		string name;
		int age;
		struct student stu;
	};
	teacher t;
	t.id = 10000;
	t.age = 89;
	t.name = "С����";
	t.stu.name = "С����";
	t.stu.age = 19;
	t.stu.score = 89;

	cout << t.id << " " << t.age << " " << t.name << " " << t.stu.name << " " << t.stu.age << " " << t.stu.score << endl;
	

	//�ṹ������������
	//ֵ����&��ַ����
	structstudent(stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	spstudent(&stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	
	//�����ṹ��ָ��
	//�������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ�������


	system("pause");
	return 0;
}
//ֵ����
void structstudent(student stu) {
	stu.age = 333;
	stu.name = "��ɵ��";
	stu.score = 99;
	cout << sizeof(stu.name) << endl;
}

//��ַ����
void spstudent(student* stu) {
	stu->name = "Сɵ��";
	stu->age = 78;
	stu->score = 199;
}

//�������е��βθ�Ϊָ�룬���Լ����ڴ�ռ䣬���Ҳ��Ḵ���µĸ�������
//�����ṹ��ָ�벻�ɱ��޸�,һ�����޸ĵĲ����ͻᱨ�����Է�ֹ�����
void printstu(const student *stu) {
	//stu-> age = 150;����
	cout << "����:" << stu->name << "\n����:" << stu->age << "\n�ɼ�:" << stu->score << endl;
}