#include<iostream>
using namespace std;
#include<string>
#define max 1000

struct person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_address;
};
struct students
{
	struct person studentsarray[max];
	int m_size;
};
void addperson(students* abs)
{
	if (abs->m_size == max)
	{
		cout << "人数已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->studentsarray[abs->m_size].m_name = name;
		cout << "请输入性别" << endl;
		cout << "1--男" << endl;
		cout << "2--女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
				abs->studentsarray[abs->m_size].m_sex = sex;
			break;
		}
		cout << "输入错误，请重新输入" << endl;
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->studentsarray[abs->m_size].m_age = age;
		cout << "请输入电话号码" << endl;
		string phone;
		cin >> phone;
		abs->studentsarray[abs->m_size].m_phone = phone;
		cout << "请输入住址" << endl;
		string address;
		cin >> address;
		abs->studentsarray[abs->m_size].m_address = address;
		abs->m_size++;
		cout << "添加成功！" << endl;
		system("cls");
	}
	void showperson(students * abs)
	{
		if (abs.m_size == 0)
		{
			cout << "通讯录为空" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0;i < abs.m_size;i++)
		{

			cout << "姓名:" << studentsarray[i].name << "\t";
			cout << "性别:" << studentsarray[i].sex << "\t";
			cout << "年龄:" << studentsarray[i].age << "\t";
			cout << "电话:" << studentsarray[i].phone << "\t";
			cout << "地址:" << studentsarray[i].address << endl;
			system("pause");
			system("cls");
		}
		int isexist(students * abs, string name)
		{
			for (int i = 0;i < abs->m_size;i++)
			{
				if (abs->studentsarray[i].name == name)
				{
					cout << "找到了" << endl;
					return i;
				}
			}
		return -1;
	    }
		void deleteperson(students*abs)
		{
			cout<< "请输入你要查找的学生" << endl;
			string name;
			cin >> name;		 
			int ret = isexist(abs, name);






void showMENU()
{
	cout << "************************" << endl;
	cout << "*****  1.添加学生  *****" << endl;
	cout << "*****  2.显示学生  *****" << endl;
	cout << "*****  3.删除学生  *****" << endl;
	cout << "*****  4.查找学生  *****" << endl;
	cout << "*****  5.修改学生  *****" << endl;
	cout << "*****  6.清空学生  *****" << endl;
	cout << "***  0.退出管理系统  ***" << endl;
	cout << "************************" << endl;
}
int main()
{;
     students abs;
	 abs.m_size = 0;

	int select = 0;
	while (true)
	{

	}
	showMENU();
	cin >> select;
	switch (select)
	{
	case 1:
		addperson(&abs);
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
	case 0:
		break;
		cout << "退出程序成功！" << endl;
		system("pause");
		return 0;
	default:
		break;
	}
}