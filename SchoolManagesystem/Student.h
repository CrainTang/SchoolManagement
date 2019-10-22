#pragma once
#include "Personnel.h"
#include"iostream"
#include"fstream"
#include"StudentGrade.h"
class CStudent :
	public CPersonnel
{
public:
	CStudent(string n1,string n2,string n3,char s,string n4);//�༶��ѧ�š��������Ա𡢳�������
	~CStudent();
	void entergrade(string n1, int S,int C);
	void setgrade(string C,int S,int R);
	void deletegrade(string C);
	void printinf();
	void printgrade();
	void setNum(string n2);
	void setClass(string n1);
	string getpercourse(int j);
	int getperscore(int j);
	int getpercredit(int j);
	string getNum();
	string getClass();
	double getTotalscore();
	char getEduLevel();
	int Valid_Course(string C);
	int getCoursecount();
	int getRank();
	void setRank(int i);
protected:
	string sClass;				//�༶
	string sNum;				//ѧ��
	char cEduLevle;				//�������
	CStudentGrade **SG;			//�ɼ�ָ������
	int nCoursecount;			//�γ�����
	double dTotalscore;			//�ܳɼ�
	double dTotalcredit;		//��ѧ��
	int nRank;					//�༶����
};

