// SchoolManagesystem.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include"Personnel.h"
#include"PersonnelManage.h"
#include"conio.h"
int main()
{
	CPersonnelManage e; //��Ա�������
	e.read();			//��ȡ��Ϣ
	int n;
	while (1)
	{
		n = 1;
		switch (e.menu())
		{
		case 1:
			while (n)
			{
				switch (e.facmenu())
				{
				case 1:
					e.addFaculty();			//��ӽ�ְ����Ϣ
					break;
				case 2:
					e.searchFaculty();		//��ѯ��ְ����Ϣ
					break;
				case 3:
					e.updateFaculty();		//�޸Ľ�ְ����Ϣ
					break;
				case 4:
					e.deleteFaculty();		//ɾ����ְ����Ϣ
					break;
				case 0:
					n = 0;					//������һ���˵�
					break;
				default:
					cout << "�������󣬰������������������룡" << endl;
					_getch();
				}
				e.save();					//������Ϣ
			}

			break;
		case 2:
			while (n)
			{
				switch (e.stumenu())
				{
				case 1:
					e.addStudent();			//���ѧ��������Ϣ
					break;
				case 2:
					e.searchStudent();		//��ѯѧ��������Ϣ
					break;
				case 3:
					e.updateStudent();		//�޸�ѧ��������Ϣ
					break;
				case 4:
					e.deleteStudent();		//ɾ��ѧ��������Ϣ
					break;
				case 5:
					e.entergrade();			//¼��ѧ���ɼ�
					break;
				case 6:
					e.searchgrade();		//��ѯѧ���ɼ�
					break;
				case 7:
					e.updategrade();		//�޸�ѧ���ɼ�
					break;
				case 8:
					e.deletegrade();		//ɾ��ѧ���ɼ�
					break;
				case 9:
					e.gradeorder();			//�༶����
					break;
				case 0:
					n = 0;					//������һ���˵�
					break;
				default:
					cout << "�������󣬰������������������룡" << endl;
					_getch();
				}
				e.save();					//������Ϣ
			}
			break;
		case 0:
			exit(0);						//�˳�����
		default:
			cout << "�������󣬰������������������룡" << endl;
			_getch();
		}
	}
    return 0;
}

