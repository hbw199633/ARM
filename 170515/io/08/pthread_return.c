/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：pthread_create.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月20日
*   描    述：
================================================================*/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int id ;
	char name[32];
	float score;
}STU;


void *  fun(void * arg)
{
   printf("fun ... \n");
   static int x = 100;
   printf("fun &x = %p \n",&x);

   static char buff[] ="hello ";
   
   static STU stu = {100,"wang",99.9};

   STU *stu2 = malloc(sizeof(STU));
   stu2->id = 300;
   strcpy(stu2->name,"zhao");
   stu2->score= 88.8;

   return  (void*)99;
}
int main(int argc, char *argv[])
{

	pthread_t tid = 0;
	pthread_create(&tid,NULL,fun,NULL);
    void * ret = NULL;
	pthread_join(tid,&ret);
	printf("ret = %d \n",(int)ret);
	



//	printf("main ret = %p return va = %d \n",
//	                  ret,  *((int*)ret));

	//printf("main ret  = %s \n", (char*)ret);
/*
	STU * pstu = NULL;
	pstu = (STU*)ret;
	printf("main ret id = %d name = %s sc = %f \n",
			//pstu->id,pstu->name,pstu->score);
			((STU*)ret)->id, ((STU*)ret)->name,
			((STU*)ret)->score);
	free(ret);
*/
    return 0;
}
