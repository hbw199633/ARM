/***************************************************
> Copyright (C) 2017 ==HEBOWEN== All rights reserved.
> File Name: charu.c
> Author: hebowen
> Mail:982034166@qq.com 
> Created Time: 2017年06月29日 星期四 19时14分44秒
***************************************************/

#include <stdio.h>
#define MAX sizeof(a)/sizeof(a[0])

int insert_sort(int a[],int size)
{
	int t = 0,i = 0,j = 0;
	for(i = 1;i < size;i++)
	{
		t = a[i];
		for(j = i;((j > 0) && (a[j-1] > t));j--)
		{
			a[j] = a[j-1];
		}
		a[j] = t;
	}
}

int main(int argc,const char* argv[])
{
	int i = 0;
	int	a[] = {50,36,66,76,95,12,25,36};
	insert_sort(a,MAX);
	for(i = 0;i < MAX;i++)
		printf("%d ",a[i]);
	printf("\n");
	
    return 0;
}
