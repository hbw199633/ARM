/* ************************************************************************
	> File Name: static.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 17时10分20秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int i;
extern a;
extern void fun(void);

int main(int argc, const char *argv[])
{
	printf("i:%d\n", i);
	printf("a:%d\n", a);
	fun();
    return 0;
}

