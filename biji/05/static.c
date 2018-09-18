/**************************************************
> File Name: static.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月14日 星期六 11时21分35秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	static a;
	printf("%d %p\n",a,&a);
    return 0;
}
