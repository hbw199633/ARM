/**************************************************
> File Name: arr.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 09时47分23秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char buf[10]={'a','b','c'};
	int buff[10]={1,2,3};
	int a[10];
	static b[10];
	int i=0;
	printf("char = %d  int = %d\n",sizeof(buf),sizeof(buff));
 /*   for(i=0;i<10;i++)
		printf(" %d %p\n",buf[i],&buf[i]);
    for(i=0;i<10;i++)
		printf(" %d %p\n",buff[i],&buff[i]);
   */ for(i=0;i<10;i++)
		printf(" %d %p\n",a[i],&a[i]);
    for(i=0;i<10;i++)
		printf(" %d %p\n",b[i],&b[i]);
	return 0;
}
