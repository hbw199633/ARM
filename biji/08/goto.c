/**************************************************
  > File Name: goto.c
  > Author: Kingyi
  > Mail: joseph2009@163.com 
  > Created Time: 2017年01月18日 星期三 16时16分07秒
 **************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0, sum = 0;
flag:
	if(i<=100)
	{
		sum+=i;
		i++;
	}
	else
		goto flag1;
	goto flag;
flag1:	printf("sum = %d\n",sum);
		return 0;
}
