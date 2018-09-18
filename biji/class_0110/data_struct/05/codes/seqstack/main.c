/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月17日 星期五 09时58分08秒
	> Version: v1.0
 ************************************************************************/

#include "seqstack.h"

int main(int argc, const char *argv[])
{
	seqstack * s = create_seqstack();
	if (NULL == s)			return -1;
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		push_seqstack(s, i);
	}
	datatype data = 0;
	printf("top value:%d\n", get_top_value_seqstack(s));
	get_top_value_seqstack1(s, &data);
	printf("data:%d\n", data);
	/*
	while (!isempty_seqstack(s))
	{
		pop_seqstack(s, &data);
		printf("%d ", data);
	}
	*/
	printf("\n");
	free_seqstack(s);
    return 0;
}

