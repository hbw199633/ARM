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
int insert(int a[], int size);
int output(int a[], int size);
int quick(int a[], int low, int high);

int main(int argc, const char *argv[])
{
	int * arr = input();
	quick(arr, 0, N-1);
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

int quick(int a[], int low, int high)
{
	if (NULL == a)		return -1;
	int i = low, j = high, key = a[low];
	while (i < j)
	{
		while ((i < j) && (a[j] >= key))	j--;
		if (i < j)		a[i] = a[j];

		while ((i < j) && (a[i] <= key))	i++;
		if (i < j)		a[j] = a[i];
	}
	a[i] = key;
	if (i-1 > low)		quick(a, low, i-1);
	if (i+1 < high)		quick(a, i+1, high);

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

