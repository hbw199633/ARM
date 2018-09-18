#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

typedef int datatype;

typedef struct {
	datatype data[N];
	int last;			/* 有效数据的个数 */
}seqlist;				/* type */

extern seqlist * create_seqlist(void);	/* 指针函数 */
extern int free_seqlist(seqlist * seq);
extern int add_tail_seqlist(seqlist * seq, datatype value);
extern int show_seqlist(seqlist * seq);
extern int add_pos_seqlist(seqlist * seq, int pos, datatype value);
extern int modify_value_seqlist(seqlist * seq, datatype oldvalue, datatype newvalue);
extern int delete_value_seqlist(seqlist * seq, datatype value);
extern int delete_pos_seqlist(seqlist * seq, int pos);

