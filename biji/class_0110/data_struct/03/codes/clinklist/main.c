/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月15日 星期三 09时49分16秒
	> Version: v1.0
 ************************************************************************/

#include "clinklist.h"

int main(int argc, const char *argv[])
{
	linknode * L = create_clinklist();
	if (NULL == L)			return -1;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		add_tail_clinklist(L, i);
	}
	show_clinklist(L);
	for (i = 0; i < 10; i++)
	{
		add_head_clinklist(L, 9);
	}
	show_clinklist(L);
	insert_value_clinklist(L, 9, 9);
	show_clinklist(L);
	free_clinlist(L);
    return 0;
}

