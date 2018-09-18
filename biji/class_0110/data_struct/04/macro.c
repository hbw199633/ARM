/* ************************************************************************
	> File Name: macro.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月16日 星期四 14时24分37秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	printf("%s\n", __FILE__);	/* 文件名 */
	printf("%d\n", __LINE__);	/* 行号 */
	printf("%s\n", __func__);	/* 函数名 */
    return 0;
}

