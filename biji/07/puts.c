/**************************************************
> File Name: puts.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 13时53分55秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char buff[10]={0};
	int c = 0;
	gets(buff);
	c = puts(buff);
	printf("%d\n",c);
    return 0;
}
