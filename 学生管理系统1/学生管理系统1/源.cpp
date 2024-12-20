#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

struct person
{
	//ѧ������
	string name;
	//����
	int age;
	//�Ա� �С�Ů
	string sex;
	//�绰
	string m_phone;
	//סַ
	string m_addr;
};

struct addressbooks
{
	// ϵͳ�б����ѧ������
	int m_size;
	// ϵͳ�б����ѧ������
	person arry[MAX];
};

// �˵���ʾ����
void showmanue()
{
	cout << "****************************************************" << endl;
	cout << "*************    1�����ѧ��      ******************" << endl;
	cout << "*************    2����ʾѧ��      ******************" << endl;
	cout << "*************    3��ɾ��ѧ��      ******************" << endl;
	cout << "*************    4������ѧ��      ******************" << endl;
	cout << "*************    5���޸�ѧ��      ******************" << endl;
	cout << "*************    6�����ѧ��      ******************" << endl;
	cout << "*************    0���˳�ϵͳ      ******************" << endl;
	cout << "****************************************************" << endl;
}

//���ѧ��
void addperson(addressbooks* A)
{
	//���ж�ϵͳ�Ƿ����
	if (A->m_size == MAX)
	{
		cout << "ϵͳ�Ѵ������޷����룡" << endl;
		return;
	}
	else
	{
		//����
		string name;
		cout << "����������:";
		cin >> name;
		A->arry[A->m_size].name = name;
		//�Ա�
		cout << "�������Ա�:";
		string sex;
		while (true)
		{
			cin >> sex;
			if (sex == "��" || sex == "Ů")
			{
				A->arry[A->m_size].sex = sex;
				break;
			}
			cout << "�������������������룡" << endl;
		}
		//����
		int age = 0;
		cout << "���������䣺";
		cin >> age;
		A->arry[A->m_size].age = age;
		//�绰
		string phone;
		cout << "������绰���룺";
		cin >> phone;
		A->arry[A->m_size].m_phone = phone;
		//סַ
		string addr;
		cout << "������סַ��";
		cin >> addr;
		A->arry[A->m_size].m_addr = addr;

		A->m_size++;

		cout << "��ӳɹ���" << endl;
		system("pause");//�밴���������
		system("cls");//��������
	}

}

//����ѡ����
int shuruxuanze()
{
	int select = 0;
	cout << "������ѡ��";
	cin >> select;
	return select;
}

//��ʾѧ��
void show(addressbooks A)
{
	//�ж�ϵͳ�Ƿ�Ϊ��
	if (A.m_size == 0)
	{
		cout << "ϵͳΪ�գ�" << endl;
		system("pause");//�밴���������
		system("cls");//��������
		return;
	}
	for (int i = 0; i < A.m_size; i++)
	{
		cout << "������" << A.arry[i].name << "\t";
		cout << "���䣺" << A.arry[i].age << "\t";
		cout << "�Ա�" << A.arry[i].sex << "\t";
		cout << "�绰��" << A.arry[i].m_phone << "\t";
		cout << "סַ��" << A.arry[i].m_addr << endl;
	}

	system("pause");//�밴���������
	system("cls");//��������
}

//���ѧ���Ƿ���ڣ�������ڣ�����ѧ���������еľ���λ�ã����򷵻�-1
int isexist(addressbooks A, string name)
{
	for (int i = 0; i < A.m_size; i++)
	{
		if (A.arry[i].name == name)
		{
			cout << "�ҵ���" << endl;
			return i; //�ҵ��ˣ��������������λ�õ��±�
		}
	}
	cout << "�����ҵ��˲�����" << endl;
	return -1;//�����ڣ�����-1
}

