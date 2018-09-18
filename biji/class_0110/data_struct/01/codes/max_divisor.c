/* ************************************************************************
	> File Name: divisor.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月13日 星期一 13时53分15秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int num1 = 0, num2 = 0 ,i = 0;
	printf("Please input two int num\n");
	scanf("%d%d", &num1, &num2);
	int min = num1 < num2 ? num1 : num2;
	for (i = min; i > 0; i--)		/* n */
	{
		if ((num1 % i == 0) && (num2 % i == 0))
			break;
	}
	printf("i:%d\n", i);
    return 0;
}



