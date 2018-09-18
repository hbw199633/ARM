/**************************************************
> File Name: mystrlen.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月20日 星期五 09时34分23秒
**************************************************/

#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])
{	
	int i = 0;
	char src[128]={0};
	bzero(src,sizeof(src));
	scanf("%s",src);
	while(src[++i]!='\0');
	printf("%d\n",i);
    return 0;
}
