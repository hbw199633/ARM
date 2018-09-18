/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：mkfifo.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月03日
*   描    述：
================================================================*/
#include "head.h"

int main(int argc, char *argv[])
{
	int ret = mkfifo("./def",0644);
	if(ret < 0)
	{
		if(errno != EEXIST)
		{
			perror("mkfifo");
			return -1;
		}
	}
	printf("mkfifo ok!!! \n");

	int fd  = open("./def",O_WRONLY);
	if(fd < 0)
	{
		perror("open fifo");
		return -1;
	}
	printf("write fifo fd = %d \n",fd);

	
	struct student stu={123,"zhangsan",88.8};
	ret = write(fd,&stu,sizeof(stu));
	printf("write fifo ret = %d \n",ret);


	close(fd);



    return 0;
}
