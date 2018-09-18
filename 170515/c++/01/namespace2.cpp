/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：namespace2.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

namespace std
{
	int a ;
	char b;
}

using namespace std;

int main(int argc, char *argv[])
{
	a = 100;
	b = 'w';

	cout << "a = " << a <<endl;
	cout << "b = " << b <<endl;
	
    return 0;
}

