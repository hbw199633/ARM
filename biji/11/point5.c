/**************************************************
> File Name: point5.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 14时01分24秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int c =500;
	char *p = &c;
	printf("%d %p\n",c,&c);
	printf("%d %p\n",*p,p);
	int a = 'a';
	char *p1 = &a;
	printf("%d %p\n",a,&a);
	printf("%d %p\n",*p1,p1);
    return 0;
}
