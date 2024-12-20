#include <iostream>
#include <string>
using namespace std;
#define MAX 1000

struct person
{
	//学生姓名
	string name;
	//年龄
	int age;
	//性别 男、女
	string sex;
	//电话
	string m_phone;
	//住址
	string m_addr;
};

struct addressbooks
{
	// 系统中保存的学生个数
	int m_size;
	// 系统中保存的学生数组
	person arry[MAX];
};

// 菜单显示函数
void showmanue()
{
	cout << "****************************************************" << endl;
	cout << "*************    1、添加学生      ******************" << endl;
	cout << "*************    2、显示学生      ******************" << endl;
	cout << "*************    3、删除学生      ******************" << endl;
	cout << "*************    4、查找学生      ******************" << endl;
	cout << "*************    5、修改学生      ******************" << endl;
	cout << "*************    6、清空学生      ******************" << endl;
	cout << "*************    0、退出系统      ******************" << endl;
	cout << "****************************************************" << endl;
}

//添加学生
void addperson(addressbooks* A)
{
	//先判断系统是否存满
	if (A->m_size == MAX)
	{
		cout << "系统已存满，无法存入！" << endl;
		return;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名:";
		cin >> name;
		A->arry[A->m_size].name = name;
		//性别
		cout << "请输入性别:";
		string sex;
		while (true)
		{
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				A->arry[A->m_size].sex = sex;
				break;
			}
			cout << "你输入有误，请重新输入！" << endl;
		}
		//年龄
		int age = 0;
		cout << "请输入年龄：";
		cin >> age;
		A->arry[A->m_size].age = age;
		//电话
		string phone;
		cout << "请输入电话号码：";
		cin >> phone;
		A->arry[A->m_size].m_phone = phone;
		//住址
		string addr;
		cout << "请输入住址：";
		cin >> addr;
		A->arry[A->m_size].m_addr = addr;

		A->m_size++;

		cout << "添加成功！" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏继续
	}

}

//输入选择函数
int shuruxuanze()
{
	int select = 0;
	cout << "请输入选择：";
	cin >> select;
	return select;
}

//显示学生
void show(addressbooks A)
{
	//判断系统是否为空
	if (A.m_size == 0)
	{
		cout << "系统为空！" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏继续
		return;
	}
	for (int i = 0; i < A.m_size; i++)
	{
		cout << "姓名：" << A.arry[i].name << "\t";
		cout << "年龄：" << A.arry[i].age << "\t";
		cout << "性别：" << A.arry[i].sex << "\t";
		cout << "电话：" << A.arry[i].m_phone << "\t";
		cout << "住址：" << A.arry[i].m_addr << endl;
	}

	system("pause");//请按任意键继续
	system("cls");//清屏继续
}

//检测学生是否存在，如果存在，返回学生在数组中的具体位置，否则返回-1
int isexist(addressbooks A, string name)
{
	for (int i = 0; i < A.m_size; i++)
	{
		if (A.arry[i].name == name)
		{
			cout << "找到了" << endl;
			return i; //找到了，返回这个人所在位置的下标
		}
	}
	cout << "您查找的人不存在" << endl;
	return -1;//不存在，返回-1
}

//删除学生
void deleteperson(addressbooks* A, string name)
{
	int i = isexist(*A, name);
	//先判断所要删除的学生是否存在
	if (i == -1)
	{
		cout << "所要删除的联系人不存在！" << endl;
	}
	else
	{
		for (int j = i + 1; j < A->m_size; j++)//将要删除的元素后面的元素依次往前移一位
		{
			A->arry[i] = A->arry[j];
			i++;
		}
		A->m_size -= 1;    //通讯录元素个数减一
		cout << "删除成功！" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");//清屏继续
}

//修改学生
void amendperson(addressbooks* A)
{
	while (true)
	{
		string name;
		cout << "请输入要修改的人的姓名：";
		cin >> name;
		int i = isexist(*A, name);
		//先判断所要删除的学生是否存在
		if (i == -1)
		{
			cout << "所要删除的学生不存在！请重新输入！" << endl;
		}
		else
		{
			cout << "请修改学生" << endl;
			//姓名
			cout << "请输入姓名:";
			cin >> name;
			A->arry[i].name = name;
			//性别
			cout << "请输入性别:";
			string sex;
			while (true)
			{
				cin >> sex;
				if (sex == "男" || sex == "女")
				{
					A->arry[i].sex = sex;
					break;
				}
				cout << "你输入有误，请重新输入！" << endl;
			}
			//年龄
			int age = 0;
			cout << "请输入年龄：";
			cin >> age;
			A->arry[i].age = age;
			//电话
			string phone;
			cout << "请输入电话号码：";
			cin >> phone;
			A->arry[i].m_phone = phone;
			//住址
			string addr;
			cout << "请输入住址：";
			cin >> addr;
			A->arry[i].m_addr = addr;
			cout << "修改成功！" << endl;
		}
		break;
	}
}

//清空系统
void emptyperson(addressbooks* A)
{
	A->m_size = 0;
	cout << "系统已经清空！" << endl;
}

//主函数
int main()
{
	//创建系统结构体变量
	addressbooks A;
	//初始化系统保存的个数
	A.m_size = 0;
	while (true)
	{
		showmanue();
		int select = shuruxuanze();
		if (select == 1 || select == 2 || select == 3 || select == 4 || select == 5 || select == 6 || select == 0)
		{
			switch (select)
			{
			case 1:				//添加学生
				addperson(&A);  //利用地址传递，可以修饰实参
				break;
			case 2:             //显示学生
				show(A);
				break;
			case 3://删除学生
			{
				cout << "请输入要删除的学生姓名：";
				string name;
				cin >> name;
				deleteperson(&A, name);
				break;
			}
			case 4://查找学生
			{
				string name;
				cout << "请输入要查找的人的姓名：";
				cin >> name;
				int i = isexist(A, name);
				if (i == -1)
					cout << "查无此人" << endl;
				else
				{
					cout << "姓名：" << A.arry[i].name << "\t";
					cout << "年龄：" << A.arry[i].age << "\t";
					cout << "性别：" << A.arry[i].sex << "\t";
					cout << "电话：" << A.arry[i].m_phone << "\t";
					cout << "住址：" << A.arry[i].m_addr << endl;
				}
				system("pause");//请按任意键继续
				system("cls");//清屏继续
				break;
			}
			case 5://修改学生
			{
				amendperson(&A);
				system("pause");//请按任意键继续
				system("cls");//清屏继续
				break;
			}
			case 6://清空系统
			{
				emptyperson(&A);
				system("pause");//请按任意键继续
				system("cls");//清屏继续
				break;
			}
			case 0:
			{
				cout << "退出系统，欢迎下次使用!" << endl;  //退出系统
				system("pause");
				return 0;
				break;
			}
			}
		}
		else
		{
			cout << "你的输入有误，请重新输入！" << endl;
			system("pause");//请按任意键继续
			system("cls");//清屏继续
		}

	}


	system("pause");
	return 0;
}
