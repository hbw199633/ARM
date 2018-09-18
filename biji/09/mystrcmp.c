/**************************************************
> File Name: strcmp.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 17时33分08秒
**************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	char buff1[128]={0};
	char buff2[128]={0};
	int i = 0;
	scanf("%s %s",buff1,buff2);
	if(sizeof(buff1)!=sizeof(buff2))
	{
		printf("diif\n");
		return 0;
	}
	while(1)
	{
		if(buff1[i]!=buff2[i])
		{
			printf("diff\n");
			break;
		}
		else if(buff1[i]=='\0')
			break;
		i++;
	}
    return 0;
}
