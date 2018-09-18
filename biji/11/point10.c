/**************************************************
  > File Name: point10.c
  > Author: Kingyi
  > Mail: joseph2009@163.com 
  > Created Time: 2017年02月06日 星期一 16时05分23秒
 **************************************************/

#include <stdio.h>
#include <string.h>
int main(int argc,const char* argv[])
{
	//变量定义
	char *src=NULL;
	char *dest=NULL;
	char a[128]={0};
	char b[128]={0};
	scanf("%s %s",&a,&b);
	src=a;
	dest=b;
	//逻辑判断
	while((*src!='\0')&&(*src==*dest))
	{
		src++;
		dest++;
	}
	//打印输出
/*	if(*src > *dest)
		printf("1\n");
	else if(*src<*dest)
		printf("-1\n");
	else
		printf("0\n");
*/		printf("%d\n",*src-*dest);
	return 0;
}
