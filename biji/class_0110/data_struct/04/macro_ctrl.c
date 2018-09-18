/* ************************************************************************
	> File Name: macro_ctrl.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月16日 星期四 14时31分28秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

#define DEBUG 1
/* 宏值控制的条件编译 */

int main(int argc, const char *argv[])
{
#if DEBUG
	printf("hello world\n");
#endif
    return 0;
}



