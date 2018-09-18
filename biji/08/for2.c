/**************************************************
> File Name: for2.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 11时49分31秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i =1;
	for(;i<=100;)
	{
		if(i%3==0)
			printf("%d ",i);
		i++;
	}
	printf("\n");
    return 0;
}
