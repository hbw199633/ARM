/**************************************************
> File Name: point8.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 14时59分13秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int *p1=a;
	int *p2=&a[9];
	printf("%d\n",p2-p1);
    return 0;
}
