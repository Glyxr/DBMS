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
class table {    //Ĭ������Ϊ��һ������
public:
	string tablename;
	vector<string> row;
	vector<string> type;
	string PATH = "C:\\Users\\27197\\Desktop\\ɽ��ʦ����ѧ\\MyDBMS\\user1\\";
public:
	table() { }
	~table() {}
	std::vector<std::string> stringSplit(const std::string& strIn, char delim);
	int cmpDate(string input);  //�鿴date�����Ƿ�����淶�� - - ����������-1��1
	int cmpchar(string input); //����char�ĳ���
	int cmpvarchar(string input); //����varchar�ĳ���
	int Init(vector<string> p)   //��ʼ����
	{
		tablename = p[0];
		for (int i = 1; i < p.size(); i++)
		{
			if (i % 2 == 0) type.push_back(p[i]);
			else row.push_back(p[i]);
		}
		//������ txt �ļ�
		string path = "C:\\Users\\27197\\Desktop\\ɽ��ʦ����ѧ\\MyDBMS\\user1\\" + tablename + ".txt";
		ofstream MyFile;
		MyFile.open(path, ios::app | ios::out);     //û���ļ��ʹ���
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
	void AddDatas()  //ֻ������һ��������Ԫ��
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
		for (int i = 0; i < row.size(); i++)   //������Լ��(����������)
		{
			//cout << strcmp(row[i].c_str(), "date") << endl;
			if ( strcmp(type[i].c_str(), "date") == 0 && cmpDate(input[i]) == -1 )  //date�������벻��׼
			{
				cout << "�������date���Ͳ��淶��yyyy-mm-dd���������ݲ�û�б�¼�룡" << endl;
				flag = 0;
			}
			if (strcmp(type[i].substr(0,4).c_str(), "char") == 0 && input[i].length() > cmpchar(type[i]))  //char �������벻��׼
			{
				cout << cmpchar(type[i]) << endl;
				cout << "�������" << input[i];
				cout << "������Ԥ����Ĵ�С��Χ(";
				cout << type[i] << "),������û�б�¼��!" << endl;
				flag = 0;
			}
			if (strcmp(type[i].substr(0, 7).c_str(), "varchar") == 0 && input[i].length() > cmpchar(type[i]))  //char �������벻��׼
			{
				cout << cmpchar(type[i]) << endl;
				cout << "�������" << input[i];
				cout << "������Ԥ����Ĵ�С��Χ(";
				cout << type[i] << "),������û�б�¼��!" << endl;
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
		cout << "������ӳɹ���" << endl;
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
		cout << "������Ҫɾ����Ϣ�����룺";
		cin >> output;
		for (int i = 0; i < data.size(); i++)
		{
			if (strcmp(data[i].c_str(), output.c_str()) == 0)
			{
				//cout << "ɾ���ɹ�" << endl;
				count = i;
			}
		}

		//д������
		fstream f;
		f.open(path, ios::out);
		int flag = 0;   //���б�־
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
			cout << "ɾ���ɹ���" << endl;
		}
		else
			cout << "��Ҫɾ������Ϣ������!" << endl;
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
		cout << "��Ҫ��ѯʲô��Ϣ?:";
		string data;
		cin >> data;
		for (int i = 0; i < datas.size() - 1; i++)
		{
			if (strcmp(data.c_str(), datas[i].c_str()) == 0)
			{
				cout << "������Ϊ:" << endl;
				for (int j = i; j < i + row.size(); j++)
					cout << datas[j] << "\t";
				cout << endl;
				return;
			}
		}
		cout << "�����ݲ����ڣ�" << endl;
		return;
	}
	void Changedata()
	{
		//��ȡ���е����ݵ�datas
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
		//�޸�datas
		string data;
		cout << "������Ҫ�޸����ݵ����룺";
		cin >> data;
		int flag = 0;
		for (int i = 0; i < datas.size() - 1; i++)
		{
			if (strcmp(datas[i].c_str(), data.c_str()) == 0) //����ƥ��
			{
				flag = 1;
				cout << "�����ݴ��ڣ���������Ϣ���滻��:" << endl;
				for (int j = 0; j < row.size(); j++)
				{
					cin >> data;
					datas[i + j] = data;
				}
				cout << "�滻�ɹ���" << endl;
				break;
			}
		}
		if (flag == 0)
			cout << "�����ݲ����ڣ�" << endl;
		//datas���������ļ���
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
	void add(string fldname, table tab) //�����tab�е���Ϊfldname��field
	{

	}
	void addAllField(table tab) //�����������table��field
	{

	}
	vector<string> fields() {  //�������е�field
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