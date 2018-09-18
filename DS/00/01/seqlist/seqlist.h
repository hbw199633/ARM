/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: seqlist.h
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月15日 星期四 14时01分50秒
***************************************************/

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef int datatype;
typedef struct
{
	datatype data[N];
	int		 count;
}seqlist;

extern seqlist * create_seqlist();
extern int add_seqlist(seqlist *sq,datatype va);
extern int chg_va_seqlist(seqlist *sq,datatype old_va,datatype new_va);
extern int chg_pos_seqlist(seqlist *sq,int pos,datatype new_va);
extern int inr_va_seqlist(seqlist *sq,datatype old_va,datatype new_va);
extern int show_seqlist(seqlist *sq);
extern int full_seqlist(seqlist *sq);

#endif
