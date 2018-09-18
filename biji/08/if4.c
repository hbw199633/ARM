/**************************************************
> File Name: if4.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月18日 星期三 10时04分16秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a = 9,b = 6, c =3;
	if(a>b)
		if(b>c)
			printf("a>b>c\n");
		else
			printf("a>c>b\n");

    return 0;
}
