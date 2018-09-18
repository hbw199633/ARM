/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：vector4.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
	vector<int>  a;

	for(int i = 0;i<10;i++)
	{
		a.push_back(100+i);
	}

	vector<int>::iterator it;
	for(it = a.begin();it != a.end();it++)
	{
		cout << "*it =" << *it <<endl;
	}


	for(int i=0;i<10;i++)
	{
		a.pop_back();
	}
	
    return 0;
}

