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
	cout << "�Բ��𣬵�ǰѡ���ѡ��������ѡ��"<< endl;
}

void CAdminiper::setClassSubsidies()
{
	cout << "�Բ��𣬵�ǰѡ���ѡ��������ѡ��" << endl;
}

void CAdminiper::setAdminiSubsidies()
{
	cout << "***********************�������µ���������******************:" << endl;
	cin >> dAdminiSubsidies;
	cout << "�޸ĳɹ���" << endl;
}
CAdminiper::~CAdminiper()
{
}