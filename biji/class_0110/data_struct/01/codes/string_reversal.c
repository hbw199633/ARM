/* ************************************************************************
	> File Name: string_reversal.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月13日 星期一 10时13分26秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	char buf[] = "hello world";
	char *p = buf, *p1 = buf, tmp = 0;
	int i = 0;
	while (*p1 != '\0')
		p1++;
	p1--;
	while (p < p1)
	{
		tmp = *p;
		*p  = *p1;
		*p1 = tmp;
		p++;
		p1--;
	}
	printf("buf:%s\n", buf);
	
    return 0;
}

