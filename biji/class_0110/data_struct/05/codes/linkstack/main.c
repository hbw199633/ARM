/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月17日 星期五 14时26分56秒
	> Version: v1.0
 ************************************************************************/

#include "linkstack.h"

int main(int argc, const char *argv[])
{
	linkstack * s = create_linkstack();
	if (NULL == s)		return -1;
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		push_linkstack(s, i);
	}
	printf("%d\n", get_top_value_linkstack1(s));
	datatype data = 0;
	while(!isempty_linkstack(s))
	{
		pop_linkstack1(s, &data);
		printf("%d ", data);
	}
	printf("\n");
	free_linkstack(s);
    return 0;
}

