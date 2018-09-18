/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：a.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月27日
*   描    述：
================================================================*/

#include  "head.h"


int main(int argc, char *argv[])
{
	key_t key = 0x999;

	char * p = shm_init(key,128);

	int	 semid = sem_init(key,1);

	while(1)
	{
		printf(">>"); fflush(NULL);
		scanf("%s",p);
		my_sem_post(semid,0);
		if(!strcmp(p,"quit")) break;
	}

	shm_exit(key,128);

	sem_exit(semid);

    return 0;
}
