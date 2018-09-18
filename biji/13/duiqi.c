/**************************************************
> File Name: duiqi.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月08日 星期三 17时35分18秒
**************************************************/

#include <stdio.h>

typedef struct zi
{
	char  c;
	long long l;
	int	  i;	
	short s;
}AA;

int main(int argc,const char* argv[])
{
	AA x;
	printf("x%d x.c%d x.l%d x.s%d x.i%d\n",sizeof(x),
									 sizeof(x.c),
									 sizeof(x.l),
									 sizeof(x.s),
									 sizeof(x.i)
									 );
    return 0;
}
