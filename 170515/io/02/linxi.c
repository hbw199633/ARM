#include <stdio.h>
#include <string.h>

int get_id(char *name)
{
	FILE * fp = fopen(name,"r");
	int count = 0;
	char buff[128] ={0};
	while(1)
	{
		if(NULL == (fgets(buff,sizeof(buff),fp)))
		 break;
		count ++;
	}
	fclose(fp);
	return count;
}


int main()
{
	int ret = 0;
	FILE * fp  = fopen("./abc","a+");
	if(NULL == fp)
	{
	  perror("fopen");
	  return -1;
	}

	int 	id = 1;
	char	name[32] = {0};
	char    addr[128] ={0};


	id = get_id("./abc");
	if(id == 0)
	{
	  fprintf(fp,"id   name   addr \n");
	  id ++;
	}

	while(1)
	{
		bzero(name,sizeof(name));
		bzero(addr,sizeof(addr));
		printf("请输入用户名称和地址\n");
		scanf("%s %s",name,addr);
		ret = fprintf(fp,"%d %s %s \n",id++,name,addr);
		fflush(fp);
	}


	ret = fclose(fp);
	printf("fclose ret = %d\n",ret);
	return  0;

}
