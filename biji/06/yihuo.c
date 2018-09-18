/**************************************************
> File Name: yihuo.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月16日 星期一 15时43分56秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a = 0x12,b = 034,c = 0;
	c = a ^ b;
	printf("%d\n",c);
	printf("%#o\n",c);
	printf("%#0x\n",c);
    return 0;
}
