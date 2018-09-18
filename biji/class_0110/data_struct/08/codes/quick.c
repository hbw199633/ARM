/* ************************************************************************
	> File Name: quick.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 16时19分57秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int input(int a[], int size);
int output(int a[], int size);
int quick(int a[], int low, int high);

int main(int argc, const char *argv[])
{
	int a[10];
	input(a, ARRAY_SIZE(a));
	quick(a, 0, ARRAY_SIZE(a)-1);
	output(a, ARRAY_SIZE(a));
    return 0;
}

int input(int a[], int size)
{
	if (NULL == a)		return -1;
	srand(time(NULL));
	int i = 0;
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 1000;
	}
	return 0;
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
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}


