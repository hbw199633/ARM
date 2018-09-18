/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：stat.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月25日
*   描    述：
================================================================*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage %s [file] \n",argv[0]);
		return -1;
	}

	struct stat buff;
	int ret = stat(argv[1],&buff);
	if(ret < 0)
	{
		perror("stat");
		return -1;
	}


	if(S_ISREG(buff.st_mode)) 
		printf("-");
	else if(S_ISDIR(buff.st_mode))
		printf("d");
	


	if(buff.st_mode & S_IRUSR)  printf("r"); else printf("-");
	if(buff.st_mode & S_IWUSR)  printf("w"); else printf("-");
	if(buff.st_mode & S_IXUSR)  printf("x"); else printf("-");


	printf(" %u ",buff.st_nlink);


	struct passwd * pd = getpwuid(buff.st_uid);
	printf(" %s ",pd->pw_name);



	struct tm *ptm  = localtime(&buff.st_mtime);	
	printf(" %2d月 %2d %2d:%2d ",
	          //ptm->tm_year + 1900,
			  ptm->tm_mon + 1,
			  ptm->tm_mday,
			  ptm->tm_hour,
			  ptm->tm_min
			  //ptm->tm_sec
			  );
	printf(" %s ", argv[1]);

	printf("\n");

    return 0;
}
