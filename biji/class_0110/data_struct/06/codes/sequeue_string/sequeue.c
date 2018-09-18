/* ************************************************************************
	> File Name: sequeue.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 09时51分51秒
	> Version: v1.0
 ************************************************************************/

#include "sequeue.h"

/*************** 创建顺序队列 ***************/
sequeue * create_sequeue(void)
{
	sequeue * q = (sequeue *)malloc(sizeof(sequeue));
	if (NULL == q)		return NULL;
	bzero(q, sizeof(sequeue));

	return q;
}


/*************** 释放顺序队列 ***************/
int free_sequeue(sequeue * q)
{
	if (NULL == q)		return -1;
	free(q);
	q = NULL;
	return 0;
}

/*************** 判断队列是否满 ***************/
int isfull_sequeue(sequeue * q)
{
	if (NULL == q)		return -1;
	if (q->tail >= N)	return 1;
	else  				return 0;
}

/*************** 入队函数 ***************/
int entry_sequeue(sequeue * q, datatype value)
{
	if (NULL == q)			return -1;
	if (isfull_sequeue(q))	return -1;

	strcpy(q->data[q->tail].buf, value.buf);
	q->tail++;

	return 0;
}

/*************** 判断队列是否为空 ***************/
int isempty_sequeue(sequeue * q)
{
	if (NULL == q)			return -1;
	if (q->head >= q->tail)	return 1;
	else  					return 0;

}

/*************** 出队函数 ***************/
datatype exit_sequeue(sequeue * q)
{
	if (NULL == q)			return;
	if (isempty_sequeue(q))	return;

	datatype data;
	strcpy(data.buf,q->data[q->head].buf);
	q->head++;

	return data;
}

int exit_sequeue1(sequeue * q, datatype * data)
{
	if ((NULL == q) || (NULL == data))	return -1;
	if (isempty_sequeue(q))				return -2;

	strcpy(data->buf, q->data[q->head].buf);
	q->head++;

	return 0;
}

/*************** 打印顺序队列 ***************/
int show_sequeue(sequeue * q)
{
	if (NULL == q)			return -1;
	if (isempty_sequeue(q))	return -2;
	datatype data;
	while (!isempty_sequeue(q))
	{
		data = exit_sequeue(q);
		printf("%s ", data.buf);
	}
	printf("\n");

	return 0;
}



