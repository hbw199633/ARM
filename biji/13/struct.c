/**************************************************
> File Name: struct.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月08日 星期三 09时27分02秒
**************************************************/

#include <stdio.h>
#include <string.h>

int main(int argc,const char* argv[])
{
	typedef	struct student
	{
		int			id;
		char		name[32];
		float		hight;
	}STU;
	STU stu = {1,"qiaomiao",1.70};
	printf("%d %s %.2f \n",stu.id,stu.name,stu.hight);
	STU *p = &stu;
	printf("%d %s %.2f \n",p->id,p->name,p->hight);

	struct 
	{
		int		id;
		char	name[32];
		float	socre;
	}abc={1,"zhangsan",88},xyz={2,"lisi",90.5};	
/*	struct person
	{
		int				id;
		struct std
		{
			int		  id;
			char	  name[32];
			float	  hight;
		}stu;
		long long      tel;	
	};
	struct person per={1,{20,"qiaomiao",1.70},123456};
	printf("%d %d %s %.2f %lld\n",per.id,per.stu.id,
								  per.stu.name,
								  per.stu.hight,
								  per.tel);
	strcpy(per.stu.name,"zhangsan");
	printf("%d %d %s %.2f %lld\n",per.id,per.stu.id,
								  per.stu.name,
								  per.stu.hight,
								  per.tel);
*/
/*	struct person
	{
		int				id;
		struct std
		{
			int		  id;
			char	  name[32];
			float	  hight;
		}stu;
		long long tel;	
	};
	struct person per={1,{20,"qiaomiao",1.70},12345678910};
	printf("%lld\n",per.tel);
*/    return 0;
}
