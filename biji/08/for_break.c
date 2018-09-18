/**************************************************
> File Name: for_break.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 13时53分07秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0,j = 0;
	for(;i<10;i++)
	{
		for(;j<50;j++)
		{
			if(j>25)
			{
				printf("%d\n",j);
				break;
			}
		}
		if(i>5)
		{
			printf("%d\n",i);
			break;
		}
	}
    return 0;
}
