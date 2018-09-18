/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 09时32分29秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%s\n", argv[i]);
	}
    return 0;
}
