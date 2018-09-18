/**************************************************
> File Name: swap.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月07日 星期二 15时00分00秒
**************************************************/

#include <stdio.h>

int swap(int *pa,int *pb)
{
	int z = 0;
	z   = *pa;
	*pa = *pb;
	*pb = z;
}

int main(int argc,const char* argv[])
{
	int a = 3,b =4;

	printf("1 a = %d b = %d\n",a,b);
	swap(&a,&b);
	printf("2 a = %d b = %d\n",a,b);
    return 0;
}
