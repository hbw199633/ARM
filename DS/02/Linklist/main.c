/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: main.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月20日 星期二 15时00分09秒
***************************************************/

#include "Linklist.h"

int main(int argc,const char* argv[])
{
	int i =0;
	linklist *ls = create_linklist();
    if(ls == NULL)	
	{
		perror("malloc create linklist\n");
		return -1;
	}
	for(i=0;i<10;i++)
	{
		add_linklist(ls,i);
	}
	show_linklist(ls);
	return 0;
}
