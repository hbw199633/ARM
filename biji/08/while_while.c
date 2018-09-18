/**************************************************
> File Name: while_while.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 15时01分37秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 1 , j = 1;
	while(i<10)
	{
		while(j<=i)
		{
			printf("%d*%d=%d\t",j,i,(j*i));
			j++;
		}
		i++;
		j=1;
		printf("\n");
	}
    return 0;
}
