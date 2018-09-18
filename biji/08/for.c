/**************************************************
> File Name: for.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 11时22分29秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0,sum = 0;
	for(;i<=100;i++)
	{
		sum+=i;	
	}
	printf("sum = %d\n",sum);
    return 0;
}
