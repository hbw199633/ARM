/**************************************************
> File Name: pp_2.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月16日 星期一 11时02分33秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a = 64;
	while((a>=64)&&(a<90))
		printf("%c ",++a);
	printf("\n");
	while((a>=65)&&(a<=90))
		printf("%c ",a--);
	printf("\n");

    return 0;
}
