/**************************************************
> File Name: huo.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月16日 星期一 14时36分37秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{	
	unsigned int a = 0x4ac,b = 0123;
	unsigned int z = 0;
	
	z = a | b;
	a |= 1<<4;
	printf("%#0x\n",a);
	printf("%d\n",z);
	printf("%#o\n",z);
	printf("%#0x\n",z);

    return 0;
}
