/**************************************************
> File Name: argc.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月13日 星期五 11时17分27秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s num1 num2 \n",argv[0]);
		return 0;
	}
	int sum = 0,a=0,b=0;
	a=argv[1];
	b=argv[2];
	sum=a+b;
	printf("sum = %d \n",sum);
    return 0;
}
