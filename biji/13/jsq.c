/**************************************************
> File Name: jsq.c
> Author: Kingyi
> Mail: joseph2009@163.com 
> Created Time: 2017年02月09日 星期四 09时17分08秒
**************************************************/

#include <stdio.h>

typedef struct jsq_pro
{
	int a;
	char b;
	int c;
	int ret;
}JSQ;
int add(JSQ *p);
int sub(JSQ *p);
int div(JSQ *p);
int mul(JSQ *p);
int Input_mode(JSQ *p);
int Luoji_mode(JSQ *p);
int Out_put(JSQ *p,int a);

int add(JSQ *p)
{
	p->ret = p->a + p->c;
}

int sub(JSQ *p)
{
	p->ret = p->a - p->c;
}

int mul(JSQ *p)
{
	p->ret = p->a * p->c;
}

int div(JSQ *p)
{
	if(p->c == 0)
		return -1;
	else
		p->ret = p->a / p->c;
}

int Input_mode(JSQ *p)
{
	printf("please in put a +-*/ b\n");
	scanf("%d %s %d",&p->a,&p->b,&p->c);
}

int Luoji_mode(JSQ *p)
{
	int a;
	switch(p->b)
	{
		case '+':add(p);break;
		case '-':sub(p);break;
		case '*':mul(p);break;
		case '/':a = div(p);break;
		default:printf("error\n");
	}
	return a;
}

int Output_mode(JSQ *p,int a)
{
	if(a == -1)
		printf("分母不能为0!\n");
	else
		printf("%d\n",p->ret);
}

int main(int argc,const char* argv[])
{
	JSQ jsq = {0};
	int ret = 0;

	Input_mode(&jsq);
	ret = Luoji_mode(&jsq);
	Output_mode(&jsq,ret);
    return 0;
}
