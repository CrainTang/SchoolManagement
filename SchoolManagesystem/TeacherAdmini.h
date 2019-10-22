#pragma once
#include "Teacher.h"
#include "Adminiper.h"
class CTeacherAdmini :
	public CTeacher ,public CAdminiper
{
public:
	CTeacherAdmini(string n1, char s, string n2, string n3, string n4, int L, int CH, double BW, double CS, double AS,int P);
	double getWage();
	void setClassHours();
	void setClassSubsidies();
	void setAdminiSubsidies();
	~CTeacherAdmini();
};

