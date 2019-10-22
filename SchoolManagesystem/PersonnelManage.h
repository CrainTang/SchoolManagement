#pragma once
#include"Personnel.h"
#include"Faculty.h"
#include"TeacherAdmini.h"
#include"Retiree.h"
#include"Juniorstu.h"
#include"Undergrastu.h"
#include"Graduatestu.h"
#include"iostream"
#include"fstream"
#include"conio.h"
class CPersonnelManage
{
public:
	CPersonnelManage();
	
	~CPersonnelManage();
	int Valid_Facnum(string num);
	int Valid_Stunum(string num);
	int Valid_sex(char ch);               //判断性别有效性
	void addFaculty();          //增加教职工信息
	void searchFaculty();
	void updateFaculty();
	void deleteFaculty();
	void addStudent();
	void searchStudent();
	void updateStudent();
	void deleteStudent();
	void entergrade();
	void searchgrade();
	void updategrade();
	void gradeorder();
	void deletegrade();
	int menu();         //系统界面函数
	int facmenu();
	int stumenu();
	void read();
	void save();
private:
	CFaculty **F;								//教职工指针数组
	CStudent **S;								//学生指针数组
	int nJuniorstucount;						//专科生数量
	int nUndergrastucount;						//本科生数量
	int nGraduatestucount;						//研究生熟练
	int nTeachercount;							//教师数量
	int nAdminipercount;						//行政人员数量
	int nTeacherAdminicount;					//教师兼行政人员数量
	int nRetireecount;							//退休人员数量
};

