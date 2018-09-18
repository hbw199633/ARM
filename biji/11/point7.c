/**************************************************
> File Name: point7.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月06日 星期一 14时18分17秒
**************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	char buff[128]={0};
	char *p = buff;
	scanf("%s",p);
	while(*p!='\0')
	{
		printf("%c %p\n",*p,p);
		p++;
	}
	int i = 0;
	for(i=0;i<strlen(buff);i++)
		printf("%c %p\n",buff[i],&buff[i]);
	return 0;
}
