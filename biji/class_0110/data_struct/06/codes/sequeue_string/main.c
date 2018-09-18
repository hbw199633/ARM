/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 09时51分56秒
	> Version: v1.0
 ************************************************************************/

#include "sequeue.h"

int main(int argc, const char *argv[])
{
	sequeue * q = create_sequeue();
	if (NULL == q)		return -1;

	datatype arr[] = {"hello", "world", "good", "well"};

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		entry_sequeue(q, arr[i]);
	}
	show_sequeue(q);
	free_sequeue(q);

    return 0;
}
