/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：mycp.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage %s [src_file] [dest_file]\n",argv[0]);
		return -1;
	}
	char s[128] ={0};
	FILE * fp_src  = fopen(argv[1],"r");
	if(NULL == fp_src)
	{
		printf("打开源文件失败！\n");
		return -1;
	}
	FILE * fp_dst = fopen(argv[2],"w+");
	if(NULL == fp_dst)
	{
		printf("打开目标文件失败\n");
		fclose(fp_src);
		return -1;
	}

	while(1)
	{
		if( NULL == fgets(s,sizeof(s),fp_src)) break;
		else	fputs(s,fp_dst);
		fflush(fp_dst);
	}


	fclose(fp_src);
	fclose(fp_dst);


    return 0;
}
