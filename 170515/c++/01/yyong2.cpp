/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：yyong2.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	int a = 100;
	int &ra = a;

	cout << "a addr = " << &a << endl;
	cout << "ra addr = "<< &ra <<endl;

	cout << "a =" << a << " ra =" << ra <<endl;

	int &rb = 100;



    return 0;
}


