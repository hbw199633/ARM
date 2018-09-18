/**************************************************
> File Name: quanju.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月07日 星期二 16时59分37秒
**************************************************/

#include <stdio.h>

int x;

int input_mode	(int *pa,int *pb);
int add_mode	(int a,int b);
int sub_mode	(int a,int b);
int output_mode	(int a);

int input_mode(int *pa,int *pb)
{
	if(!x) 
	{
		printf("please input two num\n");
		scanf("%d %d",pa,pb);
	}
}

int add_mode(int a,int b)
{
	if(x)
		return 0;
	else
		return a+b;
}

int sub_mode(int a,int b)
{
	if(!x)
		return a-b;
	else
		return 0;
}

int output_mode(int a)
{
	printf("%d\n",a);
}

int main(int argc,const char* argv[])
{
	int a,b,ret;
	a=b=ret=0;
	input_mode(&a,&b);
	ret = add_mode(a,b);
	output_mode(ret);
	ret = sub_mode(a,b);
	output_mode(ret);
    return 0;
}
