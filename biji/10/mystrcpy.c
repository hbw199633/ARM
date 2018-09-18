/**************************************************
> File Name: mystrcpy.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月20日 星期五 10时10分13秒
**************************************************/

#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])
{
	int  i = 0;
	char src[128]={0};
	char dest[128]={0};
	bzero(src ,sizeof(src));
	bzero(dest,sizeof(dest));
	scanf("%s %s",src,dest);
/*	while(1)
	{
		dest[i]=src[i];
		i++;
		if(src[i]=='\0')
		{
			dest[i]='\0';
			break;
		}
	}*/
/*	while(src[i]!='\0')
	{
		dest[i]=src[i];
		i++;
	}
	dest[i]='\0';
	*/
/*	while((dest[i]=src[i])!='\0') 
		i++;
*/	while((dest[i]=src[i++])!='\0') 
	printf("%s\n",dest);
    return 0;
}
