/* ************************************************************************
	> File Name: seqstack.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月17日 星期五 09时58分12秒
	> Version: v1.0
 ************************************************************************/

#include "seqstack.h"

/*************** 申请顺序栈空间 ***************/
seqstack * create_seqstack(void)
{
	seqstack * s = (seqstack *)malloc(sizeof(seqstack));
	if (NULL == s)			return NULL;
	bzero(s, sizeof(seqstack));
	return s;
}

/*************** 释放栈空间函数 ***************/
int free_seqstack(seqstack * s)
{
	if (NULL == s)		return -1;
	free(s);
	s = NULL;
	return 0;
}

/*************** 判断栈是否为满 ***************/
int isfull_seqstack(seqstack * s)
{
	if (NULL == s)			return -1;
	if (s->top >= N)		return 1;
	else 					return 0;
}


/*************** 入栈函数 ***************/
int push_seqstack(seqstack * s, datatype value)
{
	if (NULL == s)			return -1;
	if (isfull_seqstack(s))	return -1;

	s->data[s->top] = value;
	s->top++;

	return 0;
}

/*************** 判断栈是否为空 ***************/
int isempty_seqstack(seqstack * s)
{
	if (NULL == s)			return -1;
	if (s->top <= 0)		return 1;
	else 					return 0;
}

/*************** 出栈函数 ***************/
int pop_seqstack(seqstack * s, datatype * data)
{
	if ((NULL == s) || (NULL == data))		return -1;
	if (isempty_seqstack(s))					return -1;

	s->top--;
	*data = s->data[s->top];
	s->data[s->top] = 0;

	return 0;
}

/*************** 获取栈顶元素 ***************/
datatype get_top_value_seqstack(seqstack * s)
{
	if (NULL == s)				return -1;
	if (isempty_seqstack(s))	return -1;
	return s->data[s->top-1];
}

int get_top_value_seqstack1(seqstack * s, datatype * data)
{
	if ((NULL == s) || (NULL == data))		return -1;
	if (isempty_seqstack(s))				return -1;

	*data = s->data[s->top-1];

	return 0;
}






