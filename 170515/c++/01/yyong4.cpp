/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：yyong4.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int *pa = NULL;

int test()
{
	cout <<"test..." <<endl;
	return 100;
}

int & test2()
{
	static int a = 10;
	int &ra = a; 
	pa = &a;
	cout << "a = "<< a << "  ra =" << ra << endl; 
	return ra;
}

int main(int argc, char *argv[])
{

	int x = test();
	cout << "test ret x = " << x << endl;
	test2() = 100;
	cout << "*pa = " << *pa <<endl;
	test2() = 200;
	int &rb = test2();
	cout << "rb =" <<rb <<endl;


    return 0;
}

