/* ************************************************************************
	> File Name: test.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 13时43分24秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 10000

int bubble(int a[], int size);
int * input(void);

int main(int argc, const char *argv[])
{
	int * a = input();
	bubble(a, N);
	free(a);
    return 0;
}

int * input(void)
{
	int * p = (int *)malloc(sizeof(int)*N);
	if (NULL == p)		return NULL;
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < N; i++)
	{
		p[i] = rand() % 1000000;
	}
	return p;
}

int bubble(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = 0, j = 0, swap = 0;
	for (i = 0; i < size-1; i++)
	{
		for (j = 0; j < size-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				swap = a[j];
				a[j] = a[j+1];
				a[j+1] = swap;
			}
		}
	}
	return 0;
}

