/* ************************************************************************
	> File Name: union.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 16时59分59秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

union {
	int a;
	short b;
	char c;
}var;

int main(int argc, const char *argv[])
{
	var.c = 'a';
	printf("var.a:%d var.b:%d va.c:%d\n", var.a, var.b, var.c);
	printf("sizeof(var):%d\n", sizeof(var));
    return 0;
}

