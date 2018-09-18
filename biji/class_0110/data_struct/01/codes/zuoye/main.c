/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月13日 星期一 18时03分00秒
	> Version: v1.0
 ************************************************************************/

#include "seqlist.h"

/******************* main函数  *******************/
int main(int argc, const char *argv[])
{
	seqlist * seq = create_seqlist();
	if (NULL == seq)	return -1;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		add_tail_seqlist(seq, i);
	}
	show_seqlist(seq);
	delete_pos_seqlist(seq, 7);
	show_seqlist(seq);

	free_seqlist(seq);
	seq = NULL;

    return 0;
}
