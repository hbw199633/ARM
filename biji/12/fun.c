/**************************************************
> File Name: fun.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月07日 星期二 09时21分47秒
**************************************************/

#include <stdio.h>

int add(int ,int );
int sub(int ,int );
int mul(int ,int );
int div(int ,int );
void printf_out(int a);
void printf_out1(int a);

int add(int a,int b)
{
	return a+b;
}

int sub(int a,int b)
{
	return a-b;
}

int mul(int a,int b)
{
	return a*b;
}

int div(int a,int b)
{
	if(b!=0)
		return a/b;
	else
		return -1;
}

void printf_out(int a)
{
	printf("%d\n",a);
}

void printf_out1(int a)
{
	if(a==-1)
		printf("denominator can't be zero!\n");
	else
		printf("%d\n",a);
}

int main(int argc,const char* argv[])
{
	int i = 0, j = 0,ret = 0;
	scanf("%d %d",&i,&j);
	ret = add(i,j);
	printf_out(ret);
	ret = sub(i,j);
	printf_out(ret);
	ret = mul(i,j);
	printf_out(ret);
	ret = div(i,j);
	printf_out1(ret);
    return 0;
}
