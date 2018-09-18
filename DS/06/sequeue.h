/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: sequeue.h
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月26日 星期一 11时04分13秒
***************************************************/

#ifndef _SEQUEUE_H_
#define _SEQUEUE_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#define N 10

typedef int datatype;
typedef struct
{
	datatype data[N];
	int		 head;
	int		 tail;
	int		 count;
}sequeue;

extern sequeue *create_sequeue();
extern int enter_sequeue(sequeue *sq,datatype va);
extern int find_sequeue(sequeue *sq,datatype *va,int flag);
extern int chg_sequeue(sequeue *sq,datatype *va,int flag);
extern int exit_sequeue(sequeue *sq,datatype *va);
extern int full_sequeue(sequeue *sq);
extern int empty_sequeue(sequeue *sq);
extern int free_sequeue(sequeue *sq);

#endif