//ɾ��ѧ��
void deleteperson(addressbooks* A, string name)
{
	int i = isexist(*A, name);
	//���ж���Ҫɾ����ѧ���Ƿ����
	if (i == -1)
	{
		cout << "��Ҫɾ������ϵ�˲����ڣ�" << endl;
	}
	else
	{
		for (int j = i + 1; j < A->m_size; j++)//��Ҫɾ����Ԫ�غ����Ԫ��������ǰ��һλ
		{
			A->arry[i] = A->arry[j];
			i++;
		}
		A->m_size -= 1;    //ͨѶ¼Ԫ�ظ�����һ
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");//�밴���������
	system("cls");//��������
}

//�޸�ѧ��
void amendperson(addressbooks* A)
{
	while (true)
	{
		string name;
		cout << "������Ҫ�޸ĵ��˵�������";
		cin >> name;
		int i = isexist(*A, name);
		//���ж���Ҫɾ����ѧ���Ƿ����
		if (i == -1)
		{
			cout << "��Ҫɾ����ѧ�������ڣ����������룡" << endl;
		}
		else
		{
			cout << "���޸�ѧ��" << endl;
			//����
			cout << "����������:";
			cin >> name;
			A->arry[i].name = name;
			//�Ա�
			cout << "�������Ա�:";
			string sex;
			while (true)
			{
				cin >> sex;
				if (sex == "��" || sex == "Ů")
				{
					A->arry[i].sex = sex;
					break;
				}
				cout << "�������������������룡" << endl;
			}
			//����
			int age = 0;
			cout << "���������䣺";
			cin >> age;
			A->arry[i].age = age;
			//�绰
			string phone;
			cout << "������绰���룺";
			cin >> phone;
			A->arry[i].m_phone = phone;
			//סַ
			string addr;
			cout << "������סַ��";
			cin >> addr;
			A->arry[i].m_addr = addr;
			cout << "�޸ĳɹ���" << endl;
		}
		break;
	}
}

//���ϵͳ
void emptyperson(addressbooks* A)
{
	A->m_size = 0;
	cout << "ϵͳ�Ѿ���գ�" << endl;
}

//������
int main()
{
	//����ϵͳ�ṹ�����
	addressbooks A;
	//��ʼ��ϵͳ����ĸ���
	A.m_size = 0;
	while (true)
	{
		showmanue();
		int select = shuruxuanze();
		if (select == 1 || select == 2 || select == 3 || select == 4 || select == 5 || select == 6 || select == 0)
		{
			switch (select)
			{
			case 1:				//���ѧ��
				addperson(&A);  //���õ�ַ���ݣ���������ʵ��
				break;
			case 2:             //��ʾѧ��
				show(A);
				break;
			case 3://ɾ��ѧ��
			{
				cout << "������Ҫɾ����ѧ��������";
				string name;
				cin >> name;
				deleteperson(&A, name);
				break;
			}
			case 4://����ѧ��
			{
				string name;
				cout << "������Ҫ���ҵ��˵�������";
				cin >> name;
				int i = isexist(A, name);
				if (i == -1)
					cout << "���޴���" << endl;
				else
				{
					cout << "������" << A.arry[i].name << "\t";
					cout << "���䣺" << A.arry[i].age << "\t";
					cout << "�Ա�" << A.arry[i].sex << "\t";
					cout << "�绰��" << A.arry[i].m_phone << "\t";
					cout << "סַ��" << A.arry[i].m_addr << endl;
				}
				system("pause");//�밴���������
				system("cls");//��������
				break;
			}
			case 5://�޸�ѧ��
			{
				amendperson(&A);
				system("pause");//�밴���������
				system("cls");//��������
				break;
			}
			case 6://���ϵͳ
			{
				emptyperson(&A);
				system("pause");//�밴���������
				system("cls");//��������
				break;
			}
			case 0:
			{
				cout << "�˳�ϵͳ����ӭ�´�ʹ��!" << endl;  //�˳�ϵͳ
				system("pause");
				return 0;
				break;
			}
			}
		}
		else
		{
			cout << "��������������������룡" << endl;
			system("pause");//�밴���������
			system("cls");//��������
		}

	}


	system("pause");
	return 0;
}
