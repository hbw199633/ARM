/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: perror.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月19日 星期一 15时54分39秒
***************************************************/

#include <stdio.h>
#include <string.h>
#include <errno.h>
int main(int argc,const char* argv[])
{
	int i = 0;
	for(i=0;i<130;i++)
	{
		errno = i;
		printf("errno = %d errmsg = %s \n",errno,strerror(errno));
	}
    return 0;
}
