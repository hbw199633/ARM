/**************************************************
> File Name: test.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月07日 星期二 14时39分15秒
**************************************************/

#include <stdio.h>

int zhuanhuan(int *pa);

int zhuanhuan(int *pa)
{
	*pa=200;
}

int main(int argc,const char* argv[])
{
	int a =100;
	zhuanhuan(&a);
	printf("%d\n",a);
    return 0;
}
