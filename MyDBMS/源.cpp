//写一个小型的DBMS，目前只有user1这个database，完成在其中创建表结构的功能
//可以对表进行增、删、改、查、保存数据功能
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
//string PATH_DB = "C:\\Users\\27197\\Desktop\\山东师范大学\\MyDBMS\\user1\\user1.txt";
//
//class tableinform {
//public:
//	vector<string> tablenames;
//	int count = 0;
//public:
//	void showtables()
//	{
//		updatetables();   //打印之前先跟新
//		cout << "当前表有：" << endl;
//		for (int i = 0; i < tablenames.size(); i++)
//		{
//			if (strcmp(tablenames[i].c_str(), ".") != 0 && strcmp(tablenames[i].c_str(), "..") != 0)
//			{
//				count++;
//				cout << tablenames[i] << endl;
//			}
//		}
//		if (count == 0) cout << "null" << endl;   //代表没有表
//	}
//	void updatetables()
//	{
//		this->tablenames.clear();
//		intptr_t Handle;
//		struct _finddata_t FileInfo;
//		string p;
//		string path = "C:\\Users\\27197\\Desktop\\山东师范大学\\MyDBMS\\user1";
//		if ((Handle = _findfirst(p.assign(path).append("\\*").c_str(), &FileInfo)) == -1)
//			printf("没有找到匹配的项目\n");
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
//class table {    //默认主码为第一个属性
//public:
//	string tablename;
//	vector<string> row;
//	vector<string> type;
//public:
//	table() { }
//	~table() {}
//	int Init(vector<string> p)   //初始化表
//	{
//		tablename = p[0];
//		for (int i = 1; i < p.size(); i++)
//		{
//			if (i % 2 == 0) type.push_back(p[i]);
//			else row.push_back(p[i]);
//		}
//		//创建表
//		string path = "C:\\Users\\27197\\Desktop\\山东师范大学\\MyDBMS\\user1\\" + tablename + ".txt";
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
//	void AddDatas()  //只能输入一个完整的元组
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
//		cout << "数据添加成功！" << endl;
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
//		cout << "输入你要删除信息的主码：";
//		cin >> output;
//		for (int i = 0; i < data.size(); i++)
//		{
//			if (strcmp(data[i].c_str(), output.c_str()) == 0)
//			{
//				//cout << "删除成功" << endl;
//				count = i;
//			}
//		}
//
//		//写入数据
//		fstream f;
//		f.open(path, ios::out);
//		int flag = 0;   //换行标志
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
//			cout << "删除成功！" << endl;
//		}
//		else
//			cout << "你要删除的信息不存在!" << endl;
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
//		cout << "你要查询什么信息?:";
//		string data;
//		cin >> data;
//		for (int i = 0; i < datas.size() - 1; i++)
//		{
//			if (strcmp(data.c_str(), datas[i].c_str()) == 0)
//			{
//				cout << "该数据为:" << endl;
//				for (int j = i; j < i + row.size(); j++)
//					cout << datas[j] << "\t";
//				cout << endl;
//				return;
//			}
//		}
//		cout << "该数据不存在！" << endl;
//		return;
//	}
//	void Changedata()
//	{
//		//读取表中的数据到datas
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
//		//修改datas
//		string data;
//		cout << "输入你要修改数据的主码：";
//		cin >> data;
//		int flag = 0;
//		for (int i = 0; i < datas.size()-1; i++)
//		{
//			if (strcmp(datas[i].c_str(), data.c_str()) == 0) //数据匹配
//			{
//				flag = 1;
//				cout << "该数据存在，请输入信息来替换它:" << endl;
//				for (int j = 0; j < row.size(); j++)
//				{
//					cin >> data;
//					datas[i + j] = data;	
//				}
//				cout << "替换成功！" << endl;
//				break;
//			}
//		}
//		if(flag == 0)
//			cout << "该数据不存在！" << endl;
//		//datas数据输入文件中
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
//	cout << "请输入你要创建的表名,数据属性名,数据类型：";     //help
//	cin >> push;
//	string path1 = push + ".txt";
//	for (int i = 0; i < TI.tablenames.size(); i++)
//		if (strcmp(path1.c_str(), TI.tablenames[i].c_str()) == 0)
//		{
//			cout << "该表已经存在！" << endl;
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
//	//当创建表时就把信息存储到user1.txt文件中
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
//	cout << p[0] + "表创建成功！" << endl;
//	return 1;
//}
//std::vector<std::string> stringSplit(const std::string& strIn, char delim) {     //分割字符串函数
//	char* str = const_cast<char*>(strIn.c_str());   //const_cast去除strIn的const限定
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
//std::vector<std::string> stringSplit(const std::string& strIn, char delim) {     //分割字符串函数
//	char* str = const_cast<char*>(strIn.c_str());   //const_cast去除strIn的const限定
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
	//实现完整性约束


	//当程序开始执行时就记录下当前DBMS的表名    -> 开始时就生成数据库中所有的表
	//TI.updatetables();
	//实现的命令
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
	////输入你想写入的内容 
	//f << "123323" << " " << "abs" << endl;
	//f.close();
	//生成一个user1的数据库
	
	/*cout << "这是一个小型的DBMS，可以创建database和table：请输入你要执行的指令：";
	string str;
	cin >> str;*/
	/*string str1 = "nihao\tniahd\tai\t";
	vector<string> test = stringSplit(str1, '\t');
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << endl;*/
	//time_t nowtime;
	//time(&nowtime); //获取1970年1月1日0点0分0秒到现在经过的秒数
	//tm* p = localtime(&nowtime); //将秒数转换为本地时间,年从1900算起,需要+1900,月为0-11,所以要+1
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
	//创建一模式
	Database DB1;
	DB1.Init();
	cout << "user1:";
	//test desctable
	DB1.descTable("test1");
    //词义分析 实现一些sql语句 标准为mysql
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
//		this->length = len; //不会再改变
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
//		this->length = len;//会改变
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
//class Student {  //Student表的定义
//public:
//	mychar number;   //山师标准 mychar(12)-固定
//	myvarchar name; //姓名 myvarchar(8)-可变
//	mychar sex; //性别 mychar(2)
//	date birthdata; //出生日期 date
//	myvarchar sdept; //所在系 myvarchar(20)
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
//class tablehead { //学生表的表头
//public:
//	Student* next = NULL;
//	string number = "学号";
//	string name = "姓名";
//	string sex = "性别";
//	string date = "出生日期";
//	string sdept = "所在部门";
//	int count = 0;
//public:
//	tablehead() {}
//	~tablehead() {}
//	void showdatas()   //显示表的所有数据项
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
//			cout << "请输入你要添加的数据项(学号,姓名,性别,出生日期,所在部门):";
//			cin >> num >> na >> se >> year >> month >> day >> sdep;
//			bd.setdate(year, month, day);
//			this->next = new Student(num, na, se, bd, sdep);
//		}
//		else
//		{ 
//			cout << "请输入你要添加的数据项(学号,姓名,性别,出生日期,所在部门):";
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
//		cout << "输入你要删除学生的学号:";
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
//		cout << "学号 姓名 性别 出生日期 所在部门" << endl;
//	}
//	void showdatatype()
//	{
//		cout << "学号:mychar(20)" << endl;
//		cout << "姓名:myvarchar(20)" << endl;
//		cout << "性别:myvarchar(10)" << endl;
//		cout << "出生日期:date" << endl;
//		cout << "所在部门:myvarchar(20)" << endl;
//
//	}
//};



















