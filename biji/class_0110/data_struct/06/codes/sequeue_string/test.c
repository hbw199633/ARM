/* ************************************************************************
	> File Name: test.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 11时57分00秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#include <string.h>

typedef struct {
	char buf[32];
}STU;

int main(int argc, const char *argv[])
{
	STU data[10];
	strcpy(data[0].buf, "hello world");
	printf("data[0].buf:%s\n", data[0].buf);
    return 0;
}



