//дһ��С�͵�DBMS��Ŀǰֻ��user1���database����������д�����ṹ�Ĺ���
//���ԶԱ��������ɾ���ġ��顢�������ݹ���
#include<map>
#include"table.h"
#include"Database.h"
#include<iostream>
using namespace std;
#include<sstream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<stdlib.h>
#include<io.h>
#include <sstream>
#include<time.h>
#pragma warning(disable:4996)
//string PATH_DB = "C:\\Users\\27197\\Desktop\\ɽ��ʦ����ѧ\\MyDBMS\\user1\\user1.txt";
//
//class tableinform {
//public:
//	vector<string> tablenames;
//	int count = 0;
//public:
//	void showtables()
//	{
//		updatetables();   //��ӡ֮ǰ�ȸ���
//		cout << "��ǰ���У�" << endl;
//		for (int i = 0; i < tablenames.size(); i++)
//		{
//			if (strcmp(tablenames[i].c_str(), ".") != 0 && strcmp(tablenames[i].c_str(), "..") != 0)
//			{
//				count++;
//				cout << tablenames[i] << endl;
//			}
//		}
//		if (count == 0) cout << "null" << endl;   //����û�б�
//	}
//	void updatetables()
//	{
//		this->tablenames.clear();
//		intptr_t Handle;
//		struct _finddata_t FileInfo;
//		string p;
//		string path = "C:\\Users\\27197\\Desktop\\ɽ��ʦ����ѧ\\MyDBMS\\user1";
//		if ((Handle = _findfirst(p.assign(path).append("\\*").c_str(), &FileInfo)) == -1)
//			printf("û���ҵ�ƥ�����Ŀ\n");
//		else
//		{
//			this->tablenames.push_back(FileInfo.name);
//			//printf("%s\n", FileInfo.name);
//			while (_findnext(Handle, &FileInfo) == 0)
//				//printf("%s\n", FileInfo.name);
//				this->tablenames.push_back(FileInfo.name);
//			_findclose(Handle);
//		}
//	}
//};
//tableinform TI;
//class table {    //Ĭ������Ϊ��һ������
//public:
//	string tablename;
//	vector<string> row;
//	vector<string> type;
//public:
//	table() { }
//	~table() {}
//	int Init(vector<string> p)   //��ʼ����
//	{
//		tablename = p[0];
//		for (int i = 1; i < p.size(); i++)
//		{
//			if (i % 2 == 0) type.push_back(p[i]);
//			else row.push_back(p[i]);
//		}
//		//������
//		string path = "C:\\Users\\27197\\Desktop\\ɽ��ʦ����ѧ\\MyDBMS\\user1\\" + tablename + ".txt";
//		ofstream MyFile(path);
//		MyFile.close();
//		//for (int i = 0; i < row.size(); i++)
//		//	MyFile << row[i] + "      ";
//		return 0;
//	}
//	void ShowRows()
//	{
//		for (int i = 0; i < row.size(); i++)
//		{
//			cout << row[i] + "\t";
//		}
//		cout << endl;
//	}
//	void AddDatas()  //ֻ������һ��������Ԫ��
//	{
//		string path = PATH + tablename + ".txt";
//		fstream fp;
//		fp.open(path, ios::app | ios::out);
//		string input;
//		for (int i = 0; i < row.size(); i++)
//		{
//			cin >> input;
//			fp << input <<"\t";
//		}
//		fp << endl;
//		fp.close();
//		cout << "������ӳɹ���" << endl;
//	}
//	void DeleteData()
//	{
//		string path = PATH + tablename + ".txt";
//		ifstream fp(path);
//		vector<string> data;
//		string output;
//		int count = -1;
//		while (fp) {
//	        fp >> output;
//			data.push_back(output);
//			cout << output << endl;
//		}
//		fp.close();
//		cout << "������Ҫɾ����Ϣ�����룺";
//		cin >> output;
//		for (int i = 0; i < data.size(); i++)
//		{
//			if (strcmp(data[i].c_str(), output.c_str()) == 0)
//			{
//				//cout << "ɾ���ɹ�" << endl;
//				count = i;
//			}
//		}
//
//		//д������
//		fstream f;
//		f.open(path, ios::out);
//		int flag = 0;   //���б�־
//		if (count != -1)
//		{
//			for (int i = 0; i < data.size() - 1; i++)
//			{
//				if (i >= count && i <= count + row.size()-1)
//					continue;
//				flag++;
//				f << data[i]<<"\t";
//				if (flag % row.size() == 0)
//					f << "\n";
//			}
//			f.close();
//			cout << "ɾ���ɹ���" << endl;
//		}
//		else
//			cout << "��Ҫɾ������Ϣ������!" << endl;
//	}
//	void SearchData()
//	{
//		string path = PATH + tablename + ".txt";
//		ifstream fp(path);
//		vector<string> datas;
//		string output;
//		int count = -1;
//		while (fp) {
//			fp >> output;
//			datas.push_back(output);
//			cout << output << endl;
//		}
//		fp.close();
//		cout << "��Ҫ��ѯʲô��Ϣ?:";
//		string data;
//		cin >> data;
//		for (int i = 0; i < datas.size() - 1; i++)
//		{
//			if (strcmp(data.c_str(), datas[i].c_str()) == 0)
//			{
//				cout << "������Ϊ:" << endl;
//				for (int j = i; j < i + row.size(); j++)
//					cout << datas[j] << "\t";
//				cout << endl;
//				return;
//			}
//		}
//		cout << "�����ݲ����ڣ�" << endl;
//		return;
//	}
//	void Changedata()
//	{
//		//��ȡ���е����ݵ�datas
//		string path = PATH + tablename + ".txt";
//		ifstream fp(path);
//		vector<string> datas;
//		string output;
//		int count = -1;
//		while (fp) {
//			fp >> output;
//			datas.push_back(output);
//			cout << output << endl;
//		}
//		fp.close();
//		//�޸�datas
//		string data;
//		cout << "������Ҫ�޸����ݵ����룺";
//		cin >> data;
//		int flag = 0;
//		for (int i = 0; i < datas.size()-1; i++)
//		{
//			if (strcmp(datas[i].c_str(), data.c_str()) == 0) //����ƥ��
//			{
//				flag = 1;
//				cout << "�����ݴ��ڣ���������Ϣ���滻��:" << endl;
//				for (int j = 0; j < row.size(); j++)
//				{
//					cin >> data;
//					datas[i + j] = data;	
//				}
//				cout << "�滻�ɹ���" << endl;
//				break;
//			}
//		}
//		if(flag == 0)
//			cout << "�����ݲ����ڣ�" << endl;
//		//datas���������ļ���
//		fstream f;
//		f.open(path, ios::out);
//		for (int i = 0; i < datas.size() - 1; i++)
//		{
//			f << datas[i] << "\t";
//			if ((i+1) % row.size() == 0)
//				f << endl;
//		}
//		f.close();
//	}
//};
//int CreatTable(table& tab)  //1-success 2-fail
//{ 
//	vector<string> p;
//	string push;
//	cout << "��������Ҫ�����ı���,����������,�������ͣ�";     //help
//	cin >> push;
//	string path1 = push + ".txt";
//	for (int i = 0; i < TI.tablenames.size(); i++)
//		if (strcmp(path1.c_str(), TI.tablenames[i].c_str()) == 0)
//		{
//			cout << "�ñ��Ѿ����ڣ�" << endl;
//			return 2;
//		}
//	p.push_back(push);
//	while (cin >> push && strcmp(push.c_str(),"#") != 0)
//	{
//		if (strcmp(push.c_str(), "{") != 0 && strcmp(push.c_str(),"}") != 0)
//			p.push_back(push);
//	}
//	//cout << p.size();
//	/*for (int i = 0; i < p.size(); i++)
//	{
//		cout << p[i] << endl;
//	}*/
//	//��������ʱ�Ͱ���Ϣ�洢��user1.txt�ļ���
//	ofstream f;
//	f.open(PATH_DB, ios::app | ios::out);
//	f << endl;
//	for (int i = 0; i < p.size(); i++)
//	{
//		f << p[i] << "\t";
//	}
//	f << endl;
//	f.close();
//	tab.Init(p);
//	TI.updatetables();
//	cout << p[0] + "�����ɹ���" << endl;
//	return 1;
//}
//std::vector<std::string> stringSplit(const std::string& strIn, char delim) {     //�ָ��ַ�������
//	char* str = const_cast<char*>(strIn.c_str());   //const_castȥ��strIn��const�޶�
//	std::string s;
//	s.append(1, delim);
//	std::vector<std::string> elems;
//	char* splitted = strtok(str, s.c_str());
//	while (splitted != NULL) {
//		elems.push_back(std::string(splitted));
//		splitted = strtok(NULL, s.c_str());
//	}
//	return elems;
//}
//std::vector<std::string> stringSplit(const std::string& strIn, char delim) {     //�ָ��ַ�������
//	char* str = const_cast<char*>(strIn.c_str());   //const_castȥ��strIn��const�޶�
//	std::string s;
//	s.append(1, delim);
//	std::vector<std::string> elems;
//	char* splitted = strtok(str, s.c_str());
//	while (splitted != NULL) {
//		elems.push_back(std::string(splitted));
//		splitted = strtok(NULL, s.c_str());
//	}
//	return elems;
//}
int main()
{
	//ʵ��������Լ��


	//������ʼִ��ʱ�ͼ�¼�µ�ǰDBMS�ı���    -> ��ʼʱ���������ݿ������еı�
	//TI.updatetables();
	//ʵ�ֵ�����
	/*Database DB1;
	DB1.Init();
	DB1.printTables();

	DB1.creatTable();
	int len = DB1.tables.size();
	DB1.tables[len - 1].AddDatas();
	DB1.printTables();*/
	//DB1.creatTable();
	//DB1.printTables()

	/*DB1.tables[2].ShowRows();
	TI.showtables(); 
	int number = 1;
	table table1;
	if (number == 1)
	{
		CreatTable(table1);
	}*/
	/*table1.ShowRows();
	table1.AddDatas();
	table1.AddDatas();
	table1.AddDatas();*/
	//table1.AddDatas();
	//table1.DeleteData();
	//table1.SearchData();
	//table1.Changedata();
	//string path = PATH + "student1" + ".txt";
	//fstream f;
	//f.open(path, ios::out|ios::app);
	////��������д������� 
	//f << "123323" << " " << "abs" << endl;
	//f.close();
	//����һ��user1�����ݿ�
	
	/*cout << "����һ��С�͵�DBMS�����Դ���database��table����������Ҫִ�е�ָ�";
	string str;
	cin >> str;*/
	/*string str1 = "nihao\tniahd\tai\t";
	vector<string> test = stringSplit(str1, '\t');
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << endl;*/
	//time_t nowtime;
	//time(&nowtime); //��ȡ1970��1��1��0��0��0�뵽���ھ���������
	//tm* p = localtime(&nowtime); //������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,����Ҫ+1
	//printf("%04d:%02d:%02d\n", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday);
	//string str = "100";
	//int i = atoi(str.c_str());
	//cout << i;
	/*string input = "2021-12-21";
	vector<string> str_date1;
	str_date1.push_back(input.substr(4, 1));
	str_date1.push_back(input.substr(7, 1));
	for (int i = 0; i < str_date1.size(); i++)
		cout << str_date1[i] << endl;*/

	//table tab1;
	//tab1.AddDatas();
	/*string i;
	cin >> i;
	cout << tab1.cmpDate(i);*/
	/*string str = "0";
	string strsub = str.substr(19, 1);
	cout << strsub;*/
	//int i = atoi(str.c_str());
	//cout << i;
	//puts("nihao");
	/*string str = "nihao)";
	vector<string> str_sub;
	str_sub = stringSplit(str, ')');
	cout << str_sub[0] << endl;*/
	/*string str = "nugai";
	string str_sub = str.substr(2, 100);
	cout << str_sub << endl;
	cout << str_sub.length();*/
	//����һģʽ
	Database DB1;
	DB1.Init();
	cout << "user1:";
	//test desctable
	DB1.descTable("test1");
    //������� ʵ��һЩsql��� ��׼Ϊmysql
	return 0;
}


























