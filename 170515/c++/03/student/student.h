/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：student.h
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月13日
*   描    述：
================================================================*/

#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <string>

using namespace std;

class  student
{
	private :
		int 	id;
		string  name;
		float	score;
	public:
		int     set_name(string n);
		string  get_name();
};



#endif 
