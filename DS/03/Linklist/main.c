/***************************************************
> Copyright (C) 2017 ==KINGYI== All rights reserved.
> File Name: main.c
> Author: Kingyi
> Mail:joseph2009@163.com 
> Created Time: 2017年06月20日 星期二 15时00分09秒
***************************************************/

#include "Linklist.h"

int main(int argc,const char* argv[])
{
	int i =0,pos = 0;
	datatype old_va = 0, va = 0;
	linklist *ls = create_linklist();
    if(ls == NULL)	
	{
		perror("malloc create linklist\n");
		return -1;
	}
	for(i=0;i<10;i++)
	{
		add_linklist(ls,i);
	}
	show_linklist(ls);
	//按值查找
	printf("Pls input the pos\n");
	scanf("%d",&pos);
	find_pos_linklist(ls,pos);
	show_linklist(ls);
	//按值插入
	printf("请输入在某值后添加某值\n");
	scanf("%d %d",&old_va,&va);
	inr_va_linklist(ls,old_va,va);
	show_linklist(ls);
	//按位置插入
	printf("请输入在某位置添加某值\n");
	scanf("%d %d",&pos,&va);
	inr_pos_linklist(ls,pos,va);
	show_linklist(ls);
	//按值删除
	printf("请输入要删除的值\n");
	scanf("%d",&va);
	del_va_linklist(ls,va);
	show_linklist(ls);
	//按位置删除
	printf("请输入要删除的位置\n");
	scanf("%d",&pos);
	del_pos_linklist(ls,pos);
	show_linklist(ls);
	//按值修改
	printf("请输入被修改的值和新值\n");
	scanf("%d %d",&old_va,&va);
	chg_va_linklist(ls,old_va,va);
	show_linklist(ls);
    //按位置修改
	printf("请输入被修改的位置和值\n");
	scanf("%d %d",&pos,&va);
	chg_pos_linklist(ls,pos,va);
	show_linklist(ls);


	free_linklist(ls);
	return 0;
}
