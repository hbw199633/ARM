/**************************************************
> File Name: char_unsigned.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月13日 星期五 14时07分22秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	unsigned char c =0;
	while(1)
	{
		printf("%d ",c++);
		if(c == 0)
			sleep(1);
	}	
    return 0;
}
