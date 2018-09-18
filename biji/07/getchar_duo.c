/**************************************************
> File Name: getchar_duo.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 09时46分25秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a,b,c;
	a=b=c=0;
	a=getchar();
	b=getchar();
	c=getchar();
	printf("%c %c %c\n",a,b,c);
    return 0;
}
