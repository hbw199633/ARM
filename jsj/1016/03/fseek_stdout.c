/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fseek.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{


	int c = fputc('a',stdout);

	fseek(stdout,5,SEEK_SET);

	c = fputc('b',stdout);

	fputc('\n',stdout);
    
	c = fgetc(stdin);	
	printf("c1 = %c \n",c);

	fseek(stdin,10,SEEK_END);

	c = fgetc(stdin);
	printf("c2 = %c \n",c);
	
	
	return 0;
}
