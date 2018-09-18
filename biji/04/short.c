/**************************************************
> File Name: char_max_min.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月13日 星期五 14时19分45秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	unsigned short c =0;
	int a = 0,b = 0,count = 0;
    while(a<=b)
	{
		a=c;
		b=++c;
		count++;
	}
	printf("max = %d\ncount = %d\n",a,count);
/*	signed short c =0;
	int a = 0,b = 0;
    while(a<=b)
	{
		a=c;
		b=++c;
	}
	printf("%d\n",a);
	printf("%d\n",b);
*/	return 0;
}
