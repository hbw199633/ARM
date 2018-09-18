/**************************************************
> File Name: mystrcat.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月20日 星期五 14时03分42秒
**************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	int i = 0, j = 0;
	char src[128]={0};
	char dest[128]={0};
	bzero(src,sizeof(src));
	bzero(dest,sizeof(dest));
	scanf("%s %s",src,dest );
/*	while(src[i]!='\0')
		i++;
	while(dest[j]!='\0')
	{
		src[i]=dest[j];
		j++;
		i++;
	}
	src[i]='\0';
	printf("%s\n",src);
	*/
	while(dest[++i]!='\0');
	while((dest[i++]=src[j++])!='\0');
    printf("%s\n",dest);
	return 0;
}
