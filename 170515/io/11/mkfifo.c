/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：mkfifo.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月24日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(int argc, char *argv[])
{


	int ret = mkfifo("./myfifo",0644);
	printf("ret = %d \n",ret);

	system("ls -l");

	ret = unlink("./myfifo");
	printf("unlink ret = %d\n",ret);
	
	system("ls -l");

    return 0;
}
