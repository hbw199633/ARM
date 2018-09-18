/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月14日 星期二 10时27分22秒
	> Version: v1.0
 ************************************************************************/

#include "linklist.h"

int main(int argc, const char *argv[])
{
	linknode * L = create_linklist();
	if (NULL == L)		return -1;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		add_tail_linklist(L, i);
	}
	show_linklist(L);
	for (i = 0; i < 10; i++)
	{
		add_head_linklist(L, 6);
	}
	show_linklist(L);
	insert_value_linklist(L, 6, 6);
	printf(" ------------ \n");
	show_linklist(L);
	free_linklist(L);
    return 0;
}
