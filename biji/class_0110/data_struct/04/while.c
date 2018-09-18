/* ************************************************************************
	> File Name: while.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月16日 星期四 10时30分41秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 3, b = 3, c = 5;
	int z;
	z = (a++, b += a,  a + b);
	printf("%d\n", z);
	
    return 0;
}
