/* ************************************************************************
	> File Name: find.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 17时00分10秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int bsearch(int a[], int value, int low, int high);

int main(int argc, const char *argv[])
{
	int a[] = {2, 4, 6, 8, 10, 12, 14, 16, 18};
	int value = 0;
	printf("Please input find value\n");
	scanf("%d", &value);
	printf("%d\n", bsearch(a, value, 0, 8));
    return 0;
}

int bsearch(int a[], int value, int low, int high)
{
	if (NULL == a)			return -1;
	if ((value < a[low]) || (value > a[high]))	return -1;
//	if (low >= high)		return -1;
	int mid = (low + high) / 2, ret = 0;
	if (value == a[mid])	return 1;

	if (value > a[mid])
	{
		ret = bsearch(a, value, mid+1, high);
	}
	if (value < a[mid])
	{
		ret = bsearch(a, value, low, mid-1);
	}
	return ret;
}

