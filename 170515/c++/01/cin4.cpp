/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：cin4.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;
int main(int argc, char *argv[])
{

	char buff[128] ={0};

	cout <<"input string.... " <<endl;

	cin.getline(buff,sizeof(buff));

	cout <<"output string ="<< buff  << endl;

    return 0;
}

