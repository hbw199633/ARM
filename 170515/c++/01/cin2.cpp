/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：cin2.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	int a = 0;

	cin >> a ;

	if(cin.fail())
		cout <<"input error" <<endl;
	else
		cout <<"input a = " << a << endl;


    return 0;
}


