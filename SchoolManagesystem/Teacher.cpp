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
	cout << "*************************�������µĿ�ʱ********************:" << endl;
	cin >> nClassHours;
	cout << "�޸ĳɹ���" << endl;
}

void CTeacher::setClassSubsidies()
{
	cout << "***********************�������µĿ�ʱ����******************:" << endl;
	cin >> dClassSubsidies;
	cout << "�޸ĳɹ���" << endl;
}

void CTeacher::setAdminiSubsidies()
{
	cout << "�Բ��𣬵�ǰѡ���ѡ��������ѡ��" << endl;
}






CTeacher::~CTeacher()
{
}
