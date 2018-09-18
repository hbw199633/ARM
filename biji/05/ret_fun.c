/**************************************************
> File Name: ret_fun.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月14日 星期六 14时39分14秒
**************************************************/

#include <stdio.h>
#include <stdlib.h>

int add(int a,int b)
{
	int sum = 0;
	sum = a + b;
	return sum;
}

int sub(int a,int b)
{
	int sub = 0;
	sub = a - b;
	return sub;
}

int mul(int a,int b)
{
	int mul = 0;
	mul = a * b;
	return mul;
}

int divi(int a,int b)
{
	int divi = 0;
	if(b==0)
		return 0;
	else
		divi = a / b;
	return divi;
}

int main(int argc,const char* argv[])
{
	if(argc != 3)
	{
		printf("Usage:%s num1 num2 \n",argv[0]);
		return 0;
	}
	printf("add = %d\n",add(atoi(argv[1]),atoi(argv[2])));
	printf("sub = %d\n",sub(atoi(argv[1]),atoi(argv[2])));
	printf("mul = %d\n",mul(atoi(argv[1]),atoi(argv[2])));
	printf("div = %d\n",divi(atoi(argv[1]),atoi(argv[2])));

	return 0;
}
