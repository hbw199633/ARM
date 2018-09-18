/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：string1.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>
#include <string>

using namespace std;

int test(string a)
{
	cout << "test a =" << a <<endl;
	a = "aaaaaaaa";
	cout <<"test a2  =" << a <<endl;
	return 0;
}


int main(int argc, char *argv[])
{
	string  s1;

	int a ;

	a = 10;

	s1 = "abc";

	cout <<"a = " << a << endl;
	cout << "s =" << s1 <<endl;
	
	s1 = "aslkdjfaslkjfd";

	cout << "s =" << s1 <<endl;

	
	string s2 = "z25482374325";

	cout << "s2  = "  << s2 <<endl;


	string s3 = "nihao";

	test(s3);

	if(s3 > s2)
	{
		cout << "s3 da" <<endl;
	}
	else
	{
		cout << "s2 da" <<endl;
	}

	
	string s4 = s1 + s2 +s3;
	cout << "s4 =" << s4<<endl;




    return 0;
}

