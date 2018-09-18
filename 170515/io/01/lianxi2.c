/*====================================================
*   Copyright (C) 2016 ==CQB==  All rights reserved.
*
*   文件名称：fopen.c
*   创 建 者：cqb 2848319176@qq.com
*   创建日期：2016年11月18日
*   描    述：
================================================================*/

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE * fp  = fopen("./abc","a+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	
	printf("请任意输入信息，'quit'退出\n");

	int a = 0,i = 0;
	char buff[128] ={0};
	int count  = 0;
	while(1)
	{
		buff[i] = fgetc(stdin);
		if(buff[i]== '\n')
		{
			if(!strcmp(buff,"quit\n")) break;
			bzero(buff,sizeof(buff));
			i = 0;
		}
		else
		{
			if(buff[i] > 32)
			{	
				fputc(buff[i],fp);
				count ++;
				i++;
				fflush(fp);
			}
		}
	}
	int ret = fclose(fp);
	printf("count = %d\n",count);


    return 0;
}
