#include "stdafx.h"
#include "Faculty.h"






CFaculty::CFaculty(string n1, char s, string n2, string n3, string n4, int L, double BW, int P):CPersonnel(n1, s, n2)
{
	dBasicwage = BW;
	sDepartment = n3;
	sNum = n4;
	nLevel = L;
	nPosition = P;
}

void CFaculty::setBasicWage(double BW)
{
	dBasicwage = BW;
}

CFaculty::~CFaculty()
{
}

void CFaculty::setNum(string n4)
{
	sNum = n4;
}

void CFaculty::setDepartment(string n3)
{
	sDepartment = n3;
}

void CFaculty::setLevel(int L)
{
	nLevel = L;
}

string CFaculty::getNum()
{
	return sNum;
}


string CFaculty::getDepartment()
{
	return sDepartment;
}

int CFaculty::getClassHours()
{
	return nClassHours;
}

double CFaculty::getBasicwage()
{
	return dBasicwage;
}

double CFaculty::getClassSubsidies()
{
	return dClassSubsidies;
}

double CFaculty::getAdminiSubsidies()
{
	return dAdminiSubsidies;
}

int CFaculty::getLevel()
{
	return nLevel;
}

int CFaculty::getPosition()
{
	return nPosition;
}

void CFaculty::print()
{
	/*cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�";
	cout << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;*/
	cout << setw(12)<<getDepartment() << setw(12) << getNum() << setw(9) << getName();
	if (getSex() == 'f' || getSex() == 'F')
		cout << setw(9) << "��";
	else
		cout << setw(9) << "Ů";
	cout << setw(15) << getBirthday() << setw(9) << getLevel() << setw(9) << getWage() << endl;
}
