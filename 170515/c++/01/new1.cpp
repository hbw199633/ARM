/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：new1.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	int *pa = new int;
	if(NULL == pa)
	{
		cout << "new error" <<endl;
		return -1;
	}
	*pa = 100;
	cout << "*pa = " << *pa << endl;

	delete  pa;

	int *pb = new int[10];
	if(NULL == pb)
	{
		cout << "new error" <<endl;
		return -1;
	}
	for(int i = 0;i<10;i++)
	{
		*pb = i+100;
		pb++;
	}

	for(int i=9 ;i>= 0;i--)
	{
		pb--;
		cout << "*pb = " << *pb <<endl;
	}

	delete [] pb;


    return 0;
}

