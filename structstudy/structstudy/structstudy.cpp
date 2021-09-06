#include "structstudy.h"
/*
结构体属于用户自定义的数据类型，允许用户存储不同的数据类型
*/
int main() {
	//语法:struct 结构体名{结构体成员列表};
	/*
	通过结构体创建变量的方式有三种:
	struct 结构体名 变量名;
	struct 结构体名 变量名 = {成员1值，成员2值，...}
	定义结构体是顺便创建变量
	*/
	//第一种
	struct student s1;
	s1.name = "大咪咪";
	s1.age = 22;
	s1.score = 99;
	cout << s1.name <<" " << s1.age <<" " << s1.score << endl;

	//第二种
	struct student s2 = { "小咪咪",18,77 };
	cout << s2.name << " " << s2.age << " " << s2.score << endl;
	
	s3.name = "咪咪";
	s3.age = 22;
	s3.score = 99;
	s1.name = "大咪咪";
	s1.age = 22;
	s1.score = 99;
	cout << s1.name << " " << s1.age << " " << s1.score << endl;


	//结构体数组：struct 结构体名 数组名{元素个数} = {{},{},{},{}...}
	struct student stuArr[3] = {
		{"咪咪咪",12,33},
		{"咪咪",23,55},
		{"大咪咪",22,66}
	};
	stuArr[1].name = "小咪咪";
	cout << stuArr[1].name << " " << stuArr[1].age << " " << stuArr[1].score << endl;


	//结构体指针
	//利用操作符->可以通过访问结构体指针访问结构体属性
	struct student stu = { "妈妈咪啊",18,99 };
	struct student* p = &stu;
	//通过指针访问结构体变量中的数据
	cout << p->name << " " << p->age << " " << p->score << endl;

	
	//结构体嵌套结构体
	struct teacher {
		int id;
		string name;
		int age;
		struct student stu;
	};
	teacher t;
	t.id = 10000;
	t.age = 89;
	t.name = "小摸摸";
	t.stu.name = "小咪咪";
	t.stu.age = 19;
	t.stu.score = 89;

	cout << t.id << " " << t.age << " " << t.name << " " << t.stu.name << " " << t.stu.age << " " << t.stu.score << endl;
	

	//结构体做函数参数
	//值传递&地址传递
	structstudent(stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	spstudent(&stu);
	cout << stu.name << " " << stu.age << " " << stu.score << endl;
	
	//常量结构体指针
	//将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来


	system("pause");
	return 0;
}
//值传递
void structstudent(student stu) {
	stu.age = 333;
	stu.name = "大傻逼";
	stu.score = 99;
	cout << sizeof(stu.name) << endl;
}

//地址传递
void spstudent(student* stu) {
	stu->name = "小傻逼";
	stu->age = 78;
	stu->score = 199;
}

//将函数中的形参改为指针，可以减少内存空间，而且不会复制新的副本出来
//常量结构体指针不可被修改,一旦有修改的操作就会报错，可以防止误操作
void printstu(const student *stu) {
	//stu-> age = 150;报错
	cout << "姓名:" << stu->name << "\n年龄:" << stu->age << "\n成绩:" << stu->score << endl;
}