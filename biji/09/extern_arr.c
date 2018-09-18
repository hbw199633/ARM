/**************************************************
> File Name: extern_arr.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 10时29分16秒
**************************************************/

#include <stdio.h>

int buff[10];

int main(int argc,const char* argv[])
{
	int i = 0;
	for(i=0;i<10;i++)
		printf("%d %p\n",buff[i],&buff[i]);
    return 0;
}
