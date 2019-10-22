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
	int Valid_sex(char ch);               //�ж��Ա���Ч��
	void addFaculty();          //���ӽ�ְ����Ϣ
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
	int menu();         //ϵͳ���溯��
	int facmenu();
	int stumenu();
	void read();
	void save();
private:
	CFaculty **F;								//��ְ��ָ������
	CStudent **S;								//ѧ��ָ������
	int nJuniorstucount;						//ר��������
	int nUndergrastucount;						//����������
	int nGraduatestucount;						//�о�������
	int nTeachercount;							//��ʦ����
	int nAdminipercount;						//������Ա����
	int nTeacherAdminicount;					//��ʦ��������Ա����
	int nRetireecount;							//������Ա����
};

