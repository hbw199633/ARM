/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: zheban.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月29日 星期四 09时24分23秒
***************************************************/

#include <stdio.h>

#define MAX (sizeof(buff)/sizeof(int))

int zheban(int buff[],int size,int va)
{
	int mid = size/2, ret = 0;
	if((*buff > va)||(*(buff+size-1)<va))	return -1;
	if(*(buff+mid) == va)	return 0;
	if(*(buff+size-1)==va)	return 0;
	if(*(buff+mid)<va)
	{
		ret = zheban(buff+mid,mid,va);
	}
	if(*(buff+mid)>va)
	{
		ret = zheban(buff,mid,va);
	}
	return ret;
}

int main(int argc,const char* argv[])
{
	int va = 0,ret = 0;
	int buff[10]={1,2,3,4,5,6,7,8,9,10};
	printf("Pls input the num find\n");
	scanf("%d",&va);
	ret = zheban(buff,MAX,va);
	if(!ret)
		printf("Find the value\n");
	else
		printf("Not find the value\n");
    return 0;
}
