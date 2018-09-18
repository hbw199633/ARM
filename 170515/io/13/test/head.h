/*====================================================
*   Copyright (C) 2017  All rights reserved.
*
*   文件名称：head.h
*   创 建 者：cqb  2848319176@qq.com
*   创建日期：2017年07月27日
*   描    述：
================================================================*/

#ifndef _HEAD_H_
#define _HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

void* shm_init(key_t key,int size);

int shm_exit(key_t key,int size);

int  sem_init(key_t key,int n);

int sem_exit(int semid);


int my_sem_wait(int semid, int sem);

int my_sem_post(int semid, int sem);

#endif 
