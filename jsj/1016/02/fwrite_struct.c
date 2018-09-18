/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：fwrite.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年12月11日
*   描    述：
================================================================*/

#include <stdio.h>

struct student
{
	int    id;
	char   name[32];
	float  score;
};


int main(int argc, char *argv[])
{
	FILE * fp = fopen("./b.bin","w+");
	if(NULL == fp)
	{
		perror("fopen file");
		return -1;
	}

	struct student  stu ={1,"zhangsan",100};

	fwrite(&stu,sizeof(stu),1,fp);

	fclose(fp);

    return 0;
}
