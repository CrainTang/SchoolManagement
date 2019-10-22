#pragma once
#include "Personnel.h"
class CFaculty :
	public CPersonnel
{
public:
	CFaculty(string n1 ,char s,string n2,string n3,string n4,int L,double BW, int P);
	virtual double getWage() = 0;						//���麯�������㹤��
	virtual void setClassHours() = 0;					//���麯�������ÿ�ʱ
	virtual void setClassSubsidies() = 0;				//���麯�������ÿ�ʱ����
	virtual void setAdminiSubsidies() = 0;				//���麯����������������
	void setBasicWage(double BW);			//���û�������
	void setNum(string n4);								//��������
	void setDepartment(string n3);						//���ò���
	void setLevel(int L);								//���õȼ�
	string getNum();									//��ȡ����
	string getDepartment();								//��ȡ����
	int getClassHours();								//��ȡ��ʱ
	double getBasicwage();								//��ȡ��������
	double getClassSubsidies();							//��ȡ��ʱ����
	double getAdminiSubsidies();						//��ȡ��������
	int getLevel();										//��ȡ����
	int getPosition();									//��ȡ��λ
	void print();										//��ӡ��Ϣ
	~CFaculty();
private:
	string sDepartment;									//����
	string sNum;										//����
	int nLevel;											//�ȼ�
protected:
	double dBasicwage;									//��������
	int nPosition;										//��λ
	int nClassHours;									//��ʱ
	double dClassSubsidies;								//��ʱ����
	double dAdminiSubsidies;							//��������
};

