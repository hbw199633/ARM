/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：zuoye2.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月12日
*   描    述：
================================================================*/

#include <stdio.h>
#include <stdlib.h>
int get_file_size(char * file)
{
	FILE * fp = fopen(file,"r");
	int n = 0,c = 0;
	while(1)
	{
		c = fgetc(fp);
		if(EOF == c) break;
		n++;
	}
	fclose(fp);
	//printf("get file size  = %d \n",n);
	return n;
}


int split_file(char *arg,FILE * fp,int size,int num)
{
	char filename[128] ={0};
	sprintf(filename,"%s_%d",arg,num);
	FILE * fp2 = fopen(filename,"w+");
	char *pb = malloc(size);

	int ret = fread(pb,1,size,fp);
	fwrite(pb,1,ret,fp2);

	free(pb);
	fclose(fp2);
	return 0;
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage %s [file] [num] \n",argv[0]);
		return -1;
	}
	
	int size = get_file_size(argv[1]);
	int size2 = atoi(argv[2]);
	int num = size/size2;
	int flag = size%size2;
	int i = 0;
	FILE * fp2 = fopen(argv[1],"r");

	for(i=0;i<size2-1;i++)
	{
		split_file(argv[1],fp2,num,i+1);
	}
		
	split_file(argv[1],fp2,size,i+1);

	fclose(fp2);

    return 0;
}
