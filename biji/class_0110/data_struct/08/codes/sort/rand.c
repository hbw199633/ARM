/* ************************************************************************
	> File Name: rand.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月22日 星期三 13时37分47秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	srand(time(NULL));
	printf("%d\n", rand());
    return 0;
}
