#pragma once
#include "Faculty.h"
class CTeacher :
	virtual public CFaculty
{
public:
	CTeacher(string n1, char s, string n2, string n3, string n4, int L,int CH ,double BW,double CS,int P);
	double getWage();						//���㹤��
	void setClassHours();
	void setClassSubsidies();
	void setAdminiSubsidies();
	~CTeacher();
};

