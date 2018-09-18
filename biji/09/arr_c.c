/**************************************************
> File Name: arr_c.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 16时42分02秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0;
	char c = 0;
	char a[10]={0};
	char b[10]={0};
	scanf("%c",&c);
	printf("%c\n",c);
//	for(i=0;i<10;i++)
//	{
//		scanf("%c",&a[i]);
//		printf("%c",a[i]);
//	}
	for(i=0;i<10;i++)
	{
		scanf("%s",b);
		printf("%s",b);
	}
	return 0;
}
