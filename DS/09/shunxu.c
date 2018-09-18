/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: shunxu.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月29日 星期四 09时15分14秒
***************************************************/

#include <stdio.h>

int main(int argc,const char* argv[])
{
	int i = 0,va = 0;
	int buff[10]={10,25,40,33,55,66,39,68,59,48,};
	printf("Pls input one num: ");
	scanf("%d",&va);
	for(i=0;i<10;i++)
	{
		if(buff[i]==va)
		{
			printf("Find the value\n");
			break;
		}
		if(i == 9)
			printf("Not find the value\n");
	}
    return 0;
}
