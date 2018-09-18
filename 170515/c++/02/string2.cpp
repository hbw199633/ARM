/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：string2.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月12日
*   描    述：
================================================================*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int main(int argc, char *argv[])
{
	string   s1 = "nihao 123 wohao";

	cout <<"s1.length = " << s1.length() <<endl;
	cout <<"s1.size =" << s1.size() << endl;
	cout <<"sizeof s1 =" << sizeof(s1) <<endl;

/*
	s1.clear();
	cout << "s1 clear =" << s1 <<endl;
	
	s1 = "abc";

	s1.erase();
	cout << "s1 clear =" << s1 <<endl;
*/
/*
	int n = s1.find("123",0);
	cout <<"find n =" << n <<endl;

	n = 0;
	n = s1.find("asdf",0);
	cout <<"find n2 =" << n <<endl;
*/
	cout << "s1[0] =" << s1[0] <<endl;
	cout << "s1[1] =" << s1[1] <<endl;
	cout << "s1[2] =" << s1[2] <<endl;

	char buff[16] ={0};

	strcpy(buff,s1.c_str());

	cout << "buff =" << buff <<endl;

	string s2  = "";
	cout << "s2 =" << s2 <<endl;
	s2.append(buff);
	cout << "s2 =" <<s2 <<endl;



    return 0;
}

