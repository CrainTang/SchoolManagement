#include "stdafx.h"
#include "Teacher.h"



CTeacher::CTeacher(string n1, char s, string n2, string n3, string n4, int L, int CH, double BW,double CS,int P):CFaculty( n1,s,n2,n3,n4,L,BW,P)
{
	nClassHours = CH;
	dClassSubsidies = CS;
	nPosition = P;
}

double CTeacher::getWage()
{
	return dBasicwage + nClassHours * dClassSubsidies;
}

void CTeacher::setClassHours()
{
	cout << "*************************请输入新的课时********************:" << endl;
	cin >> nClassHours;
	cout << "修改成功！" << endl;
}

void CTeacher::setClassSubsidies()
{
	cout << "***********************请输入新的课时补贴******************:" << endl;
	cin >> dClassSubsidies;
	cout << "修改成功！" << endl;
}

void CTeacher::setAdminiSubsidies()
{
	cout << "对不起，当前选项不可选！请重新选择：" << endl;
}






CTeacher::~CTeacher()
{
}
