/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：feof.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	FILE * fp = fopen("./a.txt","r");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	char *p = NULL;
	char buff[128] = {0};
	while(!feof(fp))
	{
		bzero(buff,sizeof(buff));
		p = fgets(buff,sizeof(buff),fp);
//		if( feof(fp) )  break;
	//	if(p == NULL) break;
		printf("%s",buff);
	}


	fclose(fp);
    return 0;
}
