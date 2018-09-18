/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：sqltie3_get_tables.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月15日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sqlite3.h>

int main(int argc, char *argv[])
{
	sqlite3 * db = NULL;
	int ret = sqlite3_open("./test.db", &db);
	if(ret < 0)
	{
		perror("sqlite3 open error \n");
		return -1;
	}
	printf("sqlite 3 open ok \n");

	char * sql  = "select * from user;";
	char ** rest  = NULL;
	int  row =0, col  = 0;

	ret = sqlite3_get_table(db,sql,&rest,&row,&col,NULL);
	if(ret < 0)
	{
		perror("sqlite3 get table error");
		return -1;
	}
	printf("row  = %d col = %d \n",row,col);

	int i = 0,j = 0;
	for(i = 0;i<= row ;i++)
	{
		for(j= 0;j< col;j++)
		{
			printf(" %s ", rest[i*col + j]);
		}
		printf("\n");
	}

	sqlite3_close(db);

    return 0;
}
