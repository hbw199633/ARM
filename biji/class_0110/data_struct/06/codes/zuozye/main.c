/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 13时48分16秒
	> Version: v1.0
 ************************************************************************/

#include "linkqueue.h"

int main(int argc, const char *argv[])
{
	linkqueue * q = create_linkqueue();
	if (NULL == q)			return -1;
	int i = 0;
	datatype tmp = {{0}};
	for (i = 0; i < 5; i++)
	{
		printf("Please int a string\n");
		gets(tmp.buf);
		entry_linkqueue(q, tmp);
	}
	show_linkqueue(q);
	free_linkqueue(q);
    return 0;
}
