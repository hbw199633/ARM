/*====================================================
*   Copyright (C) 2018  All rights reserved.
*
*   文件名称：mysemop.c
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2018年01月05日
*   描    述：
================================================================*/



int my_sem_wait(int semid, int semnum)
{
	struct sembuf  sem;
	sem.sem_num = semum;
	sem.sem_op  = -1;
	sem.sem_flg = 0;
	semop(semid,&sem,1);
}

int my_sem_post(int semid,int semnum)
{
	struct sembuf  sem;
	sem.sem_num = semum;
	sem.sem_op  = 1;
	sem.sem_flg = 0;
	semop(semid,&sem,1);
}
