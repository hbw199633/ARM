/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：mkfifo.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月03日
*   描    述：
================================================================*/

#include  "head.h"

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

	int fd = open("./def",O_RDONLY);
	if(fd < 0)
	{
		perror("open fifo");
		return -1;
	}
	printf("read fifo fd = %d \n",fd);

	struct student  stu2 ={0};
	ret = read(fd,&stu2,sizeof(stu2));
	printf("read fifo ret = %d id = %d name  = %s sc = %f\n",
			ret,stu2.id,stu2.name,stu2.score);

	close(fd);

    return 0;
}
