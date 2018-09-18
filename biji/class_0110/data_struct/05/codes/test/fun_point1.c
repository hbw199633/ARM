/* ************************************************************************
	> File Name: fun_point1.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月17日 星期五 17时00分16秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

/* 定义函数指针
 * */

int main(int argc, const char *argv[])
{
	/* 定义一个指针 */
	int (*show)(const char *, ...) = (void *)printf;
	show("hello world\n");
	int a = 10;
	show("a:%d\n", a);
    return 0;
}




