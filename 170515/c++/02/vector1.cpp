/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：vector1.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char *argv[])
{
	vector<int>   a(10) ;

	for(int i = 0;i<10;i++)
	{
		a[i] = 100+i;
	}

	
	cout << "=========================" << endl;

	for(int i = 0;i<10;i++)
	{
		cout << a[i] <<endl; 
	}

	
	
    return 0;
}

