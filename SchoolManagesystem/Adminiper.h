#pragma once
#include "Faculty.h"
class CAdminiper :
	virtual public CFaculty
{
public:
	CAdminiper(string n1, char s, string n2, string n3, string n4, int L, double BW, double AS,int P);  //构造函数
	~CAdminiper();
	double getWage();							//计算工资
	void setClassHours();						//设置课时
	void setClassSubsidies();					//设置课时补贴
	void setAdminiSubsidies();					//设置行政补贴
};

