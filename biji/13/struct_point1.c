/**************************************************
> File Name: struct_point1.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月08日 星期三 14时41分42秒
**************************************************/

#include <stdio.h>
#include <string.h>

typedef struct student
{
	int id;
	char *name;
}STU;
typedef struct person
{
	int id;
	struct student stu;
	char name[32];
	struct student *p;
}PER;
int main(int argc,const char* argv[])
{
	PER per;
	STU std;
	per.p = &std;
	per.id = 1;
	per.stu.id = 2;
	per.stu.name = "zhangsan";
	strcpy(per.name,"zhangsan");
	per.p->id = 3;
	per.p->name = "zhangsan";
	printf("%d %d %s %s %d %s\n",per.id,per.stu.id,
								 per.stu.name,per.name,
								 per.p->id,per.p->name);
    return 0;
}
