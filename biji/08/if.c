/**************************************************
> File Name: if.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 09时42分14秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a = 3 ,b =5;
	if(a>b)
	{
		printf("%d - %d = %d \n",b,a,(b-a));
	}
	else
	{
		printf("a<b\n");
	}
    return 0;
}
