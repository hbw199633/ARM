/* ************************************************************************
	> File Name: insert.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 15时34分55秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int input(int a[], int size);
int insert(int a[], int size);
int output(int a[], int size);

int main(int argc, const char *argv[])
{
	int a[10];
	input(a, ARRAY_SIZE(a));
	insert(a, ARRAY_SIZE(a));
	output(a, ARRAY_SIZE(a));
    return 0;
}

int input(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		a[i] = rand() % 1000;
	}
	return 0;
}

int insert(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = 0, j = 0, t = 0;
	for (i = 1; i < size; i++)
	{
		t = a[i];
		for (j = i; (j > 0) && (a[j-1] > t); j--)
		{
			a[j] = a[j-1];
		}
		a[j] = t;
	}
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





