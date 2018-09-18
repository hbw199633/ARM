/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fread.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE * fp = fopen("./b.txt","r");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	char buff[128] ={0};

	fread(buff,sizeof(char),sizeof(buff),fp);

	printf("buff = %s \n",buff);



	fclose(fp);

    return 0;
}
