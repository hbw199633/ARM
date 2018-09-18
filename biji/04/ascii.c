/**************************************************
> File Name: ascii.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月13日 星期五 17时11分16秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i =0;
	for(i=0;i<128;i++)
		printf("ascii %d = %c\n",i,i);
    return 0;
}
