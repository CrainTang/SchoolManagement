#include "stdafx.h"
#include "Graduatestu.h"


CGraduatestu::CGraduatestu(string n1, string n2, string n3, char s, string n4, char L):CStudent(n1, n2, n3, s, n4)
{
	cEduLevle = L;
}


CGraduatestu::~CGraduatestu()
{
}
