#pragma once
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;
class CStudentGrade
{
public:
	CStudentGrade(string n1,int S,int R);
	~CStudentGrade();
	int print();
	string getCourse();
	void setScore(int S);
	void setCredit(int C);
	int getScore();
	int getCredit();
private:
	string sCourse;			//�γ�����
	int nScore;				//����
	int nCredit;			//ѧ��
};

