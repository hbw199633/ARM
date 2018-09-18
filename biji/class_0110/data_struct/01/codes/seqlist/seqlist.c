/* ************************************************************************
	> File Name: seqlist.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月13日 星期一 14时10分43秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

typedef int datatype;

typedef struct {
	datatype data[N];
	int last;			/* 有效数据的个数 */
}seqlist;				/* type */


seqlist * create_seqlist(void);	/* 指针函数 */
int free_seqlist(seqlist * seq);
int add_tail_seqlist(seqlist * seq, datatype value);
int show_seqlist(seqlist * seq);
int add_pos_seqlist(seqlist * seq, int pos, datatype value);
int modify_value_seqlist(seqlist * seq, datatype oldvalue, datatype newvalue);
int delete_value_seqlist(seqlist * seq, datatype value);


/******************* main函数  *******************/
int main(int argc, const char *argv[])
{
	seqlist * seq = create_seqlist();
	if (NULL == seq)	return -1;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		add_tail_seqlist(seq, 1);
		add_tail_seqlist(seq, 2);
	}
	show_seqlist(seq);
	delete_value_seqlist(seq, 2);
	show_seqlist(seq);

	free_seqlist(seq);
    return 0;
}


/******************* 创建顺序表函数  *******************/
/* 创建顺序表 */
seqlist * create_seqlist(void)	/* 指针函数 */
{
	seqlist * seq = (seqlist *)malloc(sizeof(seqlist));
	if (NULL == seq)		return NULL;
	bzero(seq, sizeof(seqlist));
	seq->last = 0;
	return seq;
}

/******************* 释放顺序表函数  *******************/
int free_seqlist(seqlist * seq)
{
	if (NULL == seq)	return -1;
	free(seq);
	return 0;
}

/******************* 打印顺序表函数  *******************/
/* 打印顺序表 */
int show_seqlist(seqlist * seq)
{
	if (NULL == seq)	return -1;
	int i = 0;
	for (i = 0; i < seq->last; i++)
	{
		printf("%d ", seq->data[i]);
	}
	printf("\n");
	return 0;
}


/******************* 尾部增加函数  *******************/
int add_tail_seqlist(seqlist * seq, datatype value)
{
	if (NULL == seq)		return -1;
	seq->data[seq->last] = value;
	seq->last++;

	return 0;
}


/******************* 按位置插入函数  *******************/
int add_pos_seqlist(seqlist * seq, int pos, datatype value)
{
	if (NULL == seq)		return -1;
	if (pos >= seq->last)	return -1;
	int i = 0;
	for (i = seq->last; i > pos - 1; i--)
	{
		seq->data[i] = seq->data[i-1];
	}
	seq->data[i] = value;
	seq->last++;

	return 0;
}

/******************* 修改函数  *******************/
int modify_value_seqlist(seqlist * seq, datatype oldvalue, datatype newvalue)
{
	if (NULL == seq)		return -1;
	int i = 0;
	for (i = 0; i < seq->last; i++)
	{
		if (oldvalue == seq->data[i])
		{
			seq->data[i] = newvalue;
		}
	}
	return 0;
}


/******************* 按值进行删除函数  *******************/

int delete_value_seqlist(seqlist * seq, datatype value)
{
	if (NULL == seq)		return -1;
	int i = 0, j = 0;
	for (i = 0; i < seq->last;)
	{
		if (value == seq->data[i])
		{
			for (j = i; j < seq->last; j++)
			{
				seq->data[j] = seq->data[j+1];
			}
			seq->data[j] = 0;
			seq->last--;
		}
		if (value == seq->data[i])
			continue;
		i++;
	}
	return 0;
}





