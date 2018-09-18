/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：zuoye.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月13日
*   描    述：
================================================================*/
#include <iostream>
#include <string>

using namespace std;
int myerror(string s)
{
	cout << "error = " << s << endl;
	return 0;
}

int myerror(string s,int type)
{
	cout << "type =  "<< type <<" error = " << s << endl;
	return 0;
}
int myerror(string s,string s2, int t)
{
	cout << "time = " << t ;
	cout <<" mode = " << s2;
	cout <<" error = " << s << endl;
	return 0;
}


int main(int argc, char *argv[])
{
	myerror("nihao");

	myerror("wohao",5);

	myerror("nihao","wohao",12345);
	
    return 0;
}

