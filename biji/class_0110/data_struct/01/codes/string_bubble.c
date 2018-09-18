/* ************************************************************************
	> File Name: string_bubble.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月14日 星期二 09时18分07秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int main(int argc, const char *argv[])
{
	char *p[] = {"hello", "world", "good", "this", "well", "best"};
	int i = 0, j = 0;
	char * tmp = NULL;
	for (i = 0; i < ARRAY_SIZE(p)-1; i++)
	{
		for (j = 0; j < ARRAY_SIZE(p)-i-1; j++)
		{
			if (strcmp(p[j], p[j+1]) > 0)
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
		}
	}
	for (i = 0; i < ARRAY_SIZE(p); i++)
	{
		printf("%s\n", p[i]);
	}
    return 0;
}




