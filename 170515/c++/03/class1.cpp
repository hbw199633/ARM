/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：class1.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月13日
*   描    述：
================================================================*/
#include <iostream>
#include <string>
using namespace std;

class  student
{
	public:
		int  	id;
		string  name;
		float 	score;
	public:
		int  show()
		{
			cout << "woshi yige student" <<endl;
		}
		int  study()
		{
			cout << "wo zai study" <<endl;
		}
};



int main(int argc, char *argv[])
{

	class student  stu1;
	student *pstu = &stu1;
	
	cout << "stu1 size =" << sizeof(stu1) <<endl;

	stu1.id = 100;
	stu1.name = "zhangsan";

	cout << "stu1.id =" << stu1.id <<endl;
	cout << "stu1.name =" << stu1.name <<endl;

	stu1.show();

	stu1.study();

cout <<"pstu id =" <<pstu->id <<endl;
cout <<"pstu name =" <<pstu->name <<endl;

	pstu->show();
	pstu->study();



    return 0;
}

