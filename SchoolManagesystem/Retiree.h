#pragma once
#include "Faculty.h"
class CRetiree :
	public CFaculty
{
public:
	CRetiree(string n1, char s, string n2, string n3, string n4, int L,double BW,int P);
	~CRetiree();
	double getWage();
	void setClassHours();
	void setClassSubsidies();
	void setAdminiSubsidies();
};

