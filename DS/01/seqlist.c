/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: seqlist.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月19日 星期一 13时49分18秒
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define N 10

typedef int datatype; 
typedef struct
{
	datatype	data[N];
	int			count;
}seqlist;

seqlist *create_seqlist();
int add_seqlist(seqlist *sq,datatype va);
int full_seqlist(seqlist *sq);
int find_pos_seqlist(seqlist *sq,int pos);

seqlist *create_seqlist()
{
	seqlist *sq = (seqlist *)malloc(sizeof(seqlist));
	if(NULL == sq)	
	{
		return NULL;
		perror("malloc");
	}
	bzero(sq,sizeof(seqlist));
	return sq;
}

int add_seqlist(seqlist *sq,datatype va)
{
	int ret = 0;
	if(NULL == sq)	return -1;
	ret = full_seqlist(sq);
	if(ret == -1)	return -1;
	else if(ret == -2)
	{
		printf("Full seqlist\n");
		return -2;
	}
	else
	{
		sq->data[sq->count] = va;
		sq->count++;
	}
	return 0;
}

int find_pos_seqlist(seqlist *sq,int pos)
{
	if(NULL == sq)	return -1;
	if((pos>sq->count)||(pos<=0))	return -2;
	printf("%d位置的数据是%d\n",pos,sq->data[pos-1]);
	return 0;
}

int show_seqlist(seqlist *sq)
{
	int  i= 0;
	if(NULL == sq)	return -1;
	for(i=0;i<sq->count;i++)
		printf("%d ",sq->data[i]);
	printf("\n");
	return 0;
}
int full_seqlist(seqlist *sq)
{
	if(NULL == sq)	return -1;
	if(sq->count >= N)	return -2;
	return 0;
}

int main(int argc,const char* argv[])
{
	datatype va = 0;
	int ret = 0,pos = 0;
	seqlist * sq = create_seqlist();
	if(NULL == sq)	return -1;
	while(1)
	{
		printf("请输入数字，0退出\n");
		scanf("%d",&va);
		if(va == 0)		break;	
		ret = add_seqlist(sq,va);
		if(ret == -1)	goto error;
		if(ret == -2)	break;
	}
	show_seqlist(sq);
	
	printf("请输入要查找的位置!\n");
	scanf("%d",&pos);
	find_pos_seqlist(sq,pos);
	return 0;

error:
	printf("point send error!\n");
    return -1;
}
