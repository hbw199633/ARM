/**************************************************
> File Name: for_for.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 14时26分26秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0, j = 0;
	for(i=1;i<10;i++)
	{
		for(j=1;j<=i;j++)
			printf("%d*%d=%d\t",j,i,j*i);
		printf("\n");
	}
    return 0;
}
