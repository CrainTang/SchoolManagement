#pragma once
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
class CPersonnel
{
public:
	CPersonnel(string n1,char s,string n2);    //���캯��
	void setName(string n1);					//��������
	void setSex(char s);						//�����Ա�
	void setBirthday(string n2);				//���ó�������
	char getSex();								//��ȡ�Ա�
	string getBirthday();						//��ȡ��������
	string getName();							//��ȡ����
	~CPersonnel();								//��������
	
protected:
	string sName;								//����
	char cSex;									//�Ա�
	string sBirthday;							//��������
};

