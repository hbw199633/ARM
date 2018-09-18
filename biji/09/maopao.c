/**************************************************
  > File Name: maopao.c
  > Author: Kingyi
  > Mail: joseph2009@163.com 
  > Created Time: 2017年01月19日 星期四 14时08分32秒
 **************************************************/

#include <stdio.h>
#include <string.h>

#define a(x)  (sizeof(a)/sizeof(a[0]))

int main(int argc,const char* argv[])
{
	char a[128]={0};
	int i = 0, j = 0,tmp = 0;

	printf("Please input some nums!\n");
	for(i=0;i<a(x);i++)
		scanf("%d",&a[i]);
	for(i=0;i<a(x)-1;i++)
	{
		for(j=0;j<a(x)-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				tmp=a[j];
				a[j]=a[j+1];
				a[j+1]=tmp;
			}
		}
	}
	for(i=0;i<a(x);i++)
		printf("%d ",a[i]);
	printf("\n");
	return 0;
}
