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
		cout << "�������ְ����𣺣�1����ʦ �� 2��������Ա �� 3����ʦ��������Ա �� 4��������Ա , 0��ȡ����" << endl;
		while (1)
		{
			cin >> nPosition;
			if (nPosition != 1 && nPosition != 2 && nPosition != 3 && nPosition != 4 && nPosition != 0)
				cout << "�������������ѡ��" << endl;
			else if (nPosition == 0)
				return;
			else
				break;
		}
		cout << "�������ţ�" << endl;
		cin >> sDepartment;
		cout << "���ţ�" << endl;
		while (1)
		{

			cin >> sNum;
			if (Valid_Facnum(sNum) == 0)
				cout << "�ù����Ѵ��ڣ����������룺" << endl;
			else
				break;
		}
		cout << "������" << endl;
		cin >> sName;
		cout << "�Ա�(�������룺f��F��Ů�����룺m��M)" << endl;
		while (1)
		{
			cin >> cSex;
			if (Valid_sex(cSex) == 0)
				cout << "����������������룺" << endl;
			else
				break;
		}
		cout << "�������ڣ�" << endl;
		cin >> sBirthday;
		cout << "����" << endl;
		cin >> nLevel;
		switch (nPosition)
		{
		case 1:
			cout << "�������ʣ�" << endl;
			cin >> dBasicwage;
			cout << "��ʱ��" << endl;
			cin >> nClassHours;
			cout << "��ʱ������" << endl;
			cin >> dClassSubsidies;
			F[nCount] = new CTeacher(sName, cSex, sBirthday, sDepartment, sNum, nLevel, nClassHours, dBasicwage, dClassSubsidies, nPosition);
			nTeachercount++;
			cout << "��ӳɹ���" << endl;
			break;
		case 2:
			cout << "�������ʣ�" << endl;
			cin >> dBasicwage;
			cout << "����������" << endl;
			cin >> dAdminiSubsidies;
			F[nCount] = new CAdminiper(sName, cSex, sBirthday, sDepartment, sNum, nLevel, dBasicwage, dAdminiSubsidies, nPosition);
			nAdminipercount++;
			cout << "��ӳɹ���" << endl;
			break;
		case 3:
			cout << "�������ʣ�" << endl;
			cin >> dBasicwage;
			cout << "��ʱ��" << endl;
			cin >> nClassHours;
			cout << "��ʱ������" << endl;
			cin >> dClassSubsidies;
			cout << "����������" << endl;
			cin >> dAdminiSubsidies;
			F[nCount] = new CTeacherAdmini(sName, cSex, sBirthday, sDepartment, sNum, nLevel, nClassHours, dBasicwage, dClassSubsidies, dAdminiSubsidies, nPosition);
			nTeacherAdminicount++;
			cout << "��ӳɹ���" << endl;
			break;
		case 4:
			cout << "�������ʣ�" << endl;
			cin >> dBasicwage;
			F[nCount] = new CRetiree(sName, cSex, sBirthday, sDepartment, sNum, nLevel, dBasicwage, nPosition);
			nRetireecount++;
			cout << "��ӳɹ���" << endl;
			break;
		}
		cout << "�� 0 �˳���������������������" << endl;
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
		cout << "*                 1.��������ѯ        2.�����Ų�ѯ                  *" << endl;
		cout << "*                 3.�����Ų�ѯ        4.�������ѯ                  *" << endl;
		cout << "*                 0.����                                            *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                            ��������Ӧ��ţ�                       *" << endl;
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
				cout << "*************************�������ѯ����********************:" << endl;
				cin >> nNewname;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getName() == nNewname)
					{
						if (nFlag == 0)
						{
							cout << "��ѯ�����" << endl;
							cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
						}
						F[i]->print();
						nFlag = 1;
						
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;
				}

				else
				{
					cout << "�����������!" << endl;
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
				cout << "*************************�������ѯ����********************:" << endl;
				cin >> sNum;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getNum() == sNum)
					{
						if (nFlag == 0)
						{
							cout << "��ѯ�����" << endl;
							cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
						}
						F[i]->print();
						nFlag = 1;
						
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
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
				cout << "*************************�������ѯ����********************:" << endl;
				cin >> sDepartment;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getDepartment() == sDepartment)
					{
						if (nFlag == 0)
						{
							cout << "��ѯ�����" << endl;
							cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
						}
						F[i]->print();
						nFlag = 1;
						
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "�����������!" << endl;
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
				cout << "*************************�������ѯ����********************:" << endl;
				cin >> nLevel;
				nFlag = 0;
				for (i = 0; i < count; i++)
				{
					if (F[i]->getLevel() == nLevel)
					{
						if (nFlag == 0)
						{
							cout << "��ѯ�����" << endl;
							cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
						}
						F[i]->print();
						nFlag = 1;
					}
					
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
					
			}
			break;
		}
		case 0:
			return;
		default:
			cout << "�������󣬰������������������룡" << endl;
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
		cout << "������Ҫ�޸ĵĽ�ְ������:" << endl;
		cin >> sNum;
		for (i = 0; i < count && (F[i]->getNum() != sNum); i++);
		if (i < count)
		{
			while (1)
			{
				system("cls");						
				cout << "*********************************************************************" << endl;
				cout << "*                                                                   *" << endl;
				cout << "*            1.�޸�����              2.�޸Ĺ���                     *" << endl;
				cout << "*            3.�޸��Ա�              4.�޸ĳ�������                 *" << endl;
				cout << "*            5.�޸Ĳ���              6.�޸ļ���                     *" << endl;
				cout << "*            7.�޸Ŀ�ʱ����ʦ��      8.�޸Ļ�������                 *" << endl;
				cout << "*            9.�޸Ŀ�ʱ��������ʦ�� 10.�޸�����������������Ա��     *" << endl;
				cout << "*                              0.����                               *" << endl;
				cout << "*                          ��������Ӧ��ţ�                         *" << endl;
				cout << "*                                                                   *" << endl;
				cout << "*                                                                   *" << endl;
				cout << "*********************************************************************" << endl;
				cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
				F[i]->print();
				cin >> type;
				switch (type)
				{
				case 1:
				{
					string sName;
					cout << "***************************�������µ�����******************:" << endl;
					cin >> sName;
					F[i]->setName(sName);
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�޸ĳɹ���" << endl;
					cout << "�����������" << endl;
					_getch();
				}
				break;
				case 2:
				{
					cout << "*************************�������µĹ���********************:" << endl;
					while (1)
					{
						cin >> sNum;
						if (sNum == "0")
							break;
						if (Valid_Facnum(sNum) == 0)
							cout << "�ù����Ѵ��ڣ�����������(���� 0 ȡ���޸�)��" << endl;
						
						else
						{
							F[i]->setNum(sNum);
							cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
							F[i]->print();
							cout << "�޸ĳɹ���" << endl;
							cout << "�����������" << endl;
							_getch(); 
							break;
						}
					}
				}
				break;
				case 3:
				{
					char cSex;
					cout << "******�������µ��Ա�(�������룺f��F��Ů�����룺m��M)******:" << endl;
					while (1)
					{
						cin >> cSex;
						if (cSex == '0')
							break;
						if (Valid_sex(cSex) == 0)
							cout << "�����������������(���� 0 ȡ���޸�)��" << endl;
						
						else
						{
							F[i]->setSex(cSex);
							cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
							F[i]->print();
							cout << "�޸ĳɹ���" << endl;
							cout << "�����������" << endl;
							_getch();
							break;
						}
					}
					
				}
				break;
				case 4:
				{
					string sBirthday;
					cout << "***********************�������µĳ�������******************:" << endl;
					cin >> sBirthday;
					F[i]->setBirthday(sBirthday);
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�޸ĳɹ���" << endl;
					cout << "�����������" << endl;
					_getch();
				}
				break;
				case 5:
				{
					string sDepartment;
					cout << "*************************�������µĲ���********************:" << endl;
					cin >> sDepartment;
					F[i]->setDepartment(sDepartment);
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�޸ĳɹ���" << endl;
					cout << "�����������" << endl;
					_getch();
				}
				break;
				case 6:
				{
					int nLevel;
					cout << "*************************�������µļ���********************:" << endl;
					cin >> nLevel;
					F[i]->setLevel(nLevel);
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�޸ĳɹ���" << endl;
					cout << "�����������" << endl;
					_getch();
				}
				break;
				case 7:
					F[i]->setClassHours();
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�����������" << endl;
					_getch();
					break;
				case 8:
				{
					double dBasicwage;
					cout << "***********************�������µĻ�������******************:" << endl;
					cin >> dBasicwage;
					F[i]->setBasicWage(dBasicwage);
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�޸ĳɹ���" << endl;
					cout << "�����������" << endl;
					_getch();
				}
				break;
				case 9:
					F[i]->setClassSubsidies();
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�����������" << endl;
					_getch();
					break;
				case 10:
					F[i]->setAdminiSubsidies();
					cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
					F[i]->print();
					cout << "�����������" << endl;
					_getch();
					break;
				case 0:
					return;
				default:
					cout << "�������󣬰������������������룡" << endl;
					_getch();
				}
			}
		}
		else
		{
			cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
			cout << "�� 0 ���أ��������������������" << endl;
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
		cout << "*                   1.������ɾ��        2.������ɾ��                *" << endl;
		cout << "*                   3.������ɾ��        0.����                      *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                            ��������Ӧ��ţ�                       *" << endl;
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
				cout << "*************************������ɾ������********************:" << endl;
				cin >> sName;
				for (i = 0; i < nCount; i++)
				{
					if (F[i]->getName() == sName)
					{
						nFlag = 1;
						cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�";
						cout << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
						F[i]->print();
						cout << "ȷ���Ƿ����ɾ����������y/n" << endl;
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
							cout << "ɾ���ɹ�" << endl;
						}
						else
							cout << "��������ɾ��������" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
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
				cout << "*************************������ɾ������********************:" << endl;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (F[i]->getNum() == sNum)
					{
						nFlag = 1;
						cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�";
						cout << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
						F[i]->print();
						cout << "ȷ���Ƿ����ɾ����������y/n" << endl;
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
							cout << "ɾ���ɹ�" << endl;
						}
						else
							cout << "��������ɾ��������" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
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
				cout << "***************************�����벿��**********************:" << endl;
				cin >> sDepartment;
				for (i = 0; i < nCount; i++)
				{
					if (F[i]->getDepartment() == sDepartment)
					{
						nFlag = 1;
						cout << setw(12) << "����" << setw(12) << "����" << setw(9) << "����" << setw(9) << "�Ա�";
						cout << setw(15) << "��������" << setw(9) << "����" << setw(9) << "����" << endl;
						F[i]->print();
						cout << "ȷ���Ƿ����ɾ����������y/n" << endl;
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
							cout << "ɾ���ɹ�" << endl;
						}
						else
							cout << "��������ɾ��������" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
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
			cout << "�������󣬰������������������룡" << endl;
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
		cout << "������ѧ��������Σ���1���о��� �� 2�������� �� 3��ר���� �� 0��ȡ�� ��" << endl;
		while (1)
		{
			cin >> cEduLevel;
			if (cEduLevel != '1' && cEduLevel != '2' && cEduLevel != '3' && cEduLevel != '0')
				cout << "�������������ѡ��" << endl;
			else if (cEduLevel == '0')
				return;
			else
				break;
		}
		cout << "�༶��" << endl;
		cin >> sClass;
		cout << "ѧ�ţ�" << endl;
		while (1)
		{
			cin >> sNum;
			if (Valid_Stunum(sNum) == 1)
				break;
			else
				cout << "��ѧ���Ѵ��ڣ����������룺" << endl;
		}
		cout << "������" << endl;
		cin >> sName;
		cout << "�Ա�(�������룺f��F��Ů�����룺m��M)" << endl;
		while (1)
		{
			cin >> cSex;
			if (Valid_sex(cSex) == 0)
				cout << "����������������룺" << endl;
			else
				break;
		}
		cout << "�������ڣ�" << endl;
		cin >> sBirthday;
		switch (cEduLevel)
		{
		case '1':
			S[nCount] = new CJuniorstu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
			nGraduatestucount++;
			cout << "��ӳɹ���" << endl;
			break;
		case '2':
			S[nCount] = new CUndergrastu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
			nUndergrastucount++;
			cout << "��ӳɹ���" << endl;
			break;
		case '3':
			S[nCount] = new CGraduatestu(sClass, sNum, sName, cSex, sBirthday, cEduLevel);
			nJuniorstucount++;
			cout << "��ӳɹ���" << endl;
			break;
		}
		cout << "�� 0 �˳���������������������:" << endl;
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
		cout << "*                   1.��������ѯ        2.��ѧ�Ų�ѯ                *" << endl;
		cout << "*                   3.���༶��ѯ        0.����                      *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                            ��������Ӧ��ţ�                       *" << endl;
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
				cout << "*************************�������ѯ����********************:" << endl;
				nFlag = 0;
				cin >> sName;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getName() == sName)
					{
						if (nFlag == 0)
						{
							cout << "��ѯ�����" << endl;
							cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
						}
						S[i]->printinf();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ���������ѧ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				cout << "*************************�������ѯѧ��********************:" << endl;
				nFlag = 0;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getNum() == sNum)
					{
						if (nFlag == 0)
						{
							cout << "��ѯ�����" << endl;
							cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
						}
						S[i]->printinf();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ���������ѧ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 3:
			while (1)
			{
				system("cls");
				cout << "*************************�������ѯ�༶********************:" << endl;
				nFlag = 0;
				cin >> sClass;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getClass() == sClass)
					{
						if (nFlag == 0)
						{
							cout << "��ѯ�����" << endl;
							cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
						}
						S[i]->printinf();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ���������ѧ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;
				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 0:
			return;
		default:
			cout << "�����������������룡" << endl;
		}
	}
}

void CPersonnelManage::updateStudent()
{
	int i,nType;
	int nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	string sNum;
	system("cls");
	cout << "������Ҫ�޸ĵ�ѧ��ѧ��:" << endl;
	cin >> sNum;
	for (i = 0; i< nCount && (S[i]->getNum() != sNum); i++);
	if (i < nCount)
	{
		
		while (1)
		{
			system("cls");
			cout << "*********************************************************************" << endl;
			cout << "*                                                                   *" << endl;
			cout << "*                      1.�޸�����       2.�޸�ѧ��                  *" << endl;
			cout << "*                      3.�޸��Ա�       4.�޸ĳ�������              *" << endl;
			cout << "*                      5.�޸İ༶       0.����                      *" << endl;
			cout << "*                                                                   *" << endl;
			cout << "*                            ��������Ӧ��ţ�                       *" << endl;
			cout << "*                                                                   *" << endl;
			cout << "*********************************************************************" << endl;	
			cout << setw(12)<<"�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
			S[i]->printinf();
			cin >> nType;
			switch (nType)
			{
			case 1:
				{
					string sName;
					cout << "*********************�������µ�����************************:" << endl;
					cin >> sName;
					S[i]->setName(sName);
					cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
					S[i]->printinf();
					cout << "�޸ĳɹ���" << endl;
					cout << "�����������" << endl;
					_getch();
				}break;
			case 2:
			{
				cout << "**********************�������µ�ѧ��***********************:" << endl;
				while (1)
				{
					cin >> sNum;
					if (sNum == "0")
						break;
					if(Valid_Stunum(sNum) == 0)
						cout << "��ѧ���Ѵ��ڣ�����������(���� 0 ȡ���޸�)��" << endl;
					
					else
					{
						S[i]->setNum(sNum);
						cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
						S[i]->printinf();
						cout << "�޸ĳɹ���" << endl;
						cout << "�����������" << endl;
						_getch();
						break;
					}
				}
			}
			break;
			case 3:
			{
				char cSex;
				cout << "**********************�������µ��Ա�***********************:" << endl;
				while (1)
				{
					cin >> cSex;
					if (cSex == '0')
						break;
					if (Valid_sex(cSex) == 0)
						cout << "�����������������(���� 0 ȡ���޸�)��" << endl;
					else
					{
						S[i]->setSex(cSex);
						cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
						S[i]->printinf();
						cout << "�޸ĳɹ���" << endl;
						cout << "�����������" << endl;
						_getch();
						break;
					}
				}
			}
			break;
			case 4:
			{
				string sBirthday;
				cout << "**********************�������µĳ�������***********************:" << endl;
				cin >> sBirthday;
				S[i]->setBirthday(sBirthday);
				cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
				S[i]->printinf();
				cout << "�޸ĳɹ���" << endl;
				cout << "�����������" << endl;
				_getch();
			}break;
			case 5:
			{
				string sClass;
				cout << "**********************�������µİ༶***********************:" << endl;
				cin >> sClass;
				S[i]->setClass(sClass);
				cout << setw(12) << "�༶" << setw(12) << "ѧ��" << setw(9) << "����" << setw(9) << "�Ա�" << setw(15) << "��������" << endl;
				S[i]->printinf();
				cout << "�޸ĳɹ���" << endl;
				cout << "�����������" << endl;
				_getch();
			}break;
			case 0:
				return;
			default:
				cout << "����������������룺" << endl;
			}
		}
	}
	else cout << "�����ڷ���������ѧ����¼��" << endl;
	cout << "�����������:" << endl;
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
		cout << "*                  1.������ɾ��        2.��ѧ��ɾ��                 *" << endl;
		cout << "*                  3.���༶ɾ��        0.����                       *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                          ��������Ӧ��ţ�                         *" << endl;
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
				cout << "*************************������ɾ������********************:" << endl;
				cin >> sName;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getName() == sName)
					{
						nFlag = 1;
						S[i]->printinf();
						cout << "ȷ���Ƿ����ɾ����������y/n" << endl;
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
							cout << "ɾ���ɹ�" << endl;
						}
						else
							cout << "��������ɾ��������" << endl;
					}

				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
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
				cout << "*************************������ɾ��ѧ��********************:" << endl;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getNum() == sNum)
					{
						nFlag = 1;
						S[i]->printinf();
						cout << "ȷ���Ƿ����ɾ����������y/n" << endl;
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
							cout << "ɾ���ɹ�" << endl;
						}
						else
							cout << "��������ɾ��������" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
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
				cout << "*************************������ɾ���༶********************:" << endl;
				cin >> sClass;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getClass() == sClass)
					{
						nFlag = 1;
						S[i]->printinf();
						cout << "ȷ���Ƿ����ɾ����������y/n" << endl;
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
							cout << "ɾ���ɹ�" << endl;
						}
						else
							cout << "��������ɾ��������" << endl;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ��������Ľ�ְ����Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
			}
			break;
		
		case 0:
			return;
		default:
			cout << "�����������������룡" << endl;
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
	cout << "************************������ѧ��************************��" << endl;
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
			cout << "û�д�ѧ�������������룺" << endl;
	}
	while (1)
	{
		cout << "������Ҫ¼��Ŀ�Ŀ��" << endl;
		while (1)
		{
			cin >> sCourse;
			if (S[i]->Valid_Course(sCourse) == 1)
				break;
			else
				cout << "�˿�Ŀ�Ѵ��ڣ����������룺" << endl;
		}
		cout << "������Ҫ¼��ķ�����" << endl;
		cin >> nScore;
		cout << "�������µ�ѧ�֣�" << endl;
		cin >> nCredit;
		S[i]->entergrade(sCourse, nScore,nCredit);
		S[i]->printgrade();
		cout << "¼��ɹ��������������¼�룬�˳��밴0��" << endl;
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
		cout << "*                  1.��������ѯ        2.��ѧ�Ų�ѯ                 *" << endl;
		cout << "*                  3.���༶��ѯ        0.����                       *" << endl;
		cout << "*                                                                   *" << endl;
		cout << "*                         ��������Ӧ��ţ�                          *" << endl;
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
				cout << "***********************�������ѯ����***********************:" << endl;
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
					cout << "�����ڷ���������ѧ���ɼ���Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 2:
			while (1)
			{
				system("cls");
				cout << "***********************�������ѯѧ��**********************:" << endl;
				nFlag = 0;
				cin >> sNum;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getNum() == sNum)
					{
						if (nFlag == 0)
							cout << "�ɼ���" << endl;
						S[i]->printgrade();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ���������ѧ���ɼ���Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 3:
			while (1)
			{
				system("cls");
				cout << "***********************�������ѯ�༶**********************:" << endl;
				nFlag = 0;
				cin >> sClass;
				for (i = 0; i < nCount; i++)
				{
					if (S[i]->getClass() == sClass)
					{
						if (nFlag == 0)
							cout << "�ɼ���" << endl << endl;
						S[i]->printgrade();
						nFlag = 1;
					}
				}
				if (nFlag == 0)
				{
					cout << "�����ڷ���������ѧ���ɼ���Ϣ��" << endl;
					cout << "�� 0 ���أ��������������������" << endl;
					if (_getch() == '0')
						break;

				}
				else
				{
					cout << "�����������!" << endl;
					_getch();
					break;
				}
			}
			break;
		case 0:
			return;
		default:
			cout << "�����������������룡" << endl;
			_getch();
		}
	}
}

