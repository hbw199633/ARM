/* ************************************************************************
	> File Name: const.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 16时33分36秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

void test(const int * p);
void test1(int const *p);

int main(int argc, const char *argv[])
{
	/*
	const int a = 10;
	printf("a:%d\n", a);
	*/

	/* const int * p;
	 * int const * p;
	 * int * const p;
	 * const int * const p;
	 * */

	int a = 10, b = 20;
 	int const * p = &a;
	printf("*p:%d\n", *p);
	p = &b;
//	test1(p);
	printf("*p:%d\n", *p);
    return 0;
}

void test(const int * p)
{
	if (NULL == p)		return;
}

void test1(int const *p)
{
	if (NULL == p)		return;
//	* p = 1000;
}

//const int * p  ==== int const * p


