/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：inline.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;

#define  max_fun(a,b) {a>b?a:b}

inline int  max_test(int a,int b)
{
	if(a > b)  return a;
	else	   return b;
}

int main(int argc, char *argv[])
{
	int a = 0,b = 0;
	cout <<"input 2 num" << endl;
	cin >> a >> b;
	int c = max_test(a,b);
//	int c = max_fun(a,b);
	cout << "max num =" << c <<endl;

    return 0;
}

