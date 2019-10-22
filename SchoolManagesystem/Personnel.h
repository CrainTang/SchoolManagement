#pragma once
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
class CPersonnel
{
public:
	CPersonnel(string n1,char s,string n2);    //构造函数
	void setName(string n1);					//设置姓名
	void setSex(char s);						//设置性别
	void setBirthday(string n2);				//设置出生日期
	char getSex();								//获取性别
	string getBirthday();						//获取出生日期
	string getName();							//获取姓名
	~CPersonnel();								//析构函数
	
protected:
	string sName;								//姓名
	char cSex;									//性别
	string sBirthday;							//出生日期
};

