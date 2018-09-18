/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: seqlist.h
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月19日 星期一 16时01分53秒
***************************************************/

#ifndef _SEQLIST_H_
#define _SEQLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define N 10

typedef int datatype; 
typedef struct
{
	datatype	data[N];
	int			count;
}seqlist;

seqlist *create_seqlist();
int add_seqlist(seqlist *sq,datatype va);
int find_pos_seqlist(seqlist *sq,int pos);
int inr_va_seqlist(seqlist *sq,datatype old_va,datatype va);
int chg_va_seqlist(seqlist *sq,datatype old_va,datatype va);
int chg_pos_seqlist(seqlist *sq,int pos,datatype va);
int del_va_seqlist(seqlist *sq,datatype va);
int del_pos_seqlist(seqlist *sq,int pos);
int show_seqlist(seqlist *sq);
int full_seqlist(seqlist *sq);
int empty_seqlist(seqlist *sq);
int free_seqlist(seqlist *sq);

#endif
