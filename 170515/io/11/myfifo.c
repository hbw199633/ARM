/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：myfifo.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int fifo_read(const char *name,void * buff,int size)
{
	if( (NULL == name) ||(NULL == buff))  return -1;
	int fd = 0,ret  = 0;


	fd  = open(name,O_RDONLY);
	if(fd < 0)   return errno;

	ret = read(fd,buff,size);
	if(ret < 0)  return errno;

	close(fd);

	return  0;
}


int fifo_write(const char *name,void * buff,int size)
{
	if( (NULL == name) ||(NULL == buff))  return -1;
	int fd = 0,ret  = 0;


	fd  = open(name,O_WRONLY);
	if(fd < 0)   return errno;

	ret = write(fd,buff,size);
	if(ret < 0)  return errno;

	close(fd);

	return  0;
}


