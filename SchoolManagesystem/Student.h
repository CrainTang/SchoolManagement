#pragma once
#include "Personnel.h"
#include"iostream"
#include"fstream"
#include"StudentGrade.h"
class CStudent :
	public CPersonnel
{
public:
	CStudent(string n1,string n2,string n3,char s,string n4);//班级、学号、姓名、性别、出生日期
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
	string sClass;				//班级
	string sNum;				//学号
	char cEduLevle;				//教育层次
	CStudentGrade **SG;			//成绩指针数组
	int nCoursecount;			//课程总数
	double dTotalscore;			//总成绩
	double dTotalcredit;		//总学分
	int nRank;					//班级排名
};

