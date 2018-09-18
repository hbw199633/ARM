/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：reload2.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;

int  test(long long a,long long b)
{
	return 3;
}
int test(int a ,int b)
{
	return 1;
}

int  test(short a,short b)
{
	return 2;
}

/*
int  test(float a,float b)
{
	return 5;
}
int  test(double a,double b)
{
	return 4;
}
*/

int  main(int argc, char *argv[])
{
	
	//int ret = test(100l,200l);
	//int ret = test(100.1f,200.2f);
	//int ret = test(100,200);   ///默认是int类型
	//int ret = test((short)100,(short)200);
	
	//int ret = test(3.14 ,5.67);

	long long  x = 10,y = 20;
	int ret = test(x,y);

	cout << "ret =" << ret << endl;

    return 0;
}

