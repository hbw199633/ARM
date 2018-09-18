/**************************************************
> File Name: gets_duo.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 11时41分04秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char buff1[]={0};
		 //buff2[10]={0},buff3[10]={0};
	gets(buff1);
/*	gets(buff2);
	gets(buff3);
	printf("buff1 = %s\n",buff1);
	printf("buff2 = %s\n",buff2);
	printf("buff3 = %s\n",buff3);
*/	printf("buff1 = %s\n",buff1);
    return 0;
}
