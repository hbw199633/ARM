/**************************************************
> File Name: 0.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年01月19日 星期四 14时25分57秒
**************************************************/

#include <stdio.h>

#define buff(x) (sizeof(buff)/sizeof(buff[0]))
int main(int argc,const char* argv[])
{
	int i = 0;
	char buff[]={'H','e','l','l','o','\0','W','o','r','l','d'};
//	for(i=0;i<buff(x);i++)
		printf("%s\n",buff);
    return 0;
}
