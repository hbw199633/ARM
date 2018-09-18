/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：vector2.cpp
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

	for(int i = 0;i<100;i++)
	{
		a.push_back(100+i);
	}
	
	for(int i =0;i<100;i++)
	{
		cout << a[i] <<endl;
	}

	for(int i =0;i<100;i++)
	{
		a.pop_back();
	}


    return 0;
}

