/**************************************************
> File Name: point11.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 16时38分39秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int c[10]={0,1,2,3,4,5,6,7,8,9};
	int *p = &c[0];
	int i = 0;
	for(i=0;i<10;i++)
	{
		printf("%d ",c[i]);
		printf("%d ",p[i]);
		printf("%d ",*(p+i));
		printf("%d ",*(c+i));
		printf("\n");
	}
    return 0;
}
