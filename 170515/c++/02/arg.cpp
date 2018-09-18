/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：arg.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int add(int a,int b = 0)
{
	return a + b;
}


int main(int argc, char *argv[])
{
	//int ret = add(5,6);
	//int ret = add(5);
	int ret = add(5,7);
	cout << "ret =" <<ret <<endl;

    return 0;
}

