/**************************************************
> File Name: strcpy.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月20日 星期五 09时58分48秒
**************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	char src[128]={0};
	char dest[128]={0};
//	bzero(src,sizeof(src));
//	bzero(dest,sizeof(dest));
	scanf("%s %s",src,dest );
	char *ret = strcpy(dest,src);
	printf("%s %s\n",src,dest);
	printf("%p \n",&ret);
	printf("%p \n",dest);


    return 0;
}
