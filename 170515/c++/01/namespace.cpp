/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：namespace.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;

namespace  myspace
{
	int  a ;
	char b ;
	char *c ;

	int test()
	{
		cout << "test"  <<endl;
	}

}



//using namespace myspace;

int main(int argc, char *argv[])
{
	 myspace ::a= 100;
	 myspace ::b='x';
//	 c = "nihao";

	cout << "a = " <<myspace::a << endl;
	cout << "b = " <<myspace::b << endl;
//	cout << "c = " <<c << endl;


    return 0;
}

