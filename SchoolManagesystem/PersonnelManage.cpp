#include "stdafx.h"
#include "PersonnelManage.h"
#include"algorithm"

CPersonnelManage::CPersonnelManage()
{
	F = new CFaculty *[100];
	S = new CStudent *[100];
	nJuniorstucount = 0;
	nUndergrastucount = 0;
	nGraduatestucount = 0;
	nTeachercount = 0;
	nAdminipercount = 0;
	nTeacherAdminicount = 0;
	nRetireecount = 0;
}


CPersonnelManage::~CPersonnelManage()
{
	int i;
	int nCount = nTeachercount + nAdminipercount + nTeacherAdminicount + nRetireecount;
	for (i = 0; i<nCount; i++)
		delete F[i];
	delete[] F;
	nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	for (i = 0; i<nCount; i++)
		delete S[i];
	delete[] S;
}

int CPersonnelManage::Valid_Facnum(string num)
{
	int nCount = nTeachercount + nAdminipercount + nTeacherAdminicount + nRetireecount;
	for (int i = 0; i < nCount; i++)
		if (num == F[i]->getNum())
			return 0;
	return 1;
}

int CPersonnelManage::Valid_Stunum(string num)
{
	int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	for (int i = 0; i < nCount; i++)
		if (num == S[i]->getNum())
			return 0;
	return 1;
}

int CPersonnelManage::Valid_sex(char ch)
{
	if (ch != 'f'&& ch != 'm' && ch != 'F'&& ch != 'M')
		return 0;
	else
		return 1;
}



void CPersonnelManage::addFaculty()
{
	string sName,sBirthday,sDepartment,sNum;
	int nLevel,nPosition,nClassHours;
	int nCount;
	char cSex;
	double dClassSubsidies,dAdminiSubsidies,dBasicwage;
	while (1)
	{
		nCount = nTeachercount + nAdminipercount + nTeacherAdminicount + nRetireecount;
		cout << "请输入教职工类别：（1、教师 ， 2、行政人员 ， 3、教师兼行政人员 ， 4、退休人员 , 0、取消）" << endl;
		while (1)
		{
			cin >> nPosition;
			if (nPosition != 1 && nPosition != 2 && nPosition != 3 && nPosition != 4 && nPosition != 0)
				cout << "输入错误！请重新选择：" << endl;
			else if (nPosition == 0)
				return;
			else
				break;
		}
		cout << "所属部门：" << endl;
		cin >> sDepartment;
		cout << "工号：" << endl;
		while (1)
		{

			cin >> sNum;
			if (Valid_Facnum(sNum) == 0)
				cout << "该工号已存在！请重新输入：" << endl;
			else
				break;
		}
		cout << "姓名：" << endl;
		cin >> sName;
		cout << "性别：(男请输入：f或F，女请输入：m或M)" << endl;
		while (1)
		{
			cin >> cSex;
			if (Valid_sex(cSex) == 0)
				cout << "输入错误！请重新输入：" << endl;
			else
				break;
		}
		cout << "出生日期：" << endl;
		cin >> sBirthday;
		cout << "级别：" << endl;
		cin >> nLevel;
		switch (nPosition)
		{
		case 1:
			cout << "基本工资：" << endl;
			cin >> dBasicwage;
			cout << "课时：" << endl;
			cin >> nClassHours;
			cout << "课时补贴：" << endl;
			cin >> dClassSubsidies;
			F[nCount] = new CTeacher(sName, cSex, sBirthday, sDepartment, sNum, nLevel, nClassHours, dBasicwage, dClassSubsidies, nPosition);
			nTeachercount++;
			cout << "添加成功！" << endl;
			break;
		case 2:
			cout << "基本工资：" << endl;
			cin >> dBasicwage;
			cout << "行政补贴：" << endl;
			cin >> dAdminiSubsidies;
			F[nCount] = new CAdminiper(sName, cSex, sBirthday, sDepartment, sNum, nLevel, dBasicwage, dAdminiSubsidies, nPosition);
			nAdminipercount++;
			cout << "添加成功！" << endl;
			break;
		case 3:
			cout << "基本工资：" << endl;
			cin >> dBasicwage;
			cout << "课时：" << endl;
			cin >> nClassHours;
			cout << "课时补贴：" << endl;
			cin >> dClassSubsidies;
			cout << "行政补贴：" << endl;
			cin >> dAdminiSubsidies;
			F[nCount] = new CTeacherAdmini(sName, cSex, sBirthday, sDepartment, sNum, nLevel, nClassHours, dBasicwage, dClassSubsidies, dAdminiSubsidies, nPosition);
			nTeacherAdminicount++;
			cout << "添加成功！" << endl;
			break;
		case 4:
			cout << "基本工资：" << endl;
			cin >> dBasicwage;
			F[nCount] = new CRetiree(sName, cSex, sBirthday, sDepartment, sNum, nLevel, dBasicwage, nPosition);
			nRetireecount++;
			cout << "添加成功！" << endl;
			break;
		}
		cout << "按 0 退出，按其他任意键继续添加" << endl;
		if (_getch() == '0')
			break;
	}

}

