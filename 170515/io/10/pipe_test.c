/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pipe.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月24日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
	int fd[2] ={0};
	int ret = pipe(fd);
	if(ret < 0)
	{
		perror("pipe");
		return -1;
	}
	printf("ret = %d fd[0] =%d fd[1] = %d \n",ret,fd[0],fd[1]);


	close(fd[0]);

	ret = write(fd[1],"abc",3);
	
	printf("ret = %d \n",ret);
	
	close(fd[1]);



    return 0;
}
