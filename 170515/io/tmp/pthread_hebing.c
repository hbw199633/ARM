/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pthread_hebing.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月22日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>


char * file_name = NULL;
FILE * fp  = NULL;

void * fun(void *arg)
{
	int n  = (int)arg;
	int ret = 0;
	char filename[128] ={0};
	sprintf(filename,"%s_%d",file_name,n);
	FILE * fp1  = fopen(filename,"r");
	if(NULL == fp1)
	{
		perror("thread fopen");
		goto exitflag;
	}
	void * ptr = (void *)malloc(4096);
	while(1)
	{
		ret = fread(ptr,1,sizeof(ptr),fp1);
		if(ret <= 0) break;
		fseek(fp,ret*n,SEEK_SET);
		fwrite(ptr,1,ret,fp);
	}
	free(ptr);
	fclose(fp1);
exitflag:
	usleep(100000*n);
	pthread_exit(0);
}


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage %s [filename]  [filenum] \n",argv[0]);
		return -1;
	}
	file_name = argv[1];

	fp  = fopen(argv[1],"w+");
	if(NULL == fp)
	{
		perror("fopen");
		return -1;
	}
	pthread_t tid[100];
	int i = 0,n = atoi(argv[2]);
	for(i=0;i<n;i++)
	{
		pthread_create(&tid[i],NULL,fun,(void*)i);
	}

	for(i=0;i<n;i++)
	{
		pthread_join(tid[i],NULL);
	}

	fclose(fp);

    return 0;
}
