/* ************************************************************************
	> File Name: const.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月13日 星期一 09时39分29秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	char * p = "hello world";
	printf("&p：%p\n", &p);
	printf("%p\n", "hello world");
	printf("p:%p\n", p);
	printf("%s\n", p);
    return 0;
}




