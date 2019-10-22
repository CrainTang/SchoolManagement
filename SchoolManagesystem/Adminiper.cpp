#include "stdafx.h"
#include "Adminiper.h"



CAdminiper::CAdminiper(string n1, char s, string n2, string n3, string n4, int L, double BW,double AS,int P):CFaculty(n1, s, n2, n3, n4, L,BW,P)
{
	dAdminiSubsidies = AS;
}

double CAdminiper::getWage()
{
	return dBasicwage + dAdminiSubsidies;
}

void CAdminiper::setClassHours()
{
	cout << "对不起，当前选项不可选！请重新选择："<< endl;
}

void CAdminiper::setClassSubsidies()
{
	cout << "对不起，当前选项不可选！请重新选择：" << endl;
}

void CAdminiper::setAdminiSubsidies()
{
	cout << "***********************请输入新的行政补贴******************:" << endl;
	cin >> dAdminiSubsidies;
	cout << "修改成功！" << endl;
}
CAdminiper::~CAdminiper()
{
}