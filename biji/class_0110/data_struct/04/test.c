/* ************************************************************************
	> File Name: test.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月16日 星期四 10时30分10秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	unsigned long src = 0;
	while (1)
	{
		system("stty -echo");
		while (scanf("%d", &src) != 1)
		{
			while (getchar() != '\n');
			break;
		}
		system("stty echo");
		if (123456 == src)
			break;
	}
    return 0;
}
