/**************************************************
> File Name: point2.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 11时48分38秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	char c = '5';
	char *p1 = &c;
	char *p2 = p1;
	printf("c=%c &c=%p\n",c ,&c);
	printf("*p1=%c p1=%p\n",*p1 ,p1);
	printf("*p2=%c p2=%p\n",*p2 ,p2);

    return 0;
}
