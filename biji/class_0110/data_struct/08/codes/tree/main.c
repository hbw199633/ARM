/* ************************************************************************
	> File Name: main.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月21日 星期二 11时33分15秒
	> Version: v1.0
 ************************************************************************/

#include "bitree.h"

int main(int argc, const char *argv[])
{
	bitree * root = create_bitree(7, 1);
	pro_order(root);
	printf("\n");
	mid_order(root);
	printf("\n");
	no_order(root);
	printf("\n");
	free_bitree(root);
    return 0;
}
