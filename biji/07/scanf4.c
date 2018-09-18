/**************************************************
> File Name: scanf4.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 16时01分49秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char buff[128]={0},buff1[128]={0};
	scanf("%5s %s",buff,buff1);
	printf("%s\n",buff);
	printf("%s\n",buff1);
    return 0;
}
