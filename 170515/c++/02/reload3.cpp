/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：reload3.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
/*
char max_test(char a,char b)
{
	if(a > b)  return a;
	else	   return b;
}

short max_test(short a,short b)
{
	if(a > b)  return a;
	else	   return b;
}

int max_test(int a,int b)
{
	if(a > b)  return a;
	else	   return b;
}

long max_test( long a,long b)
{
	if(a > b)  return a;
	else	   return b;
}
*/

template <class T>

T max_test(T a , T b)
{
	if(a > b)   return a;
	else 		return b;
}

int main(int argc, char *argv[])
{

	int ret = max_test(100,200);
	//char ret = max_test('z','a');
	cout << "max test = " << ret <<endl;

    return 0;
}

