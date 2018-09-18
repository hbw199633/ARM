/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：cout2.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	int a = 0x3f;

	cout << dec << a <<endl;

	cout << hex << a << endl;

	cout << oct << a << endl;
	
/*
	cout.setf( ios::dec );

	cout << a << endl;

	cout.unsetf(ios::dec);

	cout.setf(ios::hex);

	cout << a <<endl;
*/

    return 0;
}

