/**************************************************
> File Name: mystrcmp.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月20日 星期五 11时14分45秒
**************************************************/

#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])
{
/*	int i=0,j=0;
	char src[128]={0};
	char dest[128]={0};
	bzero(src,sizeof(src));
	bzero(dest,sizeof(dest));
	scanf("%s %s",src,dest );
	while(src[i]!='\0')
	{
		if(dest[i]!=src[i])
		{
			printf("diff\n");
			break;
		}
		else
			i++;
	}
*/
	char *src=NULL;
	char *dest=NULL;
	char a[128]={0};
	char b[128]={0};
	scanf("%s %s",&a,&b);
	src=a;
	dest=b;
	while((*src!='\0')&&(*src==*dest))
	{
		src++;
		dest++;
	}
	if(*src > *dest)
		printf("1\n");
	else if(*src<*dest)
		printf("-1\n");
	else
		printf("0\n");
	return 0;
}
