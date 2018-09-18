/**************************************************
> File Name: str.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 17时08分00秒
**************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	char b[10]={"hhhhh"};
	char x[10]={"oooooo"};
	printf("%s %d\n",b,strlen(b));
	printf("%s %d\n",x,strlen(x));
   // printf("%s\n",strcpy(c,b));
	if(strcmp(b,x))
	{
		printf("diff\n");
	}
	return 0;
}
