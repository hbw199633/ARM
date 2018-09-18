/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: main.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月19日 星期一 16时01分46秒
***************************************************/

#include "seqlist.h"

int main(int argc,const char* argv[])
{
	datatype va = 0,old_va = 0;
	int ret = 0,pos = 0;
	seqlist * sq = create_seqlist();
	if(NULL == sq)	return -1;
	while(1)
	{
		printf("请输入数字，0退出\n");
		scanf("%d",&va);
		if(va == 0)		break;	
		ret = add_seqlist(sq,va);
		if(ret == -1)	goto error;
		if(ret == -2)	break;
	}
	show_seqlist(sq);
	//按位置查找
/*	printf("请输入要查找的位置!\n");
	scanf("%d",&pos);
	find_pos_seqlist(sq,pos);
	//按值插入
	printf("请输入要在那一数值之后插入那个数值！\n");
	scanf("%d %d",&old_va,&va);
	inr_va_seqlist(sq,old_va,va);
	show_seqlist(sq);

	//按值修改
	printf("请输入被修改的数值和改后的值！\n");
	scanf("%d %d",&old_va,&va);
	ret =chg_va_seqlist(sq,old_va,va);
	if(ret == -1)	goto error;
	else if(ret == -2)
		printf("没有找到要被修改的值\n");
	show_seqlist(sq);
 //按位置修改	
	printf("请输入被修改的位置和值！\n");
chg_pos:	scanf("%d %d",&pos,&va);
	ret =chg_pos_seqlist(sq,pos,va);
	if(ret == -1)	goto error;
	else if(ret == -2)
	{
		printf("输入的位置有误，请重新输入\n");
		goto chg_pos;
	}
	show_seqlist(sq);
	 //按值删除
	printf("请输入要删除的值\n");
	scanf("%d",&va);
	ret = del_va_seqlist(sq,va);
	if(ret == -1)	goto error;
	else if(ret == -2)	
	{
		printf("empty seqlist\n");
		return -1;
	}
	else if(ret == -3)
		printf("没有该数据\n");
	show_seqlist(sq);
*/
	//按位置删除
	printf("请输入要删除的位置\n");
	scanf("%d",&pos);
	ret = del_pos_seqlist(sq,pos);
	if(ret == -1)	goto error;
	else if(ret == -2)	
	{
		printf("empty seqlist\n");
		return -1;
	}
	else if(ret == -3)
		printf("输入的位置有误\n");
	show_seqlist(sq);

	free_seqlist(sq);
	return 0;

error:
	printf("point send error!\n");
    return -1;
}
