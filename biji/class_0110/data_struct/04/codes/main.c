/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月16日 星期四 10时05分18秒
	> Version: v1.0
 ************************************************************************/

#include "dlinklist.h"

int main(int argc, const char *argv[])
{
	dlinknode * L = create_dlinklist();
	if (NULL == L)			return -1;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		add_tail_dlinklist(L, i);
	}
	show_left_dlinklist(L);
	show_right_dlinklist(L);
	for (i = 0; i < 10; i++)
	{
		add_head_dlinklist(L, 6);
	}
	show_left_dlinklist(L);
	show_right_dlinklist(L);
	insert_pos_dlinklist(L, 21, 11);

	show_left_dlinklist(L);
	show_right_dlinklist(L);
	free_dlinklist(L);
    return 0;
}