//int main()
//{
	////先定义一个表头,确定表的栏目
	//cout << "这是一个小型的DBMS，目前只实现了学生表的相关功能" << endl;
	//cout << "1.为表添加数据项" << endl;
	//cout << "2.删除表中的数据项" << endl;
	//cout << "3.显示表的字段名" << endl;
	//cout << "4.显示表的字段类型" << endl;
	//cout << "5.显示当前表存储的所有数据" << endl;
	//cout << "请输入你想运行的功能(输入0退出该系统):";
	//int a = 0;
	//cin >> a;
	//if (0 == a) {
	//	cout << "成功退出该系统！" << endl;
	//	exit(0);
	//}
	//tablehead* head = new tablehead();
	//while (a)
	//{
	//	switch (a)
	//	{
	//	case 1:
	//		head->adddata();
	//		cout << "添加数据项成功!" << endl;
	//		break;
	//	case 2:
	//		head->dropdata();
	//		cout << "删除数据项成功!" << endl;
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
	//	cout << "1.为表添加数据项" << endl;
	//	cout << "2.删除表中的数据项" << endl;
	//	cout << "3.显示表的字段名" << endl;
	//	cout << "4.显示表的字段类型" << endl;
	//	cout << "5.显示当前表存储的所有数据" << endl;
	//	cout << "请输入你想运行的功能(输入0退出该系统):";
	//	cin >> a;
	//}
	//cout << "成功退出该系统！" << endl;
	//一个表就是一个txt文件


	//return 0;
//}