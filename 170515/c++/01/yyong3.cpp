/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：yyong3.cpp
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年08月07日
*   描    述：
================================================================*/
#include <iostream>

using namespace std;

int swap_int(int *pa,int *pb)
{
	int c = *pa;
	*pa = *pb;
	*pb = c;
	return  0;
}
int swap_int2(int &ra,int &rb)
{
	int c = ra;
	ra = rb;
	rb = c;
	return  0;
}
int main(int argc, char *argv[])
{
	int a = 0,b = 0;
	cout << "input 2 int" << endl;
	cin >> a >> b;
	cout << "swap a =" << a  << " b= " << b <<endl;
	swap_int (&a,&b);
	cout << "swap2 a =" << a  << " b= " << b <<endl;
//	swap_int2(a,b);
	int &ca = a;
	int &cb = b;
	swap_int2(ca,cb);
	cout << "swap3 a =" << a  << " b= " << b <<endl;

    return 0;
}

