/**************************************************
> File Name: fun_arr.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月07日 星期二 15时58分36秒
**************************************************/
#include "head.h"

float fun_arv(float src[],int a)
{
	float sum = 0;
	int i =0;
	for(i=0;i<a;i++)
		sum = sum+src[i];
	return sum;
}

int fun_input(float src[],int a)
{
	int i = 0;
	for(i=0;i<a;i++)
		scanf("%f",&src[i]);
}

int fun_output(float arv)
{
	printf("%2.2f\n",arv/5);
}
