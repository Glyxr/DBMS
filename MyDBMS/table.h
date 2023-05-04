#ifndef _TABLE_H_
#define _TABLE_H_
#include<map>
#include<iostream>
using namespace std;
#include<sstream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<io.h>
class table {    //默认主码为第一个属性
public:
	string tablename;
	vector<string> row;
	vector<string> type;
	string PATH = "C:\\Users\\27197\\Desktop\\山东师范大学\\MyDBMS\\user1\\";
public:
	table() { }
	~table() {}
	std::vector<std::string> stringSplit(const std::string& strIn, char delim);
	int cmpDate(string input);  //查看date类型是否输入规范（ - - ），不返回-1，1
	int cmpchar(string input); //返回char的长度
	int cmpvarchar(string input); //返回varchar的长度
	int Init(vector<string> p)   //初始化表
	{
		tablename = p[0];
		for (int i = 1; i < p.size(); i++)
		{
			if (i % 2 == 0) type.push_back(p[i]);
			else row.push_back(p[i]);
		}
		//创建表 txt 文件
		string path = "C:\\Users\\27197\\Desktop\\山东师范大学\\MyDBMS\\user1\\" + tablename + ".txt";
		ofstream MyFile;
		MyFile.open(path, ios::app | ios::out);     //没有文件就创建
		MyFile.close();
		//for (int i = 0; i < row.size(); i++)
		//	MyFile << row[i] + "      ";
		return 0;
	}
	void ShowRows()
	{
		for (int i = 0; i < row.size(); i++)
		{
			cout << row[i] + "\t";
		}
		cout << endl;
	}
	void AddDatas()  //只能输入一个完整的元组
	{
		int flag = -1;
		string path = PATH + tablename + ".txt";
		string str;
		vector<string> input;
		for (int i = 0; i < row.size(); i++)
		{
			cin >> str;
			input.push_back(str);
		}
		for (int i = 0; i < row.size(); i++)   //完整性约束(对数据类型)
		{
			//cout << strcmp(row[i].c_str(), "date") << endl;
			if ( strcmp(type[i].c_str(), "date") == 0 && cmpDate(input[i]) == -1 )  //date类型输入不标准
			{
				cout << "你输入的date类型不规范（yyyy-mm-dd），该数据并没有被录入！" << endl;
				flag = 0;
			}
			if (strcmp(type[i].substr(0,4).c_str(), "char") == 0 && input[i].length() > cmpchar(type[i]))  //char 类型输入不标准
			{
				cout << cmpchar(type[i]) << endl;
				cout << "你输入的" << input[i];
				cout << "，超出预定义的大小范围(";
				cout << type[i] << "),该数据没有被录入!" << endl;
				flag = 0;
			}
			if (strcmp(type[i].substr(0, 7).c_str(), "varchar") == 0 && input[i].length() > cmpchar(type[i]))  //char 类型输入不标准
			{
				cout << cmpchar(type[i]) << endl;
				cout << "你输入的" << input[i];
				cout << "，超出预定义的大小范围(";
				cout << type[i] << "),该数据没有被录入!" << endl;
				flag = 0;
			}
			
		}
		if (flag == 0) return;
		fstream fp;
		fp.open(path, ios::app | ios::out);
		for (int i = 0; i < row.size(); i++)
		{
			fp << input[i] << "\t";
		}
		fp << endl;
		fp.close();
		cout << "数据添加成功！" << endl;
	}
	void DeleteData()
	{
		string path = PATH + tablename + ".txt";
		ifstream fp(path);
		vector<string> data;
		string output;
		int count = -1;
		while (fp) {
			fp >> output;
			data.push_back(output);
			cout << output << endl;
		}
		fp.close();
		cout << "输入你要删除信息的主码：";
		cin >> output;
		for (int i = 0; i < data.size(); i++)
		{
			if (strcmp(data[i].c_str(), output.c_str()) == 0)
			{
				//cout << "删除成功" << endl;
				count = i;
			}
		}

		//写入数据
		fstream f;
		f.open(path, ios::out);
		int flag = 0;   //换行标志
		if (count != -1)
		{
			for (int i = 0; i < data.size() - 1; i++)
			{
				if (i >= count && i <= count + row.size() - 1)
					continue;
				flag++;
				f << data[i] << "\t";
				if (flag % row.size() == 0)
					f << "\n";
			}
			f.close();
			cout << "删除成功！" << endl;
		}
		else
			cout << "你要删除的信息不存在!" << endl;
	}
	void SearchData()
	{
		string path = PATH + tablename + ".txt";
		ifstream fp(path);
		vector<string> datas;
		string output;
		int count = -1;
		while (fp) {
			fp >> output;
			datas.push_back(output);
			cout << output << endl;
		}
		fp.close();
		cout << "你要查询什么信息?:";
		string data;
		cin >> data;
		for (int i = 0; i < datas.size() - 1; i++)
		{
			if (strcmp(data.c_str(), datas[i].c_str()) == 0)
			{
				cout << "该数据为:" << endl;
				for (int j = i; j < i + row.size(); j++)
					cout << datas[j] << "\t";
				cout << endl;
				return;
			}
		}
		cout << "该数据不存在！" << endl;
		return;
	}
	void Changedata()
	{
		//读取表中的数据到datas
		string path = PATH + tablename + ".txt";
		ifstream fp(path);
		vector<string> datas;
		string output;
		int count = -1;
		while (fp) {
			fp >> output;
			datas.push_back(output);
			cout << output << endl;
		}
		fp.close();
		//修改datas
		string data;
		cout << "输入你要修改数据的主码：";
		cin >> data;
		int flag = 0;
		for (int i = 0; i < datas.size() - 1; i++)
		{
			if (strcmp(datas[i].c_str(), data.c_str()) == 0) //数据匹配
			{
				flag = 1;
				cout << "该数据存在，请输入信息来替换它:" << endl;
				for (int j = 0; j < row.size(); j++)
				{
					cin >> data;
					datas[i + j] = data;
				}
				cout << "替换成功！" << endl;
				break;
			}
		}
		if (flag == 0)
			cout << "该数据不存在！" << endl;
		//datas数据输入文件中
		fstream f;
		f.open(path, ios::out);
		for (int i = 0; i < datas.size() - 1; i++)
		{
			f << datas[i] << "\t";
			if ((i + 1) % row.size() == 0)
				f << endl;
		}
		f.close();
	}
	void addField(string fldname, int type) 
	{

	}
	void add(string fldname, table tab) //添加在tab中的名为fldname的field
	{

	}
	void addAllField(table tab) //复制添加其他table的field
	{

	}
	vector<string> fields() {  //返回所有的field
		return this->row;
	}
	bool hasField(string fldname)
	{
		for (int i = 0; i < row.size(); i++)
		{
			if (strcmp(fldname.c_str(), row[i].c_str()) == 0)
				return true;
		}
		return false;
	}
	string type(string fldname)
	{
		int count = 0;
		for (int i = 0; i < row.size(); i++)
		{
			if (strcmp(fldname.c_str(), row[i].c_str()) == 0)
				count = i;
		}
		return type[count];
	}

};

#endif;