/* ************************************************************************
	> File Name: test.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月13日 星期一 09时15分07秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

void *my_memset(void *s, int c, size_t n);
void *my_memset1(void *s, int c, size_t n);
void my_bzero(void *s, size_t n); 

int main(int argc, const char *argv[])
{
	char a[10] = {0};
//	my_memset(a, 'a', 10);
//	my_memset1(a, 'a', 10);
	my_bzero(a, sizeof(a));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d\n", a[i]);
	}
    return 0;
}

void *my_memset(void *s, int c, size_t n)
{
	if (NULL == s)		return NULL;
	char * p = (char *)s;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		p[i] = c;
	}

	return s;
}


void *my_memset1(void *s, int c, size_t n)
{
	if (NULL == s)			return NULL;
	char * p = (char *)s;

	while (n--)
	{
		*p = c;
		p++;
	}

	return s;
}

void my_bzero(void *s, size_t n)
{
	my_memset1(s, '\0', n);
}



