#include <stdio.h>

int itoa(int a,char *s)
{
  sprintf(s,"%d",a);
  return 0;
}

int main()
{
	char buff[32] ={0};
	int a = 888;
	//	sprintf(buff,"%d",a);
	itoa(a,buff);
	printf("buff = %s\n",buff);

	char *s = "nihao";
	sprintf(buff,"%s",s);
	printf("buff = %s \n",buff);

	sprintf(buff,"wohao");
	printf("buff = %s \n",buff);

	return 0;
}
