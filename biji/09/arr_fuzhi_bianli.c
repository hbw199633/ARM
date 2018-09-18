/**************************************************
> File Name: arr_fuzhi_bianli.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 11时54分56秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a[10]={0};
	int i = 0;
	for(i=0;i<10;i++)
	{
	//	a[i]=i;
	//	a[8]=100;
		scanf("%c",&a[i]);
		printf("%c \n",a[i]);
	}
    return 0;
}
