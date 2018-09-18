/**************************************************
> File Name: struct_arr.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月08日 星期三 15时56分16秒
**************************************************/

#include <stdio.h>
#define MAX 3

typedef struct student
{
	int		id;
	char	name[32];
	float	score;
}STU;

int main(int argc,const char* argv[])
{
	STU stu[MAX];
	int i = 0;
	for(i=0;i<MAX;i++)
	{
		printf("please input the message of student about id name score!\n");
		scanf("%d %s %f",&stu[i].id,stu[i].name,&stu[i].score);
	}
	for(i=0;i<MAX;i++)
		printf("%d %s %.2f\n",stu[i].id,stu[i].name,stu[i].score);
	
    return 0;
}
