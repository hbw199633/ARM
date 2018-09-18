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

int i = 3;
void *  fun(void * arg)
{
   printf("fun ... \n");
   pthread_t ftid = pthread_self();
   printf("ftid = %lu i= %d\n",ftid,i);
   i++;
   sleep(i);
   printf("tid = %lu exit \n",pthread_self());
   pthread_exit((void*)ftid);
   //return NULL;
}
int main(int argc, char *argv[])
{

	pthread_t tid[5] ={0};
	
	pthread_create(&tid[1],NULL,fun,NULL);
	pthread_create(&tid[2],NULL,fun,NULL);
	pthread_create(&tid[3],NULL,fun,NULL);
	pthread_create(&tid[4],NULL,fun,NULL);
	pthread_create(&tid[0],NULL,fun,NULL);

	int i = 0,n =0,c= 0;
	void *ret  = 0;
	while(1)
	{
		for(i=0;i<5;i++)
		{

			n = pthread_tryjoin_np(tid[i],&ret);
			if(n== 0)
			{
		    	printf("ret = %lu \n",(unsigned long int)ret);
				c++;
			}
		}
		if(c == 5) break;
	}



/*
	int ret =pthread_join(tid1,NULL);
	printf("ret1 = %d \n",ret);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	pthread_join(tid5,NULL);
	printf("ret5 = %d \n",ret);
*/


   while(1)
   {
   	  printf("main ... run... \n");
	  sleep(1);
   }



    return 0;
}