void CPersonnelManage::searchFaculty()
{
	
	int i;
	int type;
	int nFlag;
	int count = nTeachercount + nAdminipercount + nTeacherAdminicount + nRetireecount;
	while (1)
	{
		system("cls");
		cout << "*********************************************************************" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                 1.按姓名查询        2.按工号查询                  *" << endl;
		cout << "*                 3.按部门查询        4.按级别查询                  *" << endl;
		cout << "*                 0.返回                                            *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                            请输入相应编号：                       *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*********************************************************************" << endl;
		cin >> type;
		switch (type)
		{
		case 1:
		{
			while (1)
			{
				system("cls");
				string nNewname;
				cout << "*************************请输入查询姓名********************:" << endl;
				cin >> nNewname;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getName() == nNewname)
					{
						if (nFlag == 0)
						{
							cout << "查询结果：" << endl;
							cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
						}
						F[i]->print();
						nFlag = 1;
						
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;
				}

				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		}
		case 2:
		{
			while (1)
			{
				system("cls");
				string sNum;
				cout << "*************************请输入查询工号********************:" << endl;
				cin >> sNum;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getNum() == sNum)
					{
						if (nFlag == 0)
						{
							cout << "查询结果：" << endl;
							cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
						}
						F[i]->print();
						nFlag = 1;
						
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		}
		case 3:
		{
			while (1)
			{
				system("cls");
				string  sDepartment;
				cout << "*************************请输入查询部门********************:" << endl;
				cin >> sDepartment;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getDepartment() == sDepartment)
					{
						if (nFlag == 0)
						{
							cout << "查询结果：" << endl;
							cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
						}
						F[i]->print();
						nFlag = 1;
						
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		}
		case 4:
		{
			while (1)
			{
				system("cls");
				int nLevel;
				cout << "*************************请输入查询级别********************:" << endl;
				cin >> nLevel;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getLevel() == nLevel)
					{
						if (nFlag == 0)
						{
							cout << "查询结果：" << endl;
							cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
						}
						F[i]->print();
						nFlag = 1;
					}
					
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
					
			}
			break;
		}
		case 0:
			return;
		default:
			cout << "输入有误，按任意键清除并重新输入！" << endl;
			_getch();
		}
	
			
		
	}
}

void CPersonnelManage::updateFaculty()
{
	int i, type;
	string sNum;
	int count = nTeachercount + nAdminipercount + nTeacherAdminicount + nRetireecount;
	while (1)
	{
		system("cls");
		cout << "请输入要修改的教职工工号:" << endl;
		cin >> sNum;
		for (i = 0; i < count && (F[i]->getNum() != sNum); i++);
		if (i < count)
		{
			while (1)
			{
				system("cls");						
				cout << "*********************************************************************" << endl;
				cout << "*                                                                   *" << endl;
				cout << "*            1.修改姓名              2.修改工号                     *" << endl;
				cout << "*            3.修改性别              4.修改出生日期                 *" << endl;
				cout << "*            5.修改部门              6.修改级别                     *" << endl;
				cout << "*            7.修改课时（教师）      8.修改基本工资                 *" << endl;
				cout << "*            9.修改课时补贴（教师） 10.修改行政补贴（行政人员）     *" << endl;
				cout << "*                              0.返回                               *" << endl;
				cout << "*                          请输入相应编号：                         *" << endl;
				cout << "*                                                                   *" << endl;
				cout << "*                                                                   *" << endl;
				cout << "*********************************************************************" << endl;
				cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
				F[i]->print();
				cin >> type;
				switch (type)
				{
				case 1:
				{
					string sName;
					cout << "***************************请输入新的姓名******************:" << endl;
					cin >> sName;
					F[i]->setName(sName);
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "修改成功！" << endl;
					cout << "按任意键继续" << endl;
					_getch();
				}
				break;
				case 2:
				{
					cout << "*************************请输入新的工号********************:" << endl;
					while (1)
					{
						cin >> sNum;
						if (sNum == "0")
							break;
						if (Valid_Facnum(sNum) == 0)
							cout << "该工号已存在！请重新输入(输入 0 取消修改)：" << endl;
						
						else
						{
							F[i]->setNum(sNum);
							cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
							F[i]->print();
							cout << "修改成功！" << endl;
							cout << "按任意键继续" << endl;
							_getch(); 
							break;
						}
					}
				}
				break;
				case 3:
				{
					char cSex;
					cout << "******请输入新的性别(男请输入：f或F，女请输入：m或M)******:" << endl;
					while (1)
					{
						cin >> cSex;
						if (cSex == '0')
							break;
						if (Valid_sex(cSex) == 0)
							cout << "输入错误！请重新输入(输入 0 取消修改)：" << endl;
						
						else
						{
							F[i]->setSex(cSex);
							cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
							F[i]->print();
							cout << "修改成功！" << endl;
							cout << "按任意键继续" << endl;
							_getch();
							break;
						}
					}
					
				}
				break;
				case 4:
				{
					string sBirthday;
					cout << "***********************请输入新的出生日期******************:" << endl;
					cin >> sBirthday;
					F[i]->setBirthday(sBirthday);
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "修改成功！" << endl;
					cout << "按任意键继续" << endl;
					_getch();
				}
				break;
				case 5:
				{
					string sDepartment;
					cout << "*************************请输入新的部门********************:" << endl;
					cin >> sDepartment;
					F[i]->setDepartment(sDepartment);
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "修改成功！" << endl;
					cout << "按任意键继续" << endl;
					_getch();
				}
				break;
				case 6:
				{
					int nLevel;
					cout << "*************************请输入新的级别********************:" << endl;
					cin >> nLevel;
					F[i]->setLevel(nLevel);
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "修改成功！" << endl;
					cout << "按任意键继续" << endl;
					_getch();
				}
				break;
				case 7:
					F[i]->setClassHours();
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "按任意键继续" << endl;
					_getch();
					break;
				case 8:
				{
					double dBasicwage;
					cout << "***********************请输入新的基本工资******************:" << endl;
					cin >> dBasicwage;
					F[i]->setBasicWage(dBasicwage);
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "修改成功！" << endl;
					cout << "按任意键继续" << endl;
					_getch();
				}
				break;
				case 9:
					F[i]->setClassSubsidies();
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "按任意键继续" << endl;
					_getch();
					break;
				case 10:
					F[i]->setAdminiSubsidies();
					cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
					F[i]->print();
					cout << "按任意键继续" << endl;
					_getch();
					break;
				case 0:
					return;
				default:
					cout << "输入有误，按任意键清除并重新输入！" << endl;
					_getch();
				}
			}
		}
		else
		{
			cout << "不存在符合条件的教职工信息！" << endl;
			cout << "按 0 返回，按其他任意键重新输入" << endl;
			if (_getch() == '0')
				break;
		}
	}
}

void CPersonnelManage::deleteFaculty()
{
	int nType, nFlag,i, j = 0;
	int nCount = nTeachercount + nAdminipercount + nTeacherAdminicount + nRetireecount;
	char ch;
	while (1)
	{
		system("cls");
		nFlag = 0;
		cout << "*********************************************************************" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                   1.按姓名删除        2.按工号删除                *" << endl;
		cout << "*                   3.按部门删除        0.返回                      *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                            请输入相应编号：                       *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*********************************************************************" << endl;
		cin >> nType;
		switch (nType)
		{
		case 1:
		{
			while (1)
			{
				system("cls");
				string sName;
				cout << "*************************请输入删除姓名********************:" << endl;
				cin >> sName;
				for (i = 0; i < nCount; i++)
				{
					if (F[i]->getName() == sName)
					{
						nFlag = 1;
						cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别";
						cout << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
						F[i]->print();
						cout << "确认是否进行删除，请输入y/n" << endl;
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
						{
							for (j = i + 1; j < nCount; j++)
								F[j - 1] = F[j];
							if (i <= nTeachercount)
								nTeachercount--;
							else
								if (i <= nAdminipercount)
									nAdminipercount--;
								else
									if (i <= nTeacherAdminicount)
										nTeacherAdminicount--;
									else
										nRetireecount--;
							cout << "删除成功" << endl;
						}
						else
							cout << "放弃本次删除操作！" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
			
		}
		case 2:
		{
			while (1)
			{
				system("cls");
				string sNum;
				cout << "*************************请输入删除工号********************:" << endl;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (F[i]->getNum() == sNum)
					{
						nFlag = 1;
						cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别";
						cout << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
						F[i]->print();
						cout << "确认是否进行删除，请输入y/n" << endl;
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
						{
							for (j = i + 1; j < nCount; j++)
								F[j - 1] = F[j];
							if (i <= nTeachercount)
								nTeachercount--;
							else
								if (i <= nAdminipercount)
									nAdminipercount--;
								else
									if (i <= nTeacherAdminicount)
										nTeacherAdminicount--;
									else
										nRetireecount--;
							cout << "删除成功" << endl;
						}
						else
							cout << "放弃本次删除操作！" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		}
		case 3:
		{
			while (1)
			{
				system("cls");
				string sDepartment;
				cout << "***************************请输入部门**********************:" << endl;
				cin >> sDepartment;
				for (i = 0; i < nCount; i++)
				{
					if (F[i]->getDepartment() == sDepartment)
					{
						nFlag = 1;
						cout << setw(12) << "部门" << setw(12) << "工号" << setw(9) << "姓名" << setw(9) << "性别";
						cout << setw(15) << "出生年月" << setw(9) << "级别" << setw(9) << "工资" << endl;
						F[i]->print();
						cout << "确认是否进行删除，请输入y/n" << endl;
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
						{
							for (j = i + 1; j < nCount; j++)
								F[j - 1] = F[j];
							if (i <= nTeachercount)
								nTeachercount--;
							else
								if (i <= nAdminipercount)
									nAdminipercount--;
								else
									if (i <= nTeacherAdminicount)
										nTeacherAdminicount--;
									else
										nRetireecount--;
							cout << "删除成功" << endl;
						}
						else
							cout << "放弃本次删除操作！" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		}
		case 0:
			return;
		default:
		{
			cout << "输入有误，按任意键清除并重新输入！" << endl;
			_getch();
		}
		}
	}
}

void CPersonnelManage::addStudent()
{
	int nCount;
	char cSex,cEduLevel;
	string sClass, sNum,sName,sBirthday;
	while (1)
	{
		nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
		cout << "请输入学生培养层次：（1、研究生 ， 2、本科生 ， 3、专科生 ， 0、取消 ）" << endl;
		while (1)
		{
			cin >> cEduLevel;
			if (cEduLevel != '1' && cEduLevel != '2' && cEduLevel != '3' && cEduLevel != '0')
				cout << "输入错误！请重新选择：" << endl;
			else if (cEduLevel == '0')
				return;
			else
				break;
		}
		cout << "班级：" << endl;
		cin >> sClass;
		cout << "学号：" << endl;
		while (1)
		{
			cin >> sNum;
			if (Valid_Stunum(sNum) == 1)
				break;
			else
				cout << "此学号已存在！请重新输入：" << endl;
		}
		cout << "姓名：" << endl;
		cin >> sName;
		cout << "性别：(男请输入：f或F，女请输入：m或M)" << endl;
		while (1)
		{
			cin >> cSex;
			if (Valid_sex(cSex) == 0)
				cout << "输入错误！请重新输入：" << endl;
			else
				break;
		}
		cout << "出生日期：" << endl;
		cin >> sBirthday;
		switch (cEduLevel)
		{
		case '1':
			S[nCount] = new CJuniorstu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
			nGraduatestucount++;
			cout << "添加成功！" << endl;
			break;
		case '2':
			S[nCount] = new CUndergrastu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
			nUndergrastucount++;
			cout << "添加成功！" << endl;
			break;
		case '3':
			S[nCount] = new CGraduatestu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
			nJuniorstucount++;
			cout << "添加成功！" << endl;
			break;
		}
		cout << "按 0 退出，按其他任意键继续添加:" << endl;
		if(_getch() == '0')
			break;
	}

}

void CPersonnelManage::searchStudent()
{
	string sName,sNum,sClass;
	int i,nFlag;
	int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	while (1)
	{
		system("cls");
		cout << "*********************************************************************" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                   1.按姓名查询        2.按学号查询                *" << endl;
		cout << "*                   3.按班级查询        0.返回                      *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                            请输入相应编号：                       *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*********************************************************************" << endl;
		int nType;
		cin >> nType;
		switch (nType)
		{
		case 1:
			while(1)
			{
				system("cls");
				cout << "*************************请输入查询姓名********************:" << endl;
				nFlag = 0;
				cin >> sName;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getName() == sName)
					{
						if (nFlag == 0)
						{
							cout << "查询结果：" << endl;
							cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
						}
						S[i]->printinf();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的学生信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				cout << "*************************请输入查询学号********************:" << endl;
				nFlag = 0;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getNum() == sNum)
					{
						if (nFlag == 0)
						{
							cout << "查询结果：" << endl;
							cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
						}
						S[i]->printinf();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的学生信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 3:
			while (1)
			{
				system("cls");
				cout << "*************************请输入查询班级********************:" << endl;
				nFlag = 0;
				cin >> sClass;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getClass() == sClass)
					{
						if (nFlag == 0)
						{
							cout << "查询结果：" << endl;
							cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
						}
						S[i]->printinf();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的学生信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 0:
			return;
		default:
			cout << "输入有误，请重新输入！" << endl;
		}
	}
}

void CPersonnelManage::updateStudent()
{
	int i,nType;
	int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	string sNum;
	system("cls");
	cout << "请输入要修改的学生学号:" << endl;
	cin >> sNum;
	for (i = 0; i< nCount && (S[i]->getNum() != sNum); i++);
	if (i < nCount)
	{
		
		while (1)
		{
			system("cls");
			cout << "*********************************************************************" << endl;
			cout << "*                                                                   *" << endl;
			cout << "*                      1.修改姓名       2.修改学号                  *" << endl;
			cout << "*                      3.修改性别       4.修改出生日期              *" << endl;
			cout << "*                      5.修改班级       0.返回                      *" << endl;
			cout << "*                                                                   *" << endl;
			cout << "*                            请输入相应编号：                       *" << endl;
			cout << "*                                                                   *" << endl;
			cout << "*********************************************************************" << endl;	
			cout << setw(12)<<"班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
			S[i]->printinf();
			cin >> nType;
			switch (nType)
			{
			case 1:
				{
					string sName;
					cout << "*********************请输入新的姓名************************:" << endl;
					cin >> sName;
					S[i]->setName(sName);
					cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
					S[i]->printinf();
					cout << "修改成功！" << endl;
					cout << "按任意键继续" << endl;
					_getch();
				}break;
			case 2:
			{
				cout << "**********************请输入新的学号***********************:" << endl;
				while (1)
				{
					cin >> sNum;
					if (sNum == "0")
						break;
					if(Valid_Stunum(sNum) == 0)
						cout << "该学号已存在！请重新输入(输入 0 取消修改)：" << endl;
					
					else
					{
						S[i]->setNum(sNum);
						cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
						S[i]->printinf();
						cout << "修改成功！" << endl;
						cout << "按任意键继续" << endl;
						_getch();
						break;
					}
				}
			}
			break;
			case 3:
			{
				char cSex;
				cout << "**********************请输入新的性别***********************:" << endl;
				while (1)
				{
					cin >> cSex;
					if (cSex == '0')
						break;
					if (Valid_sex(cSex) == 0)
						cout << "输入错误！请重新输入(输入 0 取消修改)：" << endl;
					else
					{
						S[i]->setSex(cSex);
						cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
						S[i]->printinf();
						cout << "修改成功！" << endl;
						cout << "按任意键继续" << endl;
						_getch();
						break;
					}
				}
			}
			break;
			case 4:
			{
				string sBirthday;
				cout << "**********************请输入新的出生日期***********************:" << endl;
				cin >> sBirthday;
				S[i]->setBirthday(sBirthday);
				cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
				S[i]->printinf();
				cout << "修改成功！" << endl;
				cout << "按任意键继续" << endl;
				_getch();
			}break;
			case 5:
			{
				string sClass;
				cout << "**********************请输入新的班级***********************:" << endl;
				cin >> sClass;
				S[i]->setClass(sClass);
				cout << setw(12) << "班级" << setw(12) << "学号" << setw(9) << "姓名" << setw(9) << "性别" << setw(15) << "出生日期" << endl;
				S[i]->printinf();
				cout << "修改成功！" << endl;
				cout << "按任意键继续" << endl;
				_getch();
			}break;
			case 0:
				return;
			default:
				cout << "输入错误！请重新输入：" << endl;
			}
		}
	}
	else cout << "不存在符合条件的学生记录！" << endl;
	cout << "按任意键继续:" << endl;
	_getch();
}

void CPersonnelManage::deleteStudent()
{
	int nType, nFlag, i, j = 0;
	int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	char ch;
	while (1)
	{
		system("cls");
		nFlag = 0;
		cout << "*********************************************************************" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                  1.按姓名删除        2.按学号删除                 *" << endl;
		cout << "*                  3.按班级删除        0.返回                       *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                          请输入相应编号：                         *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*********************************************************************" << endl;
		cin >> nType;
		switch (nType)
		{
		case 1:
			while(1)
			{
				system("cls");
				string sName;
				cout << "*************************请输入删除姓名********************:" << endl;
				cin >> sName;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getName() == sName)
					{
						nFlag = 1;
						S[i]->printinf();
						cout << "确认是否进行删除，请输入y/n" << endl;
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
						{
							for (j = i + 1; j < nCount; j++)
								S[j - 1] = S[j];
							if (i <= nJuniorstucount)
								nJuniorstucount--;
							else
								if (i <= nUndergrastucount)
									nUndergrastucount--;
								else
									nGraduatestucount--;
							cout << "删除成功" << endl;
						}
						else
							cout << "放弃本次删除操作！" << endl;
					}

				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				string sNum;
				cout << "*************************请输入删除学号********************:" << endl;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getNum() == sNum)
					{
						nFlag = 1;
						S[i]->printinf();
						cout << "确认是否进行删除，请输入y/n" << endl;
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
						{
							for (j = i + 1; j < nCount; j++)
								S[j - 1] = S[j];
							if (i <= nJuniorstucount)
								nJuniorstucount--;
							else
								if (i <= nUndergrastucount)
									nUndergrastucount--;
								else
									nGraduatestucount--;
							cout << "删除成功" << endl;
						}
						else
							cout << "放弃本次删除操作！" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 3:
			while (1)
			{
				system("cls");
				string sClass;
				cout << "*************************请输入删除班级********************:" << endl;
				cin >> sClass;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getClass() == sClass)
					{
						nFlag = 1;
						S[i]->printinf();
						cout << "确认是否进行删除，请输入y/n" << endl;
						cin >> ch;
						if (ch == 'Y' || ch == 'y')
						{
							for (j = i + 1; j < nCount; j++)
								S[j - 1] = S[j];
							if (i <= nJuniorstucount)
								nJuniorstucount--;
							else
								if (i <= nUndergrastucount)
									nUndergrastucount--;
								else
									nGraduatestucount--;
							cout << "删除成功" << endl;
						}
						else
							cout << "放弃本次删除操作！" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的教职工信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		
		case 0:
			return;
		default:
			cout << "输入有误，请重新输入！" << endl;
		}
	}
}

void CPersonnelManage::entergrade()
{
	int i;
	int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	int nCredit;
	string sNum,sCourse;
	int nScore;
	cout << "************************请输入学号************************：" << endl;
	while (1)
	{
		cin >> sNum;
		for (i = 0; i < nCount && S[i]->getNum() != sNum; i++);
		if (i < nCount)
		{
			S[i]->printgrade();
			break;
		}
		else
			cout << "没有此学生，请重新输入：" << endl;
	}
	while (1)
	{
		cout << "请输入要录入的科目：" << endl;
		while (1)
		{
			cin >> sCourse;
			if (S[i]->Valid_Course(sCourse) == 1)
				break;
			else
				cout << "此科目已存在！请重新输入：" << endl;
		}
		cout << "请输入要录入的分数：" << endl;
		cin >> nScore;
		cout << "请输入新的学分：" << endl;
		cin >> nCredit;
		S[i]->entergrade(sCourse, nScore,nCredit);
		S[i]->printgrade();
		cout << "录入成功！按任意键继续录入，退出请按0：" << endl;
		char ch;
		ch = _getch();
		if (ch == '0')
			break;
	}
}

void CPersonnelManage::searchgrade()
{
	while (1)
	{
		system("cls");
		string sName, sNum, sClass,sCourse;
		int i, nType,nFlag;
		int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
		cout << "*********************************************************************" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                  1.按姓名查询        2.按学号查询                 *" << endl;
		cout << "*                  3.按班级查询        0.返回                       *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                         请输入相应编号：                          *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*********************************************************************" << endl;
	
		
		cin >> nType;
		system("cls");
		switch (nType)
		{
		case 1:
			while (1)
			{
				system("cls");
				cout << "***********************请输入查询姓名***********************:" << endl;
				nFlag = 0;
				cin >> sName;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getName() == sName)
					{

						S[i]->printgrade();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的学生成绩信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				cout << "***********************请输入查询学号**********************:" << endl;
				nFlag = 0;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getNum() == sNum)
					{
						if (nFlag == 0)
							cout << "成绩：" << endl;
						S[i]->printgrade();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的学生成绩信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 3:
			while (1)
			{
				system("cls");
				cout << "***********************请输入查询班级**********************:" << endl;
				nFlag = 0;
				cin >> sClass;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getClass() == sClass)
					{
						if (nFlag == 0)
							cout << "成绩：" << endl << endl;
						S[i]->printgrade();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "不存在符合条件的学生成绩信息！" << endl;
					cout << "按 0 返回，按其他任意键重新输入" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "按任意键继续!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 0:
			return;
		default:
			cout << "输入有误，请重新输入！" << endl;
			_getch();
		}
	}
}

void CPersonnelManage::updategrade()
{
	int i,nScore,nCredit,nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	string sCourse;
	cout << "请输入要修改成绩的学生学号：" << endl;
	string sNum;
	while (1)
	{
		cin >> sNum;
		for (i = 0; i < nCount && (S[i]->getNum() != sNum); i++);
		if (i < nCount)
		{
			S[i]->printgrade();
			break;
		}
		else
			cout << "此学号不存在！请重新输入：" << endl;
	}
	while(1)
	{
		cout << "请输入您要修改的科目：" << endl;
		cin >> sCourse;
		if (S[i]->Valid_Course(sCourse) == 1)
			cout << "此科目不存在！按任意键重新录入，退出请按0：" << endl;
		else
		{
			cout << "请输入新的分数：" << endl;
			cin >> nScore;
			cout << "请输入新的学分：" << endl;
			cin >> nCredit;
			S[i]->setgrade(sCourse, nScore,nCredit);
			cout << "修改成功！按任意键继续录入，退出请按0：" << endl;
		}
		char ch;
		ch = _getch();
		if (ch == '0')
			break;
			
	}

}

void CPersonnelManage::gradeorder()
{
	string sClass;
	int i, j = 0,nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	CStudent *a[50]; CStudent *t;
	cout << "请输入班级：" << endl;
	cin >> sClass;
	for (i = 0; i < nCount; i++)
	{
		if (S[i]->getClass() == sClass)
		{
			a[j] = S[i];
			j++;
		}
	}
	int k;
	for (k = 0; k<j; k++)
		for (i = 0; i < j - 1 - k; i++)
			if (a[i]->getTotalscore() < a[i + 1]->getTotalscore()) 
			{
				t = a[i];
				a[i] = a[i + 1];
				a[i + 1] = t;
			}
	for (i = 0; i < j; i++)
	{
		cout << setw(5) << "第" << i + 1 << "名" << endl;
		a[i]->printgrade();
		for (int p = 0; p < nCount; p++)
		{
			if (S[p]->getNum() == a[i]->getNum())
				S[p]->setRank(i+1);
		}
	}
	cout << "按任意键返回" << endl;
	_getch();
}

void CPersonnelManage::deletegrade()
{
	int i, nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	string sCourse;
	cout << "请输入要删除成绩的学生学号：" << endl;
	string sNum;
	while (1)
	{
		cin >> sNum;
		for (i = 0; i < nCount && (S[i]->getNum() != sNum); i++);
		if (i < nCount)
		{
			S[i]->printgrade();
			break;
		}
		else
			cout << "此学号不存在！请重新输入：" << endl;
	}
	while (1)
	{
		cout << "请输入您要删除的科目：" << endl;
		string sCourse;
		cin >> sCourse;
		if (S[i]->Valid_Course(sCourse) == 1)
			cout << "此科目不存在！按任意键重新输入，退出请按0：" << endl;
		else
			S[i]->deletegrade(sCourse);
		if(_getch() == '0')
			break;
	

	}
}




int CPersonnelManage::menu()
{
	system("cls");
	cout << "*********************************************************************" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                        欢迎使用校园信息管理系统                   *" << endl;
	cout << "*                 1.教职工信息                2.学生信息            *" << endl;
	cout << "*                              0.退出系统                           *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                            请输入相应编号                         *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*********************************************************************" << endl;
	int n ;
	cin >> n;
	return n;
}

int CPersonnelManage::facmenu()
{
	system("cls");
	cout << "*********************************************************************" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                       欢迎使用教职工信息管理系统                  *" << endl;
	cout << "*                 1.添加教职工信息      2.查询教职工信息            *" << endl;
	cout << "*                 3.修改教职工信息      4.删除教职工信息            *" << endl;
	cout << "*                                 0.返回                            *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                               请输入相应编号                      *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*********************************************************************" << endl;
	int n;
	cin >> n;
	return n;
}

int CPersonnelManage::stumenu()
{
	system("cls");
	cout << "*********************************************************************" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                       欢迎使用学生信息管理系统                    *" << endl;
	cout << "*                1.添加学生信息          2.查询学生信息             *" << endl;
	cout << "*                3.修改学生信息          4.删除学生信息             *" << endl;
	cout << "*                5.录入学生成绩          6.查询学生成绩             *" << endl;
	cout << "*                7.修改学生成绩          8.删除学生成绩             *" << endl;
	cout << "*                9.班级排名              0.返回                     *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                             请输入相应编号：                      *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*********************************************************************" << endl;
	int n;
	cin >> n;
	return n;
}

void CPersonnelManage::read()
{
	string sName, sBirthday, sDepartment, sNum;
	char cSex;
	int	nLevel, nClassHours, nPosition, nWage;
	double dBasicwage, dClassSubsidies, dAdminiSubsidies;
	int i;
	ifstream infile_t("C:\\Users\\Crain\\Desktop\\SchoolManage\\teacher.txt", ios::in);
	ifstream infile_a("C:\\Users\\Crain\\Desktop\\SchoolManage\\admini.txt", ios::in);
	ifstream infile_ta("C:\\Users\\Crain\\Desktop\\SchoolManage\\teacheradmini.txt", ios::in);
	ifstream infile_r("C:\\Users\\Crain\\Desktop\\SchoolManage\\retiree.txt", ios::in);
	ifstream infile_j("C:\\Users\\Crain\\Desktop\\SchoolManage\\juniorstu.txt", ios::in);
	ifstream infile_u("C:\\Users\\Crain\\Desktop\\SchoolManage\\undergrastu.txt", ios::in);
	ifstream infile_g("C:\\Users\\Crain\\Desktop\\SchoolManage\\graduatestu.txt", ios::in);
	if (!infile_t || !infile_a || !infile_ta || !infile_r || !infile_j || !infile_u || !infile_g)
	{
		cout << "打开文件失败！" << endl;
		exit(0);
	}
	infile_t >> nTeachercount;
	infile_a >> nAdminipercount;
	infile_ta >> nTeacherAdminicount;
	infile_r >> nRetireecount;
	infile_j >> nJuniorstucount;
	infile_u >> nUndergrastucount;
	infile_g >> nGraduatestucount;
	for (i = 0; i < nTeachercount; i++)
	{
		infile_t >> sName >> cSex >> sBirthday >> sDepartment >> sNum >> nLevel >> nClassHours >> dBasicwage >> dClassSubsidies >> nWage >> nPosition;
		F[i] = new CTeacher(sName, cSex, sBirthday, sDepartment, sNum, nLevel, nClassHours, dBasicwage, dClassSubsidies, nPosition);

	}
	for (i = 0; i < nAdminipercount; i++)
	{
		infile_a >> sName >> cSex >> sBirthday >> sDepartment >> sNum >> nLevel >> dBasicwage >> dAdminiSubsidies >> nWage >> nPosition;
		F[i+nTeachercount] = new CAdminiper(sName, cSex, sBirthday, sDepartment, sNum, nLevel, dBasicwage, dAdminiSubsidies, nPosition);
	}
	for (i = 0; i < nTeacherAdminicount; i++)
	{
		infile_ta >> sName >> cSex >> sBirthday >> sDepartment >> sNum >> nLevel >> nClassHours >> dBasicwage >> dClassSubsidies >> dAdminiSubsidies >> nWage >> nPosition;
		F[i + nTeachercount + nAdminipercount] = new CTeacherAdmini(sName, cSex, sBirthday, sDepartment, sNum, nLevel, nClassHours, dBasicwage, dClassSubsidies, dAdminiSubsidies, nPosition);
	}
	for (i = 0; i < nRetireecount; i++)
	{
		infile_r >> sName >> cSex >> sBirthday >> sDepartment >> sNum >> nLevel >> dBasicwage >> nWage >> nPosition;
		F[i + nTeachercount + nAdminipercount + nTeacherAdminicount] = new CRetiree(sName, cSex, sBirthday, sDepartment, sNum, nLevel, dBasicwage, nPosition);
	}
	string sClass; char cEduLevel;
	for (i = 0; i < nJuniorstucount; i++)
	{
		infile_j >> sClass >> sNum >> sName >> cSex >> sBirthday >> cEduLevel;
		S[i] = new CJuniorstu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
	}
	for (i = 0; i < nUndergrastucount; i++)
	{
		infile_u >> sClass >> sNum >> sName >> cSex >> sBirthday >> cEduLevel;
		S[i + nJuniorstucount] = new CUndergrastu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
	}
	for (i = 0; i < nGraduatestucount; i++)
	{
		infile_g >> sClass >> sNum >> sName >> cSex >> sBirthday >> cEduLevel;
		S[i + nJuniorstucount + nUndergrastucount] = new CGraduatestu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
	}
	ifstream infile_sg("C:\\Users\\Crain\\Desktop\\SchoolManage\\stugrade.txt", ios::in);
	if (!infile_sg)
	{
		cout << "打开成绩文件失败！" << endl;
		exit(0);
	}
	int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	int j,k;
	string sCourse;
	int nScore,nCoursecount,nCredit,dTotalscore,nRank;
	for (i = 0; i < nCount; i++)
	{
		infile_sg >> sNum;
		for (j = 0; j < nCount; j++)
		{
			if (S[j]->getNum() == sNum)
			{
				infile_sg >> sClass >> sName >> nCoursecount;
				for (k = 0; k < nCoursecount; k++)
				{
					infile_sg >> sCourse >> nScore >> nCredit;
					S[j]->entergrade(sCourse, nScore,nCredit);
				}
				break;
			}
		}
		infile_sg>>dTotalscore>>nRank;
		S[i]->setRank(nRank);
	}
	infile_t.close();
	infile_a.close();
	infile_ta.close();
	infile_r.close();
	infile_j.close();
	infile_u.close();
	infile_g.close();
	infile_sg.close();
}

void CPersonnelManage::save()
{
	int i;
	
	ofstream outfile_t("C:\\Users\\Crain\\Desktop\\SchoolManage\\teacher.txt", ios::out);
	ofstream outfile_a("C:\\Users\\Crain\\Desktop\\SchoolManage\\admini.txt", ios::out);
	ofstream outfile_ta("C:\\Users\\Crain\\Desktop\\SchoolManage\\teacheradmini.txt", ios::out);
	ofstream outfile_r("C:\\Users\\Crain\\Desktop\\SchoolManage\\retiree.txt", ios::out);
	ofstream outfile_j("C:\\Users\\Crain\\Desktop\\SchoolManage\\juniorstu.txt", ios::out);
	ofstream outfile_u("C:\\Users\\Crain\\Desktop\\SchoolManage\\undergrastu.txt", ios::out);
	ofstream outfile_g("C:\\Users\\Crain\\Desktop\\SchoolManage\\graduatestu.txt", ios::out);
	if (!outfile_t || !outfile_a || !outfile_ta || !outfile_r || !outfile_j || !outfile_u || !outfile_g)
	{
		cout << "打开文件失败！" << endl;
		return;
	}	
	outfile_t << nTeachercount << endl;
	outfile_a << nAdminipercount << endl;
	outfile_ta << nTeacherAdminicount << endl;
	outfile_r << nRetireecount << endl;
	outfile_j << nJuniorstucount << endl;
	outfile_u << nUndergrastucount << endl;
	outfile_g << nGraduatestucount << endl;
	int nCount = nTeachercount + nAdminipercount + nTeacherAdminicount + nRetireecount;
	for (i = 0; i < nCount; i++)
	{
		switch (F[i]->getPosition())
		{
		case 1:
			outfile_t << F[i]->getName() << " " << F[i]->getSex() << " " << F[i]->getBirthday() << " ";
			outfile_t << F[i]->getDepartment() << " " << F[i]->getNum() << " " << F[i]->getLevel() << " ";
			outfile_t << F[i]->getClassHours() << " " << F[i]->getBasicwage() << " " << F[i]->getClassSubsidies() << " " ;
			outfile_t << F[i]->getWage() << " " << F[i]->getPosition() << endl;
			break;
		case 2:
			outfile_a << F[i]->getName() << " " << F[i]->getSex() << " " << F[i]->getBirthday() << " ";
			outfile_a << F[i]->getDepartment() << " " << F[i]->getNum() << " " << F[i]->getLevel() << " ";
			outfile_a << F[i]->getBasicwage() << " " << F[i]->getAdminiSubsidies() << " " << F[i]->getWage() << " " << F[i]->getPosition() << endl;
			break;
		case 3:
			outfile_ta << F[i]->getName() << " " << F[i]->getSex() << " " << F[i]->getBirthday() << " ";
			outfile_ta << F[i]->getDepartment() << " " << F[i]->getNum() << " " << F[i]->getLevel() << " ";
			outfile_ta << F[i]->getClassHours() << " " << F[i]->getBasicwage() << " " << F[i]->getClassSubsidies() << " ";
			outfile_ta << F[i]->getAdminiSubsidies() << " " << F[i]->getWage() << " " << F[i]->getPosition() << endl;
			break;
		case 4:
			outfile_r << F[i]->getName() << " " << F[i]->getSex() << " " << F[i]->getBirthday() << " ";
			outfile_r << F[i]->getDepartment() << " " << F[i]->getNum() << " " << F[i]->getLevel() << " ";
			outfile_r << F[i]->getBasicwage() << " " << F[i]->getWage() << " " << F[i]->getPosition() << endl;
			break;
		}
	}
		
	nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	for (i = 0; i < nCount; i++)
	{
		switch (S[i]->getEduLevel())
		{
		case '1':
			outfile_g << S[i]->getClass() << " " << S[i]->getNum() << " " << S[i]->getName() << " ";
			outfile_g << S[i]->getSex() << " " << S[i]->getBirthday() << " " << S[i]->getEduLevel() << endl;
			break;
		case '2':
			outfile_u << S[i]->getClass() << " " << S[i]->getNum() << " " << S[i]->getName() << " ";
			outfile_u << S[i]->getSex() << " " << S[i]->getBirthday() << " " << S[i]->getEduLevel() << endl;
			break;
		case '3':
			outfile_j << S[i]->getClass() << " " << S[i]->getNum() << " " << S[i]->getName() << " ";
			outfile_j << S[i]->getSex() << " " << S[i]->getBirthday() << " " << S[i]->getEduLevel() << endl;
			break;
		}
	}
	ofstream outfile_sg("C:\\Users\\Crain\\Desktop\\SchoolManage\\stugrade.txt", ios::out);
	if (!outfile_sg)
	{
		cout << "打开成绩文件失败！" << endl;
		return;
	}

	int j;
	for (i = 0; i < nCount; i++)
	{
		outfile_sg << S[i]->getNum() << " " << S[i]->getClass() << " " << S[i]->getName() << " " << S[i]->getCoursecount() << " ";
		for (j = 0; j < S[i]->getCoursecount(); j++)
		{
			outfile_sg << S[i]->getpercourse(j) << " " << S[i]->getperscore(j) << " " << S[i]->getpercredit(j) << " ";
		}
		outfile_sg << S[i]->getTotalscore() << " " << S[i]->getRank() << endl;
	}

	outfile_t.close();
	outfile_a.close();
	outfile_ta.close();
	outfile_r.close();
	outfile_j.close();
	outfile_u.close();
	outfile_g.close();
	outfile_sg.close();
}




