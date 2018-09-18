/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：jiankong.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月22日
*   描    述：
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <dirent.h>


FILE * fp ;
int  count = 0;
pid_t pid[100];

int daemon_init()
{
	pid_t pid = fork();
	if(pid > 0)  exit(0);
    pid = setsid();
	chdir("/daemon");
	umask(0);
	int i = 0;
	for(i=3;i<getdtablesize();i++)
	{
	    close(i);
	}
	return 0;
}

int write_log(char * msg)
{
	fputs(msg,fp);
	fflush(fp);
	return 0;
}



int test_change(char *filename)
{
	pid[count] = fork();
	if(pid[count] == 0)
	{
		char logbuff[1024] ={0};
		struct stat buff={0};
		stat(filename,&buff);
	    time_t  oldtime = buff.st_mtime;
		while(1)
		{
			sleep(1);
			stat(filename,&buff);
			time_t newtime  = buff.st_mtime;
			if(oldtime != newtime)
			{
				struct tm *ptm = localtime(&newtime);
				sprintf(logbuff,"%s %4d-%2d-%2d %2d:%2d:%2d  change \n",
						filename,ptm->tm_year+1900,
						ptm->tm_mon+1,ptm->tm_mday,
						ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
				write_log(logbuff);
				oldtime = newtime ;
			}
		}
		exit(0);
	}
	if(pid[count] >0) return 0;
	if(pid[count] < 0) return -1;
	count ++;	
	return 0;
}


int read_dir(char *dirname)
{
   int ret = 0;
   struct dirent * dt ;
   DIR * dr = opendir(dirname);
   if(NULL == dr)
   {
        return -1;
   }
   chdir(dirname);
   while(1)
   {
	   dt = readdir(dr);
	   if(NULL == dt) break;
	   if(dt->d_name[0] == '.') continue;
	   ret =test_change(dt->d_name);
	   if(ret < 0) 
	   {
	   	  write_log("test_change file error \n");
	   	  return ret;
	   }
   }	

   closedir(dr);
   return 0; 
}



int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage %s [dir] [logfile]\n",argv[0]);
		return -1;
	}
	int ret  =0;
	
	daemon_init();

	fp = fopen(argv[2],"a+");
	if(NULL == fp)
	{
	   perror("fopen log");
	   return -1;
	}
	
	ret  = read_dir(argv[1]);
	if(ret <0)
	{
		write_log("read dir error  \n");
		return 0;
	}


	char cmd[128] ={0};
	struct stat buff ={0};
	stat(argv[1],&buff);
	time_t oldtime = buff.st_mtime;
	while(1)
	{
		sleep(1);
		stat(argv[1],&buff);
		time_t newtime = buff.st_mtime;
		if(oldtime != newtime)
		{
			int i =0;
			for(i=0;i<count;i++)
			{
				sprintf(cmd,"kill -9 %d",pid[i]);
				system(cmd);
				printf("kill cmd = %s\n",cmd);
			}
			count = 0;
			write_log("dir change \n");
	
			ret  = read_dir(argv[1]);
			if(ret <0)
			{
				write_log("read dir error  \n");
				return 0;
			}
			oldtime = newtime ;
		}
	}

	


/*
	ret  = read_dir(argv[1]);
	if(ret <0)
	{
		write_log("read dir error  \n");
		return 0;
	}
*/


	fclose(fp);



	//////////////////////////////////////////
    return 0;
}
