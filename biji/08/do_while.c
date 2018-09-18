/**************************************************
> File Name: do_while.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 15时56分04秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0, sum = 0;
	do
	{
		i++;
		sum+=i;
	}while(i<=100);
	printf("sum = %d\n",sum);
    return 0;
}
