# include <iostream>

using namespace std;
// �������ڵ����壺�������ǹ����ڴ�ռ�


//�곣����#define�곣����#define ������ ����ֵ
//������const �������� ������ = ����;

#define Week 7

int g = 99;

int main()
{
	typedef int zhengxing;
	int iNum = 10;
	const int Month = 12;
	cout << "hello world" << endl;

	
	/*
	cout << "iNum=" << iNum << endl;
	cout << "һ���ܹ���" << Week << "��" << endl;
	cout << "һ���ܹ���" << Month << "����" << endl;

	//short -32678 ~32768
	short shortNum = 32768;

	//int
	int intNum = 10;

	//long
	long longNum = 10;

	//long long 
	long long llNum = 10;


	//sizeof(��������/����)
	//short(2) int(4) long(4) long long(8)
	cout <<"sizeof(short):"<< sizeof(short) << endl;
	cout << "sizeof(int):" << sizeof(int) << endl;
	cout << "sizeof(longNum) =" << sizeof(longNum) << endl;

	//float/double
	zhengxing iiNum = 0;
	printf("%d",iiNum);

	//ö��,eNum���µ���������ֵ�ֱ�Ϊ9��5
	enum eNum {
		enen = 9,
		eenen = 5,
	};
	eNum En = enen;
	cout << En << endl;
	g++;
	cout << g << endl;
	int g = 88;
	cout << g << endl;


	cout << "ʮ����"<<58 << endl;
	cout << "�˽���" << 057 << endl;
	cout << "ʮ������" << 0x13ab << endl;
	if (0 == false){
		cout << false << endl;
	}

	cout << true << endl;

	char c = 's';
	cout << sizeof(c) << endl;
	cout << int(c) << endl;
	cout<<int('c') << endl;
	cout<<"\tdsf\\\n" << endl;
	cout << "sdsdsa\tdsf\\\n" << endl;
	cout << "s\tdsf\\\n" << endl;

	char cs[] = "dffgdffg";
	cout << cs << endl;

	string ccs = "dsdsasdsdassda";
	cout << ccs << endl;
	
	int inp;
	cin >> inp;
	cout << inp << endl;
	float sd;
	cin >> sd;
	cout << sd << endl;
	char ch;
	cin >> ch;
	cout << ch << endl;
	string str;
	cin >> str;
	cout << str << endl;
	
	cout << 222 %12 << endl;
	int aa = 100;
	cout << "aa++" << aa++ << endl;
	cout << "aa" << aa << endl;
	cout << "++aa" << ++aa << endl;

	cout << !(1 > 2)<< endl;
	cout << ((1 > 2)||(1<3)) << endl;
	int assd;
	cin >> assd;
	if (assd > 100) {
		cout << "sdadas" << endl;
	}else if(assd > 60) {

	}else {
		cout << "sadsafasdf" << endl;
	}
	*/
	int iNum1 = 2;
	int iNum2 = 9;
	iNum1 = (iNum >= 2?1:0);
	cout << iNum1 << endl;
	(iNum1>=iNum2?iNum2:iNum1)= 10;
	cout << "1" << iNum1 << endl;
	cout << "2" << iNum2 << endl;

	//switch
	/*
		switch(���ʽ){
		case ֵ:
			���;
			break;
		...
		
		}
	
	int inp1;
	cin >> inp1;
	switch (inp1) {
	case 1:
		cout << 1 << endl;
		break;
	case 0:
		cout << 0 << endl;
		break;
	default:
		cout << "�������" << endl;
	}
	*/

	//while
	/*
	while(ѭ������){
	���
	};
	*/
	int aaa= 1;
	int b = 0;
	while (b<50){
		b++;
		aaa *= 2;
		cout << aaa << endl;
	}
	do {
		cout << "adasdas" << endl;
	} while (false);
	system("pause");

	return 0;
}