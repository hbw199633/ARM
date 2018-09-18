/**************************************************
> File Name: yu.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月16日 星期一 14时19分12秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	unsigned int x = 0x4ac,y=0127;
	unsigned int z =x & y;

	printf("%d\n",z);
	printf("%#o\n",z);
	printf("%#0x\n",z);
	
	return 0;
}
