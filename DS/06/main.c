/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: main.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月26日 星期一 11时02分00秒
***************************************************/

#include "sequeue.h"

int main(int argc,const char* argv[])
{
	int i = 0;
	datatype va = 0;
	sequeue *sq = create_sequeue();
	if(NULL == sq)
	{
		printf("创建队列失败\n");
		return -1;
	}
	for(i=0;i<5;i++)
	{
		enter_sequeue(sq,i);
		printf("入队数据为 %d\n",i);
	}
	printf("请输入0或1代表查找队尾或队头\n");
	scanf("%d",&i);
	find_sequeue(sq,&va,i);
	if(i)
		printf("队头为%d\n",va);
	else
		printf("队尾为%d\n",va);	
	
	printf("请输入0或1代表修改队尾或队头\n");
	scanf("%d",&i);
	printf("请输入要修改的值\n");
	scanf("%d",&va);
	chg_sequeue(sq,&va,i);	
	if(i)
		printf("队头修改后为%d\n",va);
	else
		printf("队尾修改后为%d\n",va);	

	while(!empty_sequeue(sq))
	{
		exit_sequeue(sq,&va);
		printf("出队数据为 %d\n",va);
	}
	free_sequeue(sq);
	return 0;
}
