/**************************************************
> File Name: bzero.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 17时16分44秒
**************************************************/

#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])
{
	char c[128]={0};
	strcpy(c,"dsfsadfsdfsdfsdfsd");
	printf("%s\n",c);
	bzero(c,sizeof(c));
	printf("%s\n",c);
    return 0;
}
