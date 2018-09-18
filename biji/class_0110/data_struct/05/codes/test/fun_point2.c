/* ************************************************************************
	> File Name: fun_point2.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月17日 星期五 17时05分37秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
/* 函数指针数组
 *
 * int *p[10];		// 指针数组 
 *
 * int (*p)[10];	// 数组指针
 *
 * int (*p)(void);	// 函数指针
 *	
 * int * p (void);	// 指针函数
 *	
 * int (*p[10])(void);	// 函数指针数组
 *
 * int p(void);
 *
 * int * p;
 *
 * */

int add(int a, int b);

int main(int argc, const char *argv[])
{
	int (*pfun)(int, int) = add;
	printf("add result:%d\n", pfun(10, 100));
    return 0;
}

int add(int a, int b)
{
	return (a+b);
}

