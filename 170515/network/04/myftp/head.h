/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：head.h
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月29日
*   描    述：
================================================================*/

#ifndef _HEAD_H_
#define _HEAD_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>



struct filemsg
{
	int   type;
	char  filename[128];
	char  filetext[1024];
	int   filesize;
};



#endif 
