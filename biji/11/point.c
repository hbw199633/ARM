/**************************************************
> File Name: point.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 11时15分59秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a=10;
	int *pa;
	pa=&a;
	printf("%p\n",pa);
	pa++;
	printf("%p\n",pa);
    return 0;
}
