/***************************************************
  > Copyright (C) 2017 ==KINGYI== All rights reserved.
  > File Name: gongyue.c
  > Author: Kingyi
  > Mail:joseph2009@163.com 
  > Created Time: 2017年06月15日 星期四 11时48分12秒
 ***************************************************/

#include <stdio.h>
int gongyue(int a,int b)
{
	int i =0; 
	for(i = a;i>0;i--)
		if((a%i == 0)&&(b%i==0)) 
			break;
	return i;
}

int main(int argc,const char* argv[])
{
	int a = 0, b = 0,ret = 0;
	printf("Please input two num！\n");
	scanf("%d %d",&a,&b);
	if(a < b )
		ret = gongyue(a,b);
	else
		ret = gongyue(b,a);
	printf("%d\n",ret);
	return 0;
}
