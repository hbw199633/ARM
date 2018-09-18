/**************************************************
> File Name: name.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 10时56分49秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int c =0;
	while(1)
	{
		c = getchar();
		if(c == '\n')
			break;
		else
			putchar(c);
//			putchar(c-32); /*a to A*/
//			putchar(c-30); /*passwd*/
	}
	printf("\n");
    return 0;
}
