/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：main.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月13日
*   描    述：
================================================================*/
#include <iostream>
#include "student.h"

using namespace std;
int main(int argc, char *argv[])
{

	student stu1;

	stu1.set_name("zhangsan");

	cout<< "stu1 name =" <<stu1.get_name()<<endl;

    return 0;
}

