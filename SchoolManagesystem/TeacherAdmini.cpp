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
	cout << "*************************�������µĿ�ʱ********************:" << endl;
	cin >> nClassHours;
	cout << "�޸ĳɹ���" << endl;
}

void CTeacherAdmini::setClassSubsidies()
{
	cout << "***********************�������µĿ�ʱ����******************:" << endl;
	cin >> dClassSubsidies;
	cout << "�޸ĳɹ���" << endl;
}

void CTeacherAdmini::setAdminiSubsidies()
{
	cout << "***********************�������µ���������******************:" << endl;
	cin >> dAdminiSubsidies;
	cout << "�޸ĳɹ���" << endl;
}


CTeacherAdmini::~CTeacherAdmini()
{
}
