/**************************************************
> File Name: scanf5.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月17日 星期二 16时18分33秒
**************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int a = 0,b = 0, c = 0 ,x =0;
	x = scanf("%d %d %d",&a,&b,&c);
	printf("x=%d a=%d b=%d c=%d\n",x,a,b,c);
    return 0;
}
