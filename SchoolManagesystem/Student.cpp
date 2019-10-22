#include "stdafx.h"
#include "Student.h"


CStudent::CStudent(string n1, string n2, string n3, char s, string n4):CPersonnel(n3,s,n4)
{
	sClass = n1;
	sNum = n2;
	nCoursecount = 0;
	SG = new CStudentGrade *[20];
}


CStudent::~CStudent()
{
	int i;
	for (i = 0; i<nCoursecount; i++)
		delete SG[i];
	delete[] SG;
}

void CStudent::entergrade(string n1,int S,int C)
{
		SG[nCoursecount] = new CStudentGrade(n1,S,C);
		nCoursecount++;
}

void CStudent::setgrade(string C, int S,int r)
{
	int i;
	for (i = 0; i < nCoursecount && SG[i]->getCourse() != C; i++);
	if (i < nCoursecount)
	{
		SG[i]->setScore(S);
		SG[i]->setCredit(r);
		printgrade();
	}
	

}

void CStudent::deletegrade(string C)
{
	int i, j;
	char ch;
	for (i = 0; i < nCoursecount && SG[i]->getCourse() != C; i++);
		if (i < nCoursecount)
		{
			cout << "确认是否进行删除，请输入y/n" << endl;
			cin >> ch;
			if (ch == 'Y' || ch == 'y')
			{
				for (j = i + 1; j < nCoursecount; j++)
					SG[j - 1] = SG[j];
				nCoursecount--;
				cout << "删除成功！按任意键继续输入，退出请按0：" << endl;
			}
			else
				cout << "放弃本次删除操作！" << endl;
		}
	
}

void CStudent::printinf()
{

	cout <<setw(12) <<getClass() << setw(12) << getNum() << setw(9) << getName();
	if (getSex() == 'f' || getSex() == 'F')
		cout << setw(9) << "男";
	else
		cout << setw(9) << "女";
	cout << setw(15) << getBirthday() << endl;
}

void CStudent::printgrade()
{
	int i;
	dTotalscore = 0;
	dTotalcredit = 0;
	cout << setw(12)<<"班级" << setw(12) << "学号" << setw(9) << "姓名";
	for (i = 0; i < nCoursecount; i++)
		cout << setw(15) << SG[i]->getCourse();
	cout << setw(10) << "总计" << endl;
	cout <<setw(12)<< getClass() << setw(12) << getNum() << setw(9) << getName() ;
	for (i = 0; i < nCoursecount; i++)
		dTotalscore += SG[i]->print();
	cout << setw(10) << dTotalscore << endl;
	cout << setw(33) << "学分";
	for (i = 0; i < nCoursecount; i++)
	{
		cout << setw(15)<< SG[i]->getCredit();
		dTotalcredit += SG[i]->getCredit();
	}
	cout << setw(10) << dTotalcredit << endl;
	
}

void CStudent::setNum(string n2)
{
	sNum = n2;
}

void CStudent::setClass(string n1)
{
	sClass = n1;
}

string CStudent::getpercourse(int j)
{
	return SG[j]->getCourse();
}

int CStudent::getperscore(int j)
{
	return SG[j]->getScore();
}

int CStudent::getpercredit(int j)
{
	return SG[j]->getCredit();
}

string CStudent::getNum()
{
	return sNum;
}



string CStudent::getClass()
{
	return sClass;
}

double CStudent::getTotalscore()
{
	return dTotalscore;
}

char CStudent::getEduLevel()
{
	return cEduLevle;
}

int CStudent::Valid_Course(string C)
{
	int i;
	for (i = 0; i < nCoursecount && SG[i]->getCourse() != C; i++);
	if (i < nCoursecount)
		return 0;
	else
		return 1;
}

int CStudent::getCoursecount()
{
	return nCoursecount;
}

int CStudent::getRank()
{
	return nRank;
}

void CStudent::setRank(int i)
{
	nRank = i;
}
