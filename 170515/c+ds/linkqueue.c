#include "linkqueue.h"

int comp_linkqueue(linkqueue* lq_src,linkqueue* lq_dst)
{
	if( (NULL == lq_src) || (NULL == lq_dst) )  return -1;

	if(lq_src->count != lq_dst->count)   return -1;
	linknode * tmp  = lq_src->head;
	linknode * tmp2 = lq_dst->head;
	while(tmp)
	{
		if( memcmp(tmp,tmp2,sizeof(datatype))  ) 
			 return 1;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	return 0;
}


linkqueue * create_linkqueue()
{
	linkqueue * lq = (linkqueue *)malloc(sizeof(linkqueue));
	if(NULL == lq)
	{
		perror("fail to malloc!\n");
		return NULL;
	}
	lq->head = NULL;
	lq->tail = NULL;
	lq->count = 0;
	return lq;
}

int enter_linkqueue(linkqueue * lq, datatype va)
{
	if(NULL == lq)	return -1;
	if(full_linkqueue(lq))	return -1;
	linknode * tmp = (linknode *)malloc(sizeof(linknode));
	if(NULL == tmp)
	{
		perror("fail to malloc!\n");
		return -1;
	}
	tmp->next = NULL;
	tmp->data = va;
	if(lq->count == 0)
	{
		lq->head = tmp;
		lq->tail = tmp;
		lq->count = 1;
	}
	else
	{
		lq->tail->next = tmp;
		lq->tail = tmp;
		lq->count++;
	}
	return 0;
}

int exit_linkqueue(linkqueue * lq, datatype * va)
{
	if(NULL == lq)	return -1;
	if(empty_linkqueue(lq))	return -1;
	linknode * tmp = lq->head;
	*va = tmp->data;
	lq->head = tmp->next;
	free(tmp);
	lq->count--;
	return 0;
}

int full_linkqueue(linkqueue * lq)
{
	if(NULL == lq)	return -1;
	if(lq->count == M)
		return 1;
	return 0;
}

int empty_linkqueue(linkqueue * lq)
{
	if(NULL == lq)	return -1;
	if(lq->count == 0)
		return 1;
	return 0;
}

int get_head_linkqueue(linkqueue * lq, datatype * va)
{
	if(NULL == lq)	return -1;
	*va = lq->head->data;
	return 0;
}
int get_tail_linkqueue(linkqueue * lq, datatype * va)
{
	if(NULL == lq)	return -1;
	*va = lq->tail->data;
	return 0;
}

int modify_head_linkqueue(linkqueue * lq, datatype va)
{
	if(NULL == lq)	return -1;
	lq->head->data = va;
	return 0;
}
int modify_tail_linkqueue(linkqueue * lq, datatype va)
{
	if(NULL == lq)	return -1;
	lq->tail->data = va;
	return 0;
}

int free_linkqueue(linkqueue *lq)
{
	if(NULL == lq)	return -1;
	datatype va = 0;
	while(0 != lq->count)
	{
		exit_linkqueue(lq, &va);	
	}
	free(lq);
	return 0;
}
