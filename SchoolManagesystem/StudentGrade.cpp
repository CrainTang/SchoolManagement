#include "stdafx.h"
#include "StudentGrade.h"


CStudentGrade::CStudentGrade(string n1, int S,int C)
{
	sCourse = n1;
	nScore = S;
	nCredit = C;
}

CStudentGrade::~CStudentGrade()
{
}

int CStudentGrade::print()
{
	cout << setw(15) << nScore ;
	return nScore;
}

string CStudentGrade::getCourse()
{
	return sCourse;
}

void CStudentGrade::setScore(int S)
{
	nScore = S;
}

void CStudentGrade::setCredit(int C)
{
	nCredit = C;
}

int CStudentGrade::getScore()
{
	return nScore;
}

int CStudentGrade::getCredit()
{
	return nCredit;
}
