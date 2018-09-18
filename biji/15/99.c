/**************************************************
> File Name: 99.c
> Author: hebowen
> Mail: 982034166@qq.com 
> Created Time: 2017年02月10日 星期五 11时03分13秒
**************************************************/

#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])
{
	int c=0,i=0;
	char a[128]={0};
	char *p=&a[0];
	scanf("%s",a);
	*p++;
	i++;
	while(p=='\0')
	{
		*p++;
		i++;
	}
	c=i;
	printf("%d\n",c);
    return 0;
}
