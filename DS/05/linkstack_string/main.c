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
//	int  i = 0;
	datatype va = {0};
	linkstack *ls = create_linkstack();
	
	while(1)
	{
		printf("请输入字符串按'quit'退出\n");
		scanf("%s",va.str);
		if(strcmp(va.str,"quit")==0)
			break;
		push_linkstack(ls,va);
		printf("push = %s \n",va.str);
	}
/*	find_linkstack(ls,buff);
	printf("%d \n",buff);

	printf("请输入要修改的栈顶元素的值\n");
	scanf("%d",&va);
	chg_linkstack(ls,va);
*/	while(!empty_linkstack(ls))
	{
		pop_linkstack(ls,&va);
		printf("pop = %s \n",va.str);
	}
	free(ls);
    return 0;
}
