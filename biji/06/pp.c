/**************************************************
> File Name: pp.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月16日 星期一 10时16分19秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0;
/*	while(1)
	{
		printf("%d\n",i++);
		printf("%d\n",i);
		if(i > 10)
			break;
	}
*/	while(1)
	{
		printf("%d\n",i);
		printf("%d\n",++i);
		printf("%d\n",i);
		if(i > 10)
			break;
	}
    return 0;
}
