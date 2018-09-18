/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：test.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月15日
*   描    述：
================================================================*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

	FILE * fp  = fopen("./test2.sql","w+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	fputs("PRAGMA foreign_keys=OFF;\n",fp);
	fputs("BEGIN TRANSACTION;\n",fp);
	int i = 0;
	char buff[128] ={0};
	for(i=0;i<100;i++)
	{
		sprintf(buff,"INSERT INTO \"user\" VALUES(%d,'nihao%d','100%d');\n",i,i,i);
		fputs(buff,fp);
	}
	fputs("COMMIT;\n",fp);
	fclose(fp);

    return 0;
}
