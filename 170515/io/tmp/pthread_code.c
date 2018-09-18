/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pthread_code.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月22日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

pthread_t tid[100] = {0};
int 	  count = 0;
long      total  = 0;

int code_file(char *filename)
{
	if(NULL == filename)  return 0;
	int len = strlen(filename);
	if( (filename[len-1] == 'c')  && 
		(filename[len-2] == '.'))
		return 1;
	else
		return 0;
}

void * fun(void * arg)
{
	long  len  = 0;
	char   buff[256] ={0};
	char *file = (char *)arg;
	FILE * fp = fopen(file,"r");
	if(NULL == fp)
	{
		perror("fopen");
		pthread_exit(0);
	}
	while(1)
	{
		if(NULL == fgets(buff,sizeof(buff),fp)) break;
		len ++;
	}
	printf(" %s code line  %ld \n",file,len);
	total = total + len;
	fclose(fp);
	pthread_exit(0);
}


int pthread_count(char * filename)
{
	pthread_create(&tid[count],NULL,fun,filename);
	count ++;
}



int main(int argc, char *argv[])
{

	if(argc != 2)
	{
		printf("Usage %s [dir] \n",argv[0]);
		return -1;
	}

	int j = 0;
	struct dirent *dt  = NULL;
	DIR * dr = opendir(argv[1]);	
	if(NULL == dr)
	{
		perror("dir");
		return -1;
	}
	chdir(argv[1]);
	while(1)
	{
		dt = readdir(dr);
		if(NULL == dt) break;
		if(dt->d_name[0] == '.') continue;
		if(code_file(dt->d_name))
		{
			pthread_count(dt->d_name);
		}

	}
	
	for(j=0;j<count;j++)
	{
		pthread_join(tid[j],NULL);
	}
	printf("all code line = %ld \n",total);
	closedir(dr);
    return 0;
}
