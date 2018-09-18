/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: sequeue.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月26日 星期一 11时02分18秒
***************************************************/

#include "sequeue.h"
sequeue *create_sequeue()
{
	sequeue *sq = (sequeue *)malloc(sizeof(sequeue));
	if(NULL == sq)	return NULL;
	bzero(sq,sizeof(sequeue));
	return sq;
}

int enter_sequeue(sequeue *sq,datatype va)
{
	if(NULL == sq)	return -1;
	if(full_sequeue(sq))	return -2;
	sq->data[sq->tail] = va;
	sq->tail++;
	sq->count++;
	return 0;
}

int exit_sequeue(sequeue *sq,datatype *va)
{
	if((NULL == sq)||(NULL == va)) return -1;
	if(empty_sequeue(sq))	return -2;
	*va = sq->data[sq->head];
	sq->head++;
	sq->count--;
	return 0;
}

int find_sequeue(sequeue *sq,datatype *va,int flag)
{
	if((NULL == sq)||(NULL == va)) return -1;
	if(empty_sequeue(sq))	return -2;
	if(flag)
		*va = sq->data[sq->head];
	else
		*va = sq->data[sq->tail-1];
	return 0;
}

int chg_sequeue(sequeue *sq,datatype *va,int flag)
{
	if((NULL == sq)||(NULL == va)) return -1;
	if(empty_sequeue(sq))	return -2;
	if(flag)
		sq->data[sq->head] = *va;
	else
		sq->data[sq->tail-1] = *va;
	return 0;
}

int full_sequeue(sequeue *sq)
{
	if(NULL == sq)		return -1;
	if(sq->count >= N)	return -2;
	return 0;
}

int empty_sequeue(sequeue *sq)
{
	if(NULL == sq)		return -1;
	if(sq->count <=0)	return -2;
	return 0;	
}

int free_sequeue(sequeue *sq)
{
	if(NULL == sq)	return -1;
	free(sq);
	sq= NULL;
	return 0;
}
