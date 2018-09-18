/* ************************************************************************
	> File Name: string_bubble_fun.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月14日 星期二 09时25分51秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int show_string(char * p[], int size);
int string_bubble(char *p[], int size);

int main(int argc, const char *argv[])
{
	char *p[] = {"hello", "world", "this", "good", "well", "best"};
	string_bubble(p, ARRAY_SIZE(p));
	show_string(p, ARRAY_SIZE(p));
    return 0;
}

int string_bubble(char *p[], int size)
{
	if (NULL == p)		return -1;
	int i = 0, j = 0;
	char * tmp = NULL;
	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-1-i; j++)
		{
			if (strcmp(p[j], p[j+1]) > 0)
			{
				tmp = p[j];
				p[j] = p[j+1];
				p[j+1] = tmp;
			}
		}
	}
	return 0;
}

int show_string(char * p[], int size)
{
	if (NULL == p)		return -1;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%s\n", p[i]);
	}
	return 0;
}

