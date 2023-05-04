#pragma once

#include"table.h"
class Database
{
public:
    string DBname = "user1"; //该数据库的名
    vector<table> tables;  //用来存储该数据库的所有表
public:
    Database();
    void Init();//
    void printTables();    //show tables
    int creatTable();      // create tables
    void descTable(string tablename);  //desc tablename
};

