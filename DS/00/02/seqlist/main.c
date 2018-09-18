/***************************************************
  > Copyright (C) 2017 ==KINGYI== All rights reserved.
  > File Name: main.c
  > Author: Kingyi
  > Mail:joseph2009@163.com 
  > Created Time: 2017年06月15日 星期四 14时01分29秒
 ***************************************************/

#include "seqlist.h"

int main(int argc,const char* argv[])
{
	datatype va = 0,old_va = 0,new_va;
	int ret = 0,pos = 0;
	seqlist *sq = create_seqlist();
	if(sq == NULL) return -1;
	while(1)
	{
		printf("Pls input NUM and 0 exit!\n");
		scanf("%d",&va);
		if(va == 0) break;
		else
		{
			ret = add_seqlist(sq,va);
			if(ret == -1)	goto flag;
			else if(ret == -2) 
			{
				printf("Full seqlist\n");
				break;
			}
		}
	}
	show_seqlist(sq);

/*	//按值修改
	printf("Pls input the value which changed and change what\n");
	scanf("%d %d",&old_va ,&new_va);
	chg_va_seqlist(sq,old_va,new_va);
	show_seqlist(sq);

	//按位置修改
	printf("Pls input the value which changed and pos\n");
	scanf("%d %d",&pos,&new_va);
	chg_pos_seqlist(sq,pos,new_va);
	show_seqlist(sq);

	//按值插入
    printf("Pls input the value which insert and insert what\n");
	scanf("%d %d",&old_va,&new_va);
	inr_va_seqlist(sq,old_va,new_va);
	show_seqlist(sq);
*/	
/*	//按位置插入
inr_pos:    printf("Pls input the value which insert and insert where\n");
	scanf("%d %d",&old_va,&pos);
	if((pos>sq->count)||(pos<0))
	{
		printf("input error\n");
		goto inr_pos;
	}
	inr_pos_seqlist(sq,old_va,pos);
	show_seqlist(sq);
	//按值删除
	printf("Pls input the value which del\n");
	scanf("%d",&old_va);
	del_va_seqlist(sq,old_va);
	show_seqlist(sq);
	//按位置删除
	printf("Pls input the pos which del\n");
	scanf("%d",&pos);
	del_pos_seqlist(sq,pos);
	show_seqlist(sq);

	//按值查找
	printf("Pls input the va which find\n");
	scanf("%d",&va);
	ret = find_va_seqlist(sq,va);
	if(ret == 0)
	{
		printf("Not find the va %d\n",va);
		return -1;
	}
	else if(ret > 0)
		printf("Find the va %d\n",va);
	else if(ret < 0)
		goto flag;
*/
	//按位置查找
	printf("Pls input the pos which find\n");
find_pos:	scanf("%d",&pos);
	ret = find_pos_seqlist(sq,pos);
	if(ret >= 0)
		printf("The pos value is %d\n",sq->data[ret]);
	else if(ret == -1)
		goto flag;
	else if(ret == -2)
	{
		printf("Input error,Please input again!\n");
		goto find_pos;
	}	
	//释放模块
	free_seqlist(sq);
	return 0;
flag:
	printf("point send error\n");
	return -1;
}