void CPersonnelManage::updategrade()
{
	int i,nScore,nCredit,nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	string sCourse;
	cout << "������Ҫ�޸ĳɼ���ѧ��ѧ�ţ�" << endl;
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
			cout << "��ѧ�Ų����ڣ����������룺" << endl;
	}
	while(1)
	{
		cout << "��������Ҫ�޸ĵĿ�Ŀ��" << endl;
		cin >> sCourse;
		if (S[i]->Valid_Course(sCourse) == 1)
			cout << "�˿�Ŀ�����ڣ������������¼�룬�˳��밴0��" << endl;
		else
		{
			cout << "�������µķ�����" << endl;
			cin >> nScore;
			cout << "�������µ�ѧ�֣�" << endl;
			cin >> nCredit;
			S[i]->setgrade(sCourse, nScore,nCredit);
			cout << "�޸ĳɹ��������������¼�룬�˳��밴0��" << endl;
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
	cout << "������༶��" << endl;
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
		cout << setw(5) << "��" << i + 1 << "��" << endl;
		a[i]->printgrade();
		for (int p = 0; p < nCount; p++)
		{
			if (S[p]->getNum() == a[i]->getNum())
				S[p]->setRank(i+1);
		}
	}
	cout << "�����������" << endl;
	_getch();
}

