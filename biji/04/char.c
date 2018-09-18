/**************************************************
> File Name: char.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月13日 星期五 13时57分35秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char c = 0;
	while(1)
	{
		c++;
		printf("%d ",c);
		if(c == 0)
			sleep(1);
	}
    return 0;
}
