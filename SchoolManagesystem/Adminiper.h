#pragma once
#include "Faculty.h"
class CAdminiper :
	virtual public CFaculty
{
public:
	CAdminiper(string n1, char s, string n2, string n3, string n4, int L, double BW, double AS,int P);  //���캯��
	~CAdminiper();
	double getWage();							//���㹤��
	void setClassHours();						//���ÿ�ʱ
	void setClassSubsidies();					//���ÿ�ʱ����
	void setAdminiSubsidies();					//������������
};

