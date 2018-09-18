/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：head.h
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月03日
*   描    述：
================================================================*/

#ifndef _HEAD_H_
#define _HEAD_H_
 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


struct  student
{
	int		id;
	char 	name[32];
	float   score;
};

#endif 
