/**************************************************
> File Name: point6.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 14时11分58秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
//	char a[32]={'a','b','c','d','e','f','g','h'};
//	char *p = &a[0];
	int a[32]={'a','b','c','d','e','f','g','h'};
	int *p = &a[0];
	printf("%c %p\n",*p,p);
	p++;
	printf("%c %p\n",*p,p);
	p+=2;
	printf("%c %p\n",*p,p);
	++p;
	printf("%c %p\n",*p,p);
	p-=3;
	printf("%c %p\n",*p,p);
    return 0;
}
