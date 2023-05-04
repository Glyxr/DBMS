#include "Database.h"
string DBpath = "C:\\Users\\27197\\Desktop\\山东师范大学\\MyDBMS\\user1\\user1.txt";

std::vector<std::string> stringSplit(const std::string& strIn, char delim) {     //分割字符串函数
    char* str = const_cast<char*>(strIn.c_str());   //const_cast去除strIn的const限定
    std::string s;
    s.append(1, delim);
    std::vector<std::string> elems;
    char* splitted = strtok(str, s.c_str());
    while (splitted != NULL) {
        elems.push_back(std::string(splitted));
        splitted = strtok(NULL, s.c_str());
    }
    return elems;
}

void Database::Init()
{
	//读取user1.txt文件，生成表
  
    //cout << "1";
    vector<string> lines;   //用来初始table
    string line;
    ifstream input_file(DBpath);
    
   while (getline(input_file, line)) {    //生成user中的所有表，存在tables中
       lines = stringSplit(line, '\t');   //分割字符串
       table push;  
       push.Init(lines);
       tables.push_back(push);
    }
    /*for (int i = 0; i < lines.size(); i++)
        cout << lines[i] << endl;*/
    //关闭文件
    input_file.close();
}

void Database::printTables()
{
    cout << "该模式下的表有：" << endl;
    for (int i = 0; i < this->tables.size(); i++)
    {
        cout << tables[i].tablename << endl;
    }
}
int Database::creatTable()
{
	table tab;
	vector<string> p;
	string push;
	cout << "请输入你要创建的表名,数据属性名,数据类型：";     //help
	cin >> push;
	string path1 = push + ".txt";
	for (int i = 0; i < tables.size(); i++)
		if (strcmp(path1.c_str(), tables[i].tablename.c_str()) == 0)
		{
			cout << "该表已经存在！" << endl;
			return 2;
		}
	p.push_back(push);
	while (cin >> push && strcmp(push.c_str(), "#") != 0)
	{
		if (strcmp(push.c_str(), "{") != 0 && strcmp(push.c_str(), "}") != 0)
			p.push_back(push);
	}
	//cout << p.size();
	/*for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << endl;
	}*/
	//当创建表时就把信息存储到user1.txt文件中
	ofstream f;
	f.open(DBpath, ios::app | ios::out);
	/*f << endl;*/
	for (int i = 0; i < p.size(); i++)
	{
		f << p[i] << "\t";
	}
	f << endl;
	f.close();
	tab.Init(p);
	cout << p[0] + "表创建成功！" << endl;
	this->tables.push_back(tab);
	return 1;
}
Database::Database()
{
	
}

void Database::descTable(string tablename)
{
	//确定要使用的table
	int count = -1;
	cout << endl;
	for (int i = 0; i < tables.size(); i++)
	{
		if (strcmp(this->tables[i].tablename.c_str(), tablename.c_str()) == 0)
		{
			count = i;
			break;
		}
	}
	cout << "Field\t\t" << "Type" << endl;
	for (int i = 0; i < tables[count].row.size(); i++)
	{
		cout << tables[count].row[i] << "\t\t" << tables[count].type[i] << endl;
	}
}