void CPersonnelManage::deletegrade()
{
	int i, nCount = nJuniorstucount + nUndergrastucount + nGraduatestucount;
	string sCourse;
	cout << "������Ҫɾ���ɼ���ѧ��ѧ�ţ�" << endl;
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
			cout << "��ѧ�Ų����ڣ����������룺" << endl;
	}
	while (1)
	{
		cout << "��������Ҫɾ���Ŀ�Ŀ��" << endl;
		string sCourse;
		cin >> sCourse;
		if (S[i]->Valid_Course(sCourse) == 1)
			cout << "�˿�Ŀ�����ڣ���������������룬�˳��밴0��" << endl;
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
	cout << "*                        ��ӭʹ��У԰��Ϣ����ϵͳ                   *" << endl;
	cout << "*                 1.��ְ����Ϣ                2.ѧ����Ϣ            *" << endl;
	cout << "*                              0.�˳�ϵͳ                           *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                            ��������Ӧ���                         *" << endl;
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
	cout << "*                       ��ӭʹ�ý�ְ����Ϣ����ϵͳ                  *" << endl;
	cout << "*                 1.��ӽ�ְ����Ϣ      2.��ѯ��ְ����Ϣ            *" << endl;
	cout << "*                 3.�޸Ľ�ְ����Ϣ      4.ɾ����ְ����Ϣ            *" << endl;
	cout << "*                                 0.����                            *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                               ��������Ӧ���                      *" << endl;
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
	cout << "*                       ��ӭʹ��ѧ����Ϣ����ϵͳ                    *" << endl;
	cout << "*                1.���ѧ����Ϣ          2.��ѯѧ����Ϣ             *" << endl;
	cout << "*                3.�޸�ѧ����Ϣ          4.ɾ��ѧ����Ϣ             *" << endl;
	cout << "*                5.¼��ѧ���ɼ�          6.��ѯѧ���ɼ�             *" << endl;
	cout << "*                7.�޸�ѧ���ɼ�          8.ɾ��ѧ���ɼ�             *" << endl;
	cout << "*                9.�༶����              0.����                     *" << endl;
	cout << "*                                                                   *" << endl;
	cout << "*                             ��������Ӧ��ţ�                      *" << endl;
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
		cout << "���ļ�ʧ�ܣ�" << endl;
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
		cout << "�򿪳ɼ��ļ�ʧ�ܣ�" << endl;
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
		cout << "���ļ�ʧ�ܣ�" << endl;
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
		cout << "�򿪳ɼ��ļ�ʧ�ܣ�" << endl;
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




