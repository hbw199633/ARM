/**************************************************
> File Name: goto2.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 17时05分26秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	if(argc != 3)
		goto loop;
	printf("%d+%d=%d\n",atoi(argv[1]),atoi(argv[2]),
			( (atoi(argv[1]) )+( atoi(argv[2]) ) ) );
	return 0;

loop:
	printf("Usage: %s num1 num2!\n",argv[0]);
    return 0;

}
