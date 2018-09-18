/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fgets.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE * fp  = fopen("./b.txt","r");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}
	char s[12] ={0};
	//char *p =fgets(s,sizeof(s),fp);
	char *p =fgets(s,128,fp);
	if(NULL == p)
	{
		perror("fgets file");
		goto error;
	}
	printf("fgets s = %s\n",s);
	fclose(fp);
    return 0;
error:
	fclose(fp);
}
