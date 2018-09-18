/* ************************************************************************
	> File Name: register.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 17时07分12秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	register int a = 10;
	printf("a:%d\n", a);
	printf("&a:%p\n", &a);
    return 0;
}

