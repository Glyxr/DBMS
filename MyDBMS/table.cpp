#include "table.h"
#include "Date.h"
std::vector<std::string> table::stringSplit(const std::string& strIn, char delim) {     //�ָ��ַ�������
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
int table::cmpDate(string input)  //2023-10-1
{
    //�ж��Ƿ���ϸ�ʽ��׼ Y-M-D 
    if (input.size() != 10) return -1;
    vector<string> str_date;
    int d[3] = { 0 };
    str_date.push_back(input.substr(4, 1));
    str_date.push_back(input.substr(7, 1));
    d[0] = atoi(input.substr(0, 4).c_str());
    d[1] = atoi(input.substr(5, 2).c_str());
    d[2] = atoi(input.substr(8, 2).c_str());
    if (strcmp(str_date[0].c_str(), "-") != 0 && strcmp(str_date[1].c_str(), "-") != 0) return -1;
    //�ж��Ƿ�Ϊ��������(��ǰʱ���ȥ100-��ǰʱ��)
    //��ȡ��ǰʱ��
    time_t nowtime;
    time(&nowtime); //��ȡ1970��1��1��0��0��0�뵽���ھ���������
    tm* p = localtime(&nowtime); //������ת��Ϊ����ʱ��,���1900����,��Ҫ+1900,��Ϊ0-11,����Ҫ+1
    //printf("%04d:%02d:%02d\n", p->tm_year + 1900, p->tm_mon + 1, p->tm_mday);
   
    date d1(d);
   // cout << d1.getMaxday() << endl;
    if (d[0] < p->tm_year + 1800 || d[0] > p->tm_year + 1900 || d[1] < 1 || d[1] > 12 || d[2] > d1.getMaxday() || d[2] < 1)
        return -1;
    return 1;
}
int table::cmpchar(string input)//input = char(num)
{
    //�õ�num
    string input_sub = input.substr(5, 100);
    vector<string> str_num = stringSplit(input_sub, ')');
    return atoi(str_num[0].c_str());
}
int table::cmpvarchar(string input)//input = varchar(num)
{
    //�õ�num
    string input_sub = input.substr(8, 100);
    vector<string> str_num = stringSplit(input_sub, ')');
    return atoi(str_num[0].c_str());
}