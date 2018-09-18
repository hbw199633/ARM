/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：test.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月25日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE * fp = fopen("./1.txt","r+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}


	write(fp->_fileno,"nihao wohao",11);


	fclose(fp);
    return 0;
}
