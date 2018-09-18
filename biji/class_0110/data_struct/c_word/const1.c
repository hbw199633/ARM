/* ************************************************************************
	> File Name: const1.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 16时44分42秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
	int a = 10, b = 20;
	int * const p = &a;
	printf("*p：%d\n", *p);

	* p = 1000;
	printf("*p：%d\n", *p);
    return 0;
}

/* const int * p  ==== int const * p	常量指针，
 * 指针的指向可以进行更改，但指向的内存区域中的
 * 数据不能通过该指针进行更改。
 *
 * int * const p	指针常量，指针的指向不能更改，
 * 但指针指向的内存区域中的数据可以通过该指针进行
 * 更改。
 * */

