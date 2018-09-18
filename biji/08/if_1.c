/**************************************************
> File Name: if_1.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 09时50分57秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char c = 0;
	scanf("%c",&c);
/*	if((c>96)&&(c<123))
	{
		printf("%c\n",c-32);
	}
	else
	{
		printf("Input error!\n");
	}
  */
  ((c>96)&&(c<123))?(printf("%c\nhahaha\n",c-32)):(printf("Inout error!\nwuwuwu\n"));
	return 0;
}
