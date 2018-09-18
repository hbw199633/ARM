#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

typedef int datatype;

typedef struct {
	datatype	data[N];
	int			top;
}seqstack;


extern seqstack * create_seqstack(void);
extern int free_seqstack(seqstack * s);
extern int push_seqstack(seqstack * s, datatype value);
extern int isfull_seqstack(seqstack * s);
extern int pop_seqstack(seqstack * s, datatype * data);
extern int isempty_seqstack(seqstack * s);
extern datatype get_top_value_seqstack(seqstack * s);
extern int get_top_value_seqstack1(seqstack * s, datatype * data);

#endif
