/* ************************************************************************
	> File Name: select.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 11时57分06秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int output(int a[], int size);
int select(int a[], int size);

int main(int argc, const char *argv[])
{
	int a[] = {9,8,7,6,5,4,3,2,1,0};
	select(a, ARRAY_SIZE(a));
	output(a, ARRAY_SIZE(a));
    return 0;
}

int select(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = 0, j = 0, min = 0, swap = 0;
	for (i = 0; i < size-1; i++)
	{
		min = i;
		for (j = i+1; j < size; j++)
		{
			if (a[j] < a[min])	min = j;
		}
		if (min != i)
		{
			swap = a[i];
			a[i] = a[min];
			a[min] = swap;
		}
	}
	return 0;
}

int output(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = -1;
	while (i++,  i < size)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

