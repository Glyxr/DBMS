#include "Database.h"
string DBpath = "C:\\Users\\27197\\Desktop\\ɽ��ʦ����ѧ\\MyDBMS\\user1\\user1.txt";

std::vector<std::string> stringSplit(const std::string& strIn, char delim) {     //�ָ��ַ�������
    char* str = const_cast<char*>(strIn.c_str());   //const_castȥ��strIn��const�޶�
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
	//��ȡuser1.txt�ļ������ɱ�
  
    //cout << "1";
    vector<string> lines;   //������ʼtable
    string line;
    ifstream input_file(DBpath);
    
   while (getline(input_file, line)) {    //����user�е����б�����tables��
       lines = stringSplit(line, '\t');   //�ָ��ַ���
       table push;  
       push.Init(lines);
       tables.push_back(push);
    }
    /*for (int i = 0; i < lines.size(); i++)
        cout << lines[i] << endl;*/
    //�ر��ļ�
    input_file.close();
}

void Database::printTables()
{
    cout << "��ģʽ�µı��У�" << endl;
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
	cout << "��������Ҫ�����ı���,����������,�������ͣ�";     //help
	cin >> push;
	string path1 = push + ".txt";
	for (int i = 0; i < tables.size(); i++)
		if (strcmp(path1.c_str(), tables[i].tablename.c_str()) == 0)
		{
			cout << "�ñ��Ѿ����ڣ�" << endl;
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
	//��������ʱ�Ͱ���Ϣ�洢��user1.txt�ļ���
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
	cout << p[0] + "�����ɹ���" << endl;
	this->tables.push_back(tab);
	return 1;
}
Database::Database()
{
	
}

void Database::descTable(string tablename)
{
	//ȷ��Ҫʹ�õ�table
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
