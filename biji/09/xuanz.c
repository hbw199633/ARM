/**************************************************
  > File Name: xuanze.c
  > Author: Kingyi
  > Mail: joseph2009@163.com 
  > Created Time: 2017年01月19日 星期四 15时02分22秒
 **************************************************/

#include <stdio.h>

#define a(x)  (sizeof(a)/sizeof(a[0]))

int main(int argc,const char* argv[])
{
	int i =0 ,j = 0, min =0,tmp = 0;
	int a[10]={0};
	for(i=0;i<a(x);i++)
		scanf("%d",&a[i]);
	for(i=0;i<a(x);i++)
	{
		min = i;
		for(j=i+1;j<a(x);j++)
		{
			if(a[min]>a[j])
			min=j;
		}
		if(min!=i)
		{
			tmp=a[i];
			a[i]=a[min];
			a[min]=tmp;
		}
	}
	for(i=0;i<a(x);i++)
		printf("%d ",a[i]);
	printf("\n");
return 0;
}
