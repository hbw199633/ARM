/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：yyong5.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{
	const char * s = "asdfasdfasf";
//	const char * p = s;
//	const char * &rs = s;

	const char* *p = &s;
	const char ** &rp = p;
	cout << " rp =" << *rp <<endl;
	
//	cout << rs << endl;
//	cout << p  << endl;


    return 0;
}

