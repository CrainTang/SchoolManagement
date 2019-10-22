// SchoolManagesystem.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Personnel.h"
#include"PersonnelManage.h"
#include"conio.h"
int main()
{
	CPersonnelManage e; //人员管理对象
	e.read();			//读取信息
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
					e.addFaculty();			//添加教职工信息
					break;
				case 2:
					e.searchFaculty();		//查询教职工信息
					break;
				case 3:
					e.updateFaculty();		//修改教职工信息
					break;
				case 4:
					e.deleteFaculty();		//删除教职工信息
					break;
				case 0:
					n = 0;					//返回上一级菜单
					break;
				default:
					cout << "输入有误，按任意键清除并重新输入！" << endl;
					_getch();
				}
				e.save();					//存入信息
			}

			break;
		case 2:
			while (n)
			{
				switch (e.stumenu())
				{
				case 1:
					e.addStudent();			//添加学生基本信息
					break;
				case 2:
					e.searchStudent();		//查询学生基本信息
					break;
				case 3:
					e.updateStudent();		//修改学生基本信息
					break;
				case 4:
					e.deleteStudent();		//删除学生基本信息
					break;
				case 5:
					e.entergrade();			//录入学生成绩
					break;
				case 6:
					e.searchgrade();		//查询学生成绩
					break;
				case 7:
					e.updategrade();		//修改学生成绩
					break;
				case 8:
					e.deletegrade();		//删除学生成绩
					break;
				case 9:
					e.gradeorder();			//班级排名
					break;
				case 0:
					n = 0;					//返回上一级菜单
					break;
				default:
					cout << "输入有误，按任意键清除并重新输入！" << endl;
					_getch();
				}
				e.save();					//存入信息
			}
			break;
		case 0:
			exit(0);						//退出程序
		default:
			cout << "输入有误，按任意键清除并重新输入！" << endl;
			_getch();
		}
	}
    return 0;
}

