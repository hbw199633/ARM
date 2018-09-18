/***************************************************
  > Copyright (C) 2017 ==KINGYI== All rights reserved.
  > File Name: seqlist.c
  > Author: Kingyi
  > Mail:joseph2009@163.com 
  > Created Time: 2017年06月15日 星期四 14时01分34秒
 ***************************************************/

#include "seqlist.h"

seqlist * create_seqlist()
{
	seqlist *sq = (seqlist *)malloc(sizeof(seqlist));
	if(NULL == sq)
	{
		perror("malloc");
		return NULL;
	}
	bzero(sq,sizeof(seqlist));
	return sq;
}

int add_seqlist(seqlist *sq,datatype va)
{
	int ret = 0;
	if(sq == NULL)		return -1;
	ret = full_seqlist(sq);
	if(ret ==-1)		return -1;
	else if(ret == -2)	return -2;
	else
	{
		sq->data[sq->count] = va;
		sq->count++;
	}
	return 0;
}

int chg_va_seqlist(seqlist *sq,datatype old_va,datatype new_va)
{
	int i = 0;
	if(sq == NULL)		return -1;
	for(i = 0;i< sq->count;i++)
	{
		if(old_va == sq->data[i])
		{
			sq->data[i] = new_va ;
			break;
		}
	}
	return 0;
}

int chg_pos_seqlist(seqlist *sq,int pos,datatype new_va)
{
	int i = 0;
	if(sq == NULL)		return -1;
	for(i = 0;i< sq->count;i++)
	{
		if(pos == i+1)
		{
			sq->data[i] = new_va ;
			break;
		}
	}
	return 0;
}

int inr_va_seqlist(seqlist *sq,datatype old_va,datatype new_va)
{
	int i =0, j =0;
	if(NULL == sq)	return -1;
	if(full_seqlist(sq)==-2) return -2;
	for(i=0;i<sq->count;i++)
	{
		if(sq->data[i] == old_va)
		{
			for(j=sq->count;j>i+1;j--)
			{
				sq->data[j] = sq->data[j-1];
			}
				sq->count++;
				sq->data[i+1] = new_va;		
				break;
		}
	}
	return 0;
}

int inr_pos_seqlist(seqlist *sq,datatype va,int pos)
{
	int j = 0;
	if(NULL == sq)			return -1;
	if(--pos > sq->count)	return -2;
	for(j=sq->count;j>pos;j--)
	{
		sq->data[j] = sq->data[j-1];
	}
	sq->count++;
	sq->data[j] = va;
	return 0;
}

int del_va_seqlist(seqlist *sq,datatype va)
{
	int ret = 0 ,i =0 ,j=0;
	if(NULL == sq)				return -1;
	ret = empty_seqlist(sq);	
	if(ret == -1)				return -1;
	if(ret == -2)				return -2;
	for(i=0;i<sq->count;i++)
	{
		if(sq->data[i] == va)
		{
			for(j=i;j<sq->count;j++)
				sq->data[j] = sq->data[j+1];
			sq->count--;
			i--;
		}
	}
	return 0;
}
int del_pos_seqlist(seqlist *sq,int pos)
{
	int i = 0;
	if(NULL == sq)					return -1;
	if((pos>sq->count)||(pos<=0))	return -2;
	if(empty_seqlist(sq))			return -3;
	for(i=pos-1;i<sq->count;i++)
	{
		sq->data[i] = sq->data[i+1];
	}
	sq->count--;
	return 0;
}

int find_va_seqlist(seqlist *sq,datatype va)
{
	int i = 0,count = 0;
	if(NULL == sq)	return -1;
	for(i=0;i<sq->count;i++)
	{
		if(sq->data[i] == va)
			count++;
	}
	return count;
}

int find_pos_seqlist(seqlist *sq,int pos)
{
	if(NULL == sq )					return -1;
	if((pos>sq->count)||(pos<=0))	return -2;
	return pos-1;
}
int show_seqlist(seqlist *sq)
{
	int i = 0;
	if(NULL == sq)	return -1;
	for(;i<sq->count;i++)
		printf("%d ",sq->data[i]);
	printf("\n");
	return 0;
}

int free_seqlist(seqlist *sq)
{
	free(sq);
	return 0;
}

int full_seqlist(seqlist *sq)
{
	if(sq == NULL)		return -1;
	if(sq->count >= N)	return -2;
	return 0;
}

int empty_seqlist(seqlist *sq)
{
	if(sq == NULL)		return -1;
	if(sq->count <= 0)	return -2;
	return 0;
}
