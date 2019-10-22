#pragma once
#include "Personnel.h"
class CFaculty :
	public CPersonnel
{
public:
	CFaculty(string n1 ,char s,string n2,string n3,string n4,int L,double BW, int P);
	virtual double getWage() = 0;						//纯虚函数，计算工资
	virtual void setClassHours() = 0;					//纯虚函数，设置课时
	virtual void setClassSubsidies() = 0;				//纯虚函数，设置课时补贴
	virtual void setAdminiSubsidies() = 0;				//纯虚函数，设置行政补贴
	void setBasicWage(double BW);			//设置基本工资
	void setNum(string n4);								//设置姓名
	void setDepartment(string n3);						//设置部门
	void setLevel(int L);								//设置等级
	string getNum();									//获取工号
	string getDepartment();								//获取部门
	int getClassHours();								//获取课时
	double getBasicwage();								//获取基本工资
	double getClassSubsidies();							//获取课时补贴
	double getAdminiSubsidies();						//获取行政补贴
	int getLevel();										//获取级别
	int getPosition();									//获取岗位
	void print();										//打印信息
	~CFaculty();
private:
	string sDepartment;									//部门
	string sNum;										//工号
	int nLevel;											//等级
protected:
	double dBasicwage;									//基本工资
	int nPosition;										//岗位
	int nClassHours;									//课时
	double dClassSubsidies;								//课时补贴
	double dAdminiSubsidies;							//行政补贴
};

