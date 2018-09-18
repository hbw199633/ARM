/**************************************************
> File Name: malloc2.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月09日 星期四 14时06分45秒
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,const char* argv[])
{	
	char *x = NULL;
	char * p = (char *)malloc(sizeof(char));
	if(NULL==p)
	{
		perror("malloc \n");
		return 0;
	}
	printf("%d\n",*p);
	bzero(p,sizeof(p));
	printf("%d\n",*p);
	x = p;
	p="nihao";
	printf("%s\n",p);
	free(x);
	printf("%s\n",x);
	x=NULL;
    return 0;
}
