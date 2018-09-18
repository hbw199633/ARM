/**************************************************
> File Name: struct_arr2.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月08日 星期三 16时54分56秒
**************************************************/
#include <stdio.h>
#define MAX 128

typedef struct student
{
	int		id;
	char	name[32];
	float	score;
}STU;

int count;

int Input_mode(STU *p)
{
		printf("please input the message of student about name score! Input 0 exit\n");
		scanf("%s",p->name);
		if(strcmp(p->name,"0")==0)
			return -1;
		scanf("%f",&p->score);
		p->id=++count;
		return 0;
}

int Out_put(STU stu)
{
	printf("%d %s %.2f\n",stu.id,stu.name,stu.score);
}

int main(int argc,const char* argv[])
{
	STU stu[MAX];
	int i = 0 ,ret = 0;
	for(i=0;i<MAX;i++)
	{
		ret = Input_mode(&stu[i]);
		printf("%s %f\n",stu[i].name,stu[i].score);
		if(ret) break;
	}
	for(i=0;i<count;i++)
		Out_put(stu[i]);
    return 0;
}
