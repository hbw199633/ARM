/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：cin3.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	int a  = 0, b = 0,c = 0;

	cin >> a>> b>> c;

	cout <<"a = " <<a <<endl;
	cout <<"b = " <<b <<endl;
	cout <<"c = " <<c <<endl;

	float a2 = 0;
	char  a3 = 0;
/*
	cin >> a2;
	cin >> a3;
*/
	cin >> a2 ;
	a3 = cin.get();

	cout << "a2 = " << a2 <<endl;
	cout << "a3 = " << a3 <<endl;




    return 0;
}

