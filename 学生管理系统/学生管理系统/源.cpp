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
		cout << "�����������޷���ӣ�" << endl;
		return;
	}
	else
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->studentsarray[abs->m_size].m_name = name;
		cout << "�������Ա�" << endl;
		cout << "1--��" << endl;
		cout << "2--Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
				abs->studentsarray[abs->m_size].m_sex = sex;
			break;
		}
		cout << "�����������������" << endl;
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->studentsarray[abs->m_size].m_age = age;
		cout << "������绰����" << endl;
		string phone;
		cin >> phone;
		abs->studentsarray[abs->m_size].m_phone = phone;
		cout << "������סַ" << endl;
		string address;
		cin >> address;
		abs->studentsarray[abs->m_size].m_address = address;
		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("cls");
	}
	void showperson(students * abs)
	{
		if (abs.m_size == 0)
		{
			cout << "ͨѶ¼Ϊ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		for (int i = 0;i < abs.m_size;i++)
		{

			cout << "����:" << studentsarray[i].name << "\t";
			cout << "�Ա�:" << studentsarray[i].sex << "\t";
			cout << "����:" << studentsarray[i].age << "\t";
			cout << "�绰:" << studentsarray[i].phone << "\t";
			cout << "��ַ:" << studentsarray[i].address << endl;
			system("pause");
			system("cls");
		}
		int isexist(students * abs, string name)
		{
			for (int i = 0;i < abs->m_size;i++)
			{
				if (abs->studentsarray[i].name == name)
				{
					cout << "�ҵ���" << endl;
					return i;
				}
			}
		return -1;
	    }
		void deleteperson(students*abs)
		{
			cout<< "��������Ҫ���ҵ�ѧ��" << endl;
			string name;
			cin >> name;		 
			int ret = isexist(abs, name);






void showMENU()
{
	cout << "************************" << endl;
	cout << "*****  1.���ѧ��  *****" << endl;
	cout << "*****  2.��ʾѧ��  *****" << endl;
	cout << "*****  3.ɾ��ѧ��  *****" << endl;
	cout << "*****  4.����ѧ��  *****" << endl;
	cout << "*****  5.�޸�ѧ��  *****" << endl;
	cout << "*****  6.���ѧ��  *****" << endl;
	cout << "***  0.�˳�����ϵͳ  ***" << endl;
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
		cout << "�˳�����ɹ���" << endl;
		system("pause");
		return 0;
	default:
		break;
	}
}