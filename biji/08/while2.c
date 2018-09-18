/**************************************************
> File Name: while2.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 15时17分39秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 100,sum = 0;
	while(i<=1000)
	{
		if((i%3)==0)
		{
			i++;
			continue;
		}
		else
		{
			sum+=i;
			i++;
		}
	}
	printf("%d\n",sum);
    return 0;
}
