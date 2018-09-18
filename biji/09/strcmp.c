/**************************************************
> File Name: strcmp.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 17时48分06秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char src[128]={0};
	char dest[128]={0};
	int i = 0;
	scanf("%s %s",src,dest);
	while(src[i]==dest[i])
		i++;  	
	printf("diff\n");
    return 0;
}
