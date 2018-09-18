/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: seqlist.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月19日 星期一 13时49分18秒
***************************************************/

#include "seqlist.h"

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

int inr_va_seqlist(seqlist *sq,datatype old_va,datatype va)
{
	int i =0,j = 0;
	if(NULL == sq)	return -1;
	if(full_seqlist(sq) == -2)	return -2;
	for(i=0;i<sq->count;i++)
	{
		if(sq->data[i] == old_va)
		{
			for(j=sq->count;j>i+1;j--)
			{
				sq->data[j] = sq->data[j-1];
			}
			sq->count++;
			sq->data[i+1] = va;
			break;
		}
	}
	return 0;
}

int chg_va_seqlist(seqlist *sq,datatype old_va,datatype va)
{
	int i = 0;
	if(NULL == sq)		return -1;
	for(;i<sq->count;i++)
	{
		if(sq->data[i] == old_va)
		{
			sq->data[i] = va;
			break;
		}
		if(i == sq->count-1)
			return -2;
	}
	return 0;
}

int chg_pos_seqlist(seqlist *sq,int pos,datatype va)
{
	int  i = 0;
	if(NULL == sq)		return -1;
	if((pos<=0)||(pos>sq->count))	return -2;
	sq->data[pos-1] = va; 
	return 0;
}

int del_va_seqlist(seqlist *sq,datatype va)
{
	int ret = 0,i = 0,j = 0,flag = 0;
	if(NULL == sq)		return -1;
	ret = empty_seqlist(sq);
	if(ret == -1)		return -1;
	else if(ret == -2)		return -2;
	else
	{
		for(i=0;i<sq->count;i++)
		{
			if(sq->data[i] == va)
			{
				for(j=i;j<sq->count;j++)
				{
					sq->data[j] = sq->data[j+1];
				}
				sq->count--;
				i--;
				flag = 1;
//				break;
			}
//			if(i == sq->count-1)	return -3;
			if(!flag)		return -3;
		}
	}
}

int del_pos_seqlist(seqlist *sq,int pos)
{
	int i =0;
	if(NULL == sq)		return -1;
	if(empty_seqlist(sq)==-2)	return -2;
	if((pos>sq->count)||(pos<=0))return -3;
	for(i=pos-1;i<sq->count;i++)
	{
		sq->data[i] = sq->data[i+1];
	}
	sq->count--;
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

int empty_seqlist(seqlist *sq)
{
	if(NULL == sq)		return -1;
	if(sq->count <= 0)	return -2;
	return 0;
}

int free_seqlist(seqlist *sq)
{
	if(NULL == sq)	return -1;
	free(sq);
	return 0;
}

