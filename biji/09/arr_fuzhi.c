/**************************************************
> File Name: arr_fuzhi.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 11时42分56秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a[10]={0};
	a[5]=100;
	int i = 0;
	for(i=0;i<10;i++)
		printf("%d\n",a[i]);
    return 0;
}
