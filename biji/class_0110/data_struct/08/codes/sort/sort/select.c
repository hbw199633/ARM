/* ************************************************************************
	> File Name: choice.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 14时35分43秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define N 100000

int * input(void);
int choice(int a[], int size);
int output(int a[], int size);

int main(int argc, const char *argv[])
{
	int * arr = input();
	choice(arr, N);
	output(arr, N);
	free(arr);

    return 0;
}

int * input(void)
{
	int * p = (int *)malloc(sizeof(int)*N);
	if (NULL == p)		return NULL;
	srand(time(NULL));
	int i = 0;
	for (i = 0; i < N; i++)
	{
		p[i] = rand() %(N*100);
	}
	return p;
}

int choice(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = 0, j = 0, min = 0;
	for (i = 0; i < size-1; i++)
	{
		min = i;
		for (j = i+1; j < size; j++)
		{
			if (a[j] < a[min])	min = j;
		}
		if (min != i)
		{
			a[i] = a[min] ^ a[i];
			a[min] = a[min] ^ a[i];
			a[i] = a[min] ^ a[i];
		}
	}
	return 0;
}

int output(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

/* & | ~ ^ << >>
 * */

