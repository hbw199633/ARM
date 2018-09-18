/**************************************************
> File Name: fuzhi.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月16日 星期一 09时20分15秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a =100,sum = 5050;
	while(a >= 0)
	{
		sum-=a;
		a--;
	}
	printf("%d \n",sum);
    return 0;
}
