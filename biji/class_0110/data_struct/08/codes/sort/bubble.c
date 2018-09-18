/* ************************************************************************
	> File Name: bubble.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 11时50分38秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int output(int a[], int size);
int bubble(int a[], int size);

int main(int argc, const char *argv[])
{
	int a[] = {9,8,7,6,5,4,3,2,1,0};
	bubble(a, ARRAY_SIZE(a));
	output(a, ARRAY_SIZE(a));
    return 0;
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

int output(int a[], int size)
{
	if (NULL == a)		return -1;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


