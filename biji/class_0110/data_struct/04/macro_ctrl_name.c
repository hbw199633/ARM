/* ************************************************************************
	> File Name: macro_ctrl_name.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月16日 星期四 14时40分48秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

#define DEBUG
/* 宏名控制的条件编译 */

#undef DEBUG

int main(int argc, const char *argv[])
{
#ifdef DEBUG
	printf("hello world\n");
#endif

    return 0;
}

