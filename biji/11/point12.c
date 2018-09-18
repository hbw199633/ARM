/**************************************************
> File Name: point12.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 16时48分56秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a = 100;
	int b = 200;
	int c = 300;
	int *p[3]={&a,&b,&c};
	printf("a=%d p=%d\n",a,*(p[0]));	
	printf("a=%d p=%d\n",a,**p);	
	printf("b=%d p=%d\n",b,*(p[1]));	
	printf("c=%d p=%d\n",c,*(p[2]));	
    return 0;
}
