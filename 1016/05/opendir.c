/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：opendir.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	DIR * dr = opendir("./test");
	if(NULL == dr)
	{
		perror("open dir");
		return -1;
	}
	printf("open dir ok!! \n");


	struct dirent * dt = readdir(dr);
	if(NULL == dt)
	{
		perror("read dir");
		return -1;
	}

	printf("read dir file name  = %s \n",dt->d_name);

	dt = readdir(dr);
	if(NULL == dt)
	{
		perror("read dir");
		return -1;
	}
	//if(dr->d_name[0] == '.') continue;

	printf("read dir file name  = %s \n",dt->d_name);

	dt = readdir(dr);
	if(NULL == dt)
	{
		perror("read dir");
		return -1;
	}

	printf("read dir file name  = %s \n",dt->d_name);



	closedir(dr);

    return 0;

}
