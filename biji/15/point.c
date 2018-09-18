/**************************************************
> File Name: point.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月10日 星期五 09时10分26秒
**************************************************/

#include <stdio.h>

void swap(int a,int b);
void swap(int a,int b)
{
	printf("%d %d\n",a,b);
	int tmp =0;
	tmp = a;
	a = b;
	b = tmp;
	printf("%d %d\n",a,b);
}

void swap2(int *pa,int *pb)
{
	int tmp;
	tmp = *pa;
	*pa =*pb;
	*pb = tmp;
}

int main(int argc,const char* argv[])
{
	int a = 3,b = 4;
	swap(a,b);
	swap2(&a,&b);
	printf("%d %d\n",a,b);
    return 0;
}
