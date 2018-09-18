/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：vector3.cpp
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

	cout << "a.size = " <<a.size() << endl;
	cout << "a.capacity =" << a.capacity() <<endl;

	a.push_back(100);
	a.push_back(2200);
	a.push_back(300);
	a.push_back(400);
	a.push_back(500);
	a.push_back(500);
	a.push_back(500);
	a.push_back(500);
	a.push_back(500);

	cout << "a.size = " <<a.size() << endl;
	cout << "a.capacity =" << a.capacity() <<endl;

    return 0;
}

