/**************************************************
> File Name: gets.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 11时22分26秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char buff[128]={0};
	gets(buff);
	printf("%s\n",buff);
    return 0;
}
