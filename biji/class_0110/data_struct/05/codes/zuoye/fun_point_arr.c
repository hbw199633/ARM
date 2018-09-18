/* ************************************************************************
	> File Name: fun_point_arr.c
	> Function: 
	> Author: hlq
	> Mail: hlqlinux@gmail.com 
	> Created Time: 2017年02月20日 星期一 09时14分13秒
	> Version: v1.0
 ************************************************************************/

#include <stdio.h>


int add(int a, int b, int * result);
int sub(int a, int b, int * result);
int mul(int a, int b, int * result);
int div(int a, int b, int * result);

int main(int argc, const char *argv[])
{
	int (*pfun[4])(int, int, int*) = {add, sub, mul, div};
	int a = 0, b = 0, result = 0;
	if (argc == 2)
	{
		if (!strcmp(argv[1], "--help"))
		{
			printf("input example %s num1 +,-,x,/ num2\n", argv[0]);
			return -1;
		}
	}
	if (argc != 4)
	{
		printf("Usage input error, input example %s num1 +,-,x,/ num2\n", argv[0]);
		return -1;
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	switch(argv[2][0])
	{
	case '+':
		pfun[0](a,b,&result);
		break;
	case '-':
		pfun[1](a,b,&result);
		break;
	case 'x':
		pfun[2](a,b,&result);
		break;
	case '/':
		pfun[3](a,b,&result);
		break;
	default:
		break;
	}
	printf("%d %c %d = %d\n", atoi(argv[1]), argv[2][0], atoi(argv[3]), result);
    return 0;
}

int add(int a, int b, int * result)
{
	if (NULL == result)		return -1;
	*result = a + b;
	return 0;
}

int sub(int a, int b, int * result)
{
	if (NULL == result)		return -1;
	*result = a - b;
	return 0;
}

int mul(int a, int b, int * result)
{
	if (NULL == result)		return -1;
	*result = a * b;
	return 0;
}

int div(int a, int b, int * result)
{
	if (NULL == result)		return -1;
	if (b)
		*result = a / b;
	return 0;
}




