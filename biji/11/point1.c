/**************************************************
> File Name: point1.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 11时28分45秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int c = 'a';
	int* pc = &c ;
	printf("%c %p\n",c,&c);
	printf("%c %p\n",*pc,pc);
	printf("%d\n",sizeof(pc));
    return 0;
}
