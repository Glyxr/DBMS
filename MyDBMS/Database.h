#pragma once

#include"table.h"
class Database
{
public:
    string DBname = "user1"; //�����ݿ����
    vector<table> tables;  //�����洢�����ݿ�����б�
public:
    Database();
    void Init();//
    void printTables();    //show tables
    int creatTable();      // create tables
    void descTable(string tablename);  //desc tablename
};

