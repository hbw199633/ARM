/* ************************************************************************
	> File Name: fun_point.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月17日 星期五 16时52分52秒
	> Version: v1.0
 ************************************************************************/
/* 函数指针：
 * 本质：指针, 指向函数的指针
 *
 * 指针函数：
 * 本质：函数，返回值类型为指针的函数
 *
 * 函数名：地址常量		数组名：地址常量
 * */

#include <stdio.h>

void test(void);

int main(int argc, const char *argv[])
{
	int a[10];
	printf("a:%p\n", a);
	printf("test:%p\n", test);
	printf("printf:%p\n", printf);
    return 0;
}

void test(void)
{
	printf("this is %s \n", __func__);
}