//string NumberToString(int x) {
//	stringstream s{};
//	s << x;
//	return s.str();
//}
//class date{
//public:
//	int year;
//	int month;
//	int day;
//public:
//	date() {}
//	date(int ye, int mo, int da)
//	{
//		this->year = ye;
//		this->month = mo;
//		this->day = da;
//	}
//	~date() {}
//	void setdate(int y, int m, int d)
//	{
//		this->year = y;
//		this->month = m;
//		this->day = d;
//	}
//	friend ostream& operator <<(ostream& out, date& d);
//};
//ostream& operator <<(ostream& out, date& d)
//{
//	out << d.year << "-" << d.month << "-" << d.day;
//	return out;
//}
//class mychar {
//public:
//	int length = 0;
//	char* string = nullptr;
//public:
//	mychar(int len) {
//		this->length = len; //�����ٸı�
//		string = new char[length];
//	};
//	void inputstr(char* str)
//	{
//		strcpy(string, str);
//	}
//	~mychar() {}
//};
//class myvarchar {
//public:
//	int length = 0;
//	char* string = nullptr;
//public:
//	myvarchar(int len)
//	{
//		this->length = len;//��ı�
//		string = new char[length];
//	}
//	void inputstr(char* str)
//	{
//		this->length = sizeof(str);
//		string = new char[length];
//		strcpy(string, str);
//	}
//	~myvarchar() {}
//};
//date bd;
//class Student {  //Student��Ķ���
//public:
//	mychar number;   //ɽʦ��׼ mychar(12)-�̶�
//	myvarchar name; //���� myvarchar(8)-�ɱ�
//	mychar sex; //�Ա� mychar(2)
//	date birthdata; //�������� date
//	myvarchar sdept; //����ϵ myvarchar(20)
//	Student* next = NULL;
//public:
//	 Student(char* sn, char* na, char* se, date bd, char* sd):number(20),name(20),sex(10),sdept(20)
//	{
//		 this->number.inputstr(sn);
//		 this->name.inputstr(na);
//		 this->sex.inputstr(se);
//		 this->birthdata.day = bd.day;
//		 this->birthdata.month = bd.month;
//		 this->birthdata.year = bd.year;
//		 this->sdept.inputstr(sd);
//	}
//	~Student() {}
//	void showdata()
//	{
//		cout << " " << number.string << " " << name.string << " " << sex.string << " " << birthdata << " " << sdept.string << endl;
//	}
//};
//class tablehead { //ѧ����ı�ͷ
//public:
//	Student* next = NULL;
//	string number = "ѧ��";
//	string name = "����";
//	string sex = "�Ա�";
//	string date = "��������";
//	string sdept = "���ڲ���";
//	int count = 0;
//public:
//	tablehead() {}
//	~tablehead() {}
//	void showdatas()   //��ʾ�������������
//	{
//		cout << "  " << number << "  " << name << "  " << sex << "  " << date << "  " << sdept << endl;;
//		Student* p = this->next;
//		while (p != NULL)
//		{
//		    p->showdata();
//			p = p->next;
//		}
//	}
//	void adddata()
//	{   
//		int month = 0, year = 0, day = 0;
//		char num[14] = { " " };
//		char na[8] = { " " };
//		char se[4] = { " " };
//		char sdep[20] = { " " };
//		if (count == 0)
//		{
//			cout << "��������Ҫ��ӵ�������(ѧ��,����,�Ա�,��������,���ڲ���):";
//			cin >> num >> na >> se >> year >> month >> day >> sdep;
//			bd.setdate(year, month, day);
//			this->next = new Student(num, na, se, bd, sdep);
//		}
//		else
//		{ 
//			cout << "��������Ҫ��ӵ�������(ѧ��,����,�Ա�,��������,���ڲ���):";
//			Student* p = this->next;
//			while (p->next != NULL)
//			{
//				p = p->next;
//			}
//			cin >> num >> na >> se >> year >> month >> day >> sdep;
//			bd.setdate(year, month, day);
//			p->next = new Student(num, na, se, bd, sdep);
//		}
//		count++;
//		Student* p1 = new Student(num, na, se, bd , sdep);
//	}
//
//	void dropdata()
//	{
//		char num[20] = { " " };
//		cout << "������Ҫɾ��ѧ����ѧ��:";
//		cin >> num;
//		Student* p = this->next;
//		Student* p1 = NULL;
//		while (p->next != NULL)
//		{
//			p1 = p->next;
//			if (strcpy(p1->number.string, num) == 0)
//			{
//				p->next = p1->next;
//				delete p1;
//			}
//			p = p->next;
//			count--;
//		}
//		if (strcpy(p->number.string, num) == 0)
//		{
//			delete p;
//			count--;
//		}
//		
//	}
//	void showdataname()
//	{
//		cout << "ѧ�� ���� �Ա� �������� ���ڲ���" << endl;
//	}
//	void showdatatype()
//	{
//		cout << "ѧ��:mychar(20)" << endl;
//		cout << "����:myvarchar(20)" << endl;
//		cout << "�Ա�:myvarchar(10)" << endl;
//		cout << "��������:date" << endl;
//		cout << "���ڲ���:myvarchar(20)" << endl;
//
//	}
//};



















