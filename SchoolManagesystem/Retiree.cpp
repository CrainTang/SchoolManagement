#include "stdafx.h"
#include "Retiree.h"





CRetiree::CRetiree(string n1, char s, string n2, string n3, string n4, int L,double BW,int P):CFaculty(n1, s, n2, n3, n4, L,BW,P)
{
}

double CRetiree::getWage()
{
	return dBasicwage;
}

void CRetiree::setClassHours()
{
	cout << "�Բ��𣬵�ǰѡ���ѡ��������ѡ��" << endl;
}

void CRetiree::setClassSubsidies()
{
	cout << "�Բ��𣬵�ǰѡ���ѡ��������ѡ��" << endl;
}

void CRetiree::setAdminiSubsidies()
{
	cout << "�Բ��𣬵�ǰѡ���ѡ��������ѡ��" << endl;
}
CRetiree::~CRetiree()
{
}