/**************************************************
> File Name: zhan.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月09日 星期四 10时06分03秒
**************************************************/

#include <stdio.h>

int luoji_mode();

int luoji_mode()
{
	int i =0,sum=0;
	for(i=0;i<=10;i++)
	{
		sum+=i;
	}
	return sum;
}

int main(int argc,const char* argv[])
{
	int i =0,sum=0,ret = 0;
	for(i=0;i<=100;i++)
	{
		sum+=i;
	}
	ret = luoji_mode();
	printf("%d %d\n",sum,ret);
    return 0;
}
