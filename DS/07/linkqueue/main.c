/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: main.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月27日 星期二 09时55分12秒
***************************************************/

#include "Linkqueue.h"

int main(int argc,const char* argv[])
{
	int i = 0,flag = 0;
	datatype va = 0;
	linkqueue *lq = create_linkqueue();
	if(lq == NULL)	goto error;
	for(i=0;i<5;i++)
	{
		enter_linkqueue(lq,i);
		printf("入队数为 %d \n",i);
	}
	
	if(!empty_linkqueue(lq))
	{
		printf("请输入要查询队头1或队尾0\n");
		scanf("%d",&flag);
		if(flag)
		{
			find_linkqueue(lq,&va,1);
			printf("队头数据为 %d \n",va);
		}
		else
		{
			find_linkqueue(lq,&va,0);
			printf("队尾数据为 %d \n",va);
		}
	}
	
	if(!empty_linkqueue(lq))
	{
		printf("请输入要修改队头1或队尾0和修改的值\n");
		scanf("%d %d",&flag,&va);
		if(flag)
			chg_linkqueue(lq,va,1);
		else
			chg_linkqueue(lq,va,0);
	}

	while(!empty_linkqueue(lq))
	{
		exit_linkqueue(lq,&va);
		printf("出队的数据为 %d \n",va);
	}
	
	free(lq);
//	free_linkqueue(lq);
	
	return 0;	

error:
	printf("创建链式队失败\n");
	return -1;
}
