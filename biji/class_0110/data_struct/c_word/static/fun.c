/* ************************************************************************
	> File Name: fun.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 17时12分51秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int a;
static void fun(void)
{
	printf("this is %s\n", __func__);
}

