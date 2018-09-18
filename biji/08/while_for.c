/**************************************************
> File Name: while_for.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 14时46分59秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0,sum = 0;
	while(i<=100)
	{
		sum+=i;
		i++;
	}
	printf("%d\n",sum);
    return 0;
}
