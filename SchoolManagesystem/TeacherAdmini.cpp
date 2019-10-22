#include "stdafx.h"
#include "TeacherAdmini.h"


CTeacherAdmini::CTeacherAdmini(string n1, char s, string n2, string n3, string n4, int L, int CH, double BW, double CS, double AS,int P):CFaculty(n1,s,n2,n3,n4,L,BW,P),CTeacher(n1, s, n2, n3, n4, L,CH, BW, CS,P),CAdminiper(n1, s, n2, n3, n4, L, BW,AS,P)
{
	nPosition = P;
}

double CTeacherAdmini::getWage()
{
	return dBasicwage + nClassHours * dClassSubsidies + dAdminiSubsidies;
}

void CTeacherAdmini::setClassHours()
{
	cout << "*************************请输入新的课时********************:" << endl;
	cin >> nClassHours;
	cout << "修改成功！" << endl;
}

void CTeacherAdmini::setClassSubsidies()
{
	cout << "***********************请输入新的课时补贴******************:" << endl;
	cin >> dClassSubsidies;
	cout << "修改成功！" << endl;
}

void CTeacherAdmini::setAdminiSubsidies()
{
	cout << "***********************请输入新的行政补贴******************:" << endl;
	cin >> dAdminiSubsidies;
	cout << "修改成功！" << endl;
}


CTeacherAdmini::~CTeacherAdmini()
{
}
