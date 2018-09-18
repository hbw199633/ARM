/* ************************************************************************
	> File Name: linkstack.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月17日 星期五 14时25分34秒
	> Version: v1.0
 ************************************************************************/

#include "linkstack.h"

/*********************** 创建节点函数 ***********************/
linknode * create_linknode(datatype value)
{
	linknode * p = (linknode *)malloc(sizeof(linknode));
	if (NULL == p)			return NULL;
	p->data	= value;
	p->next = NULL;

	return p;
}

/*********************** 创建链式栈 ***********************/
linkstack * create_linkstack(void)
{
	linkstack * s = (linkstack *)malloc(sizeof(linkstack));
	if (NULL == s)			return NULL;
	bzero(s, sizeof(linkstack));
	return s;
}


/*********************** 判断栈是否为满 ***********************/
int isfull_linkstack(linkstack * s)
{
	if (NULL == s)			return -1;
	if (s->n >= MAX)		return 1;
	else 					return 0;
}

/*********************** 入栈函数 ***********************/
int push_linkstack(linkstack * s, datatype value)
{
	if (NULL == s)				return -1;
	if (isfull_linkstack(s))	return -1;
	linknode * p = create_linknode(value);
	if (NULL == p)				return -1;

	p->next = s->head;
	s->head = p;
	s->n++;

	return 0;
}

/*********************** 判断栈是否为空 ***********************/
int isempty_linkstack(linkstack * s)
{
	if (NULL == s)			return -1;
	if (s->n <= 0)			return 1;
	else  					return 0;

}

/*********************** 出栈函数 ***********************/
datatype pop_linkstack(linkstack * s)
{
	if (NULL == s)				return -1;
	if (isempty_linkstack(s))	return -1;
	linknode * p = s->head;
	s->head = p->next;
	datatype data = p->data;
	free(p);
	s->n--;
	return data;
}

int pop_linkstack1(linkstack * s, datatype * data)
{
	if ((NULL == s) || (NULL == data))	return -1;
	if (isempty_linkstack(s))			return -1;
	linknode * p = s->head;

	s->head = p->next;
	*data = p->data;
	free(p);
	s->n--;

	return 0;
}


/*********************** 释放链式栈 ***********************/
int free_linkstack(linkstack * s)
{
	if (NULL == s)			return -1;
	while (!isempty_linkstack(s))
	{
		pop_linkstack(s);
	}
	free(s);

	return 0;
}

/*********************** 获取栈顶元素 ***********************/
int get_top_value_linkstack(linkstack * s, datatype * data)
{
	if ((NULL == s) || (NULL == data))	return -1;
	if (isempty_linkstack(s))			return -1;
	*data = s->head->data;
	return 0;
}


int get_top_value_linkstack1(linkstack * s)
{
	if (NULL == s)			return -1;
	if (isempty_linkstack(s))	return -1;
	return s->head->data;
}