//int main()
//{
	////�ȶ���һ����ͷ,ȷ�������Ŀ
	//cout << "����һ��С�͵�DBMS��Ŀǰֻʵ����ѧ�������ع���" << endl;
	//cout << "1.Ϊ�����������" << endl;
	//cout << "2.ɾ�����е�������" << endl;
	//cout << "3.��ʾ����ֶ���" << endl;
	//cout << "4.��ʾ����ֶ�����" << endl;
	//cout << "5.��ʾ��ǰ��洢����������" << endl;
	//cout << "�������������еĹ���(����0�˳���ϵͳ):";
	//int a = 0;
	//cin >> a;
	//if (0 == a) {
	//	cout << "�ɹ��˳���ϵͳ��" << endl;
	//	exit(0);
	//}
	//tablehead* head = new tablehead();
	//while (a)
	//{
	//	switch (a)
	//	{
	//	case 1:
	//		head->adddata();
	//		cout << "���������ɹ�!" << endl;
	//		break;
	//	case 2:
	//		head->dropdata();
	//		cout << "ɾ��������ɹ�!" << endl;
	//		break;
	//	case 3:
	//		head->showdataname();
	//		break;
	//	case 4:
	//		head->showdatatype();
	//		break;
	//	case 5:
	//		head->showdatas();
	//		break;
	//	}
	//	cout << "1.Ϊ�����������" << endl;
	//	cout << "2.ɾ�����е�������" << endl;
	//	cout << "3.��ʾ����ֶ���" << endl;
	//	cout << "4.��ʾ����ֶ�����" << endl;
	//	cout << "5.��ʾ��ǰ��洢����������" << endl;
	//	cout << "�������������еĹ���(����0�˳���ϵͳ):";
	//	cin >> a;
	//}
	//cout << "�ɹ��˳���ϵͳ��" << endl;
	//һ�������һ��txt�ļ�


	//return 0;
//}