/**************************************************
> File Name: do_while1.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 16时05分49秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0,sum = 0;
	do
	{
		if((i%4)==0)
		{
			sum+=i;
			printf("%d\n",i);
		}
		i++;
	}while(i<=1000);
	printf("%d\n",sum);
    return 0;
}
