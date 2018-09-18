#ifndef __SEQUEUE_H__
#define __SEQUEUE_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

typedef int datatype;

typedef struct {
	datatype	data[N];
	int tail;
	int head;
}sequeue;


extern sequeue * create_sequeue(void);
extern int free_sequeue(sequeue * q);
extern int isfull_sequeue(sequeue * q);
extern int entry_sequeue(sequeue * q, datatype value);
extern int isempty_sequeue(sequeue * q);
extern datatype exit_sequeue(sequeue * q);
extern int exit_sequeue1(sequeue * q, datatype * data);
extern int show_sequeue(sequeue * q);

#endif
