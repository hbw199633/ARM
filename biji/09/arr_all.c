/**************************************************
> File Name: arr_all.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 11时09分50秒
**************************************************/

#include <stdio.h>

#define a(x)  (sizeof(a)/sizeof(a[0]))

int main(int argc,const char* argv[])
{
	int buff[5]={123,456,789,369,258};
	int a[]={1,2,3};
//	int b[];
	int i = 0;
    for(i=0;i<5;i++)
		printf("%d\n",buff[i]);
    for(i=0;i<a(x);i++)
		printf("%d\n",a[i]);
	return 0;
}
