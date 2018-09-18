/**************************************************
> File Name: erwei.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 10时58分26秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0,j = 0;
	int a[][10]={{9,8,7,6},{9,6,3,5,2}};
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			printf("a[%d][%d]=%d ",i,j,a[i][j]);
		printf("\n");
	}
    return 0;
}
