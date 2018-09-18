/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: main.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月23日 星期五 10时38分22秒
***************************************************/

#include "linkstack.h"

int main(int argc,const char* argv[])
{
	int  i = 0;
	datatype va = 0;
	linkstack *ls = create_linkstack();
	
	for(;i<10;i++)
	{
		push_linkstack(ls,i);
		printf("push = %d \n",i);
	}
	while(!empty_linkstack(ls))
	{
		pop_linkstack(ls,&va);
		printf("pop = %d \n",va);
	}
	free(ls);
    return 0;
}
