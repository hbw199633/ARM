/* ************************************************************************
	> File Name: enum.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 16时51分39秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	/*
	enum {OFF, ON = 100, good, ok};
	printf("ON:%d\n", ON);		
	printf("OFF:%d\n", OFF);	
	printf("good:%d\n", good);
	*/
	enum {MON, TUR, WED, TUS, FRI, SAT, SUN};
	printf("%d %d %d %d %d\n", MON, TUR, WED, TUS, FRI);
    return 0;
}
