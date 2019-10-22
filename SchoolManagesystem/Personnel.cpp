#include "stdafx.h"
#include "Personnel.h"


CPersonnel::CPersonnel(string n1,char s, string n2)
{
	sName = n1;
	cSex = s;
	sBirthday = n2;
}

void CPersonnel::setName(string s)
{
	sName = s;
}

void CPersonnel::setSex(char s)
{
	cSex = s;
}

void CPersonnel::setBirthday(string n2)
{
	sBirthday = n2;
}

char CPersonnel::getSex()
{
	return cSex;
}

string CPersonnel::getBirthday()
{
	return sBirthday;
}

string CPersonnel::getName()
{
	return sName;
}


CPersonnel::~CPersonnel()
{
}


