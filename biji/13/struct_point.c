/**************************************************
> File Name: struct_point.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月08日 星期三 13时59分13秒
**************************************************/

#include <stdio.h>

typedef struct student
{
	int id;
	char *name;
}STU;

typedef struct person
{
	int id;
	char name[32];
}PER;

int main(int argc,const char* argv[])
{
	STU stu = {1,"zhangsan"};
	STU *pstu = &stu;
	printf("%d %s\n",stu.id,stu.name);
	stu.id = 100;
	stu.name = "lisi";
	printf("%d %s\n",stu.id,stu.name);
	printf("%d %s\n",pstu->id,pstu->name);
	PER per = {5,"wang"};
	PER *pper = &per;
	printf("%d %s\n",per.id,per.name);
	printf("%d %s\n",pper->id,pper->name);
    per.name[0]='W';
	printf("%d %s\n",per.id,per.name);
	printf("%d %s\n",pper->id,pper->name);

	return 0;
}
