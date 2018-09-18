#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct txl
{
	int   id;
	char  name[64];
	long long phone;
	char  addr[256];
};


struct txl  usr[100];

int add_usr(struct txl var)
{
	usr[var.id].id = var.id;
	strcpy(usr[var.id].name,var.name);
	usr[var.id].phone = var.phone;
	strcpy(usr[var.id].addr,var.addr);
}

int add_usr2(struct txl *pvar)
{
	usr[pvar->id].id = pvar->id;
	strcpy(usr[pvar->id].name,pvar->name);
	usr[pvar->id].phone = pvar->phone;
	strcpy(usr[pvar->id].addr,pvar->addr);
}


void show_usr()
{
	int i = 0;
	for(i=0;i<100;i++)
	{
		if(strlen(usr[i].name) <=1) break;
		printf("id = %d name = %s phone = %lld,addr = %s \n",
				usr[i].id,usr[i].name,usr[i].phone,usr[i].addr);
	}

}
struct txl *input1_usr()
{
	struct txl *p = malloc(sizeof(struct txl));
	static int i = 0;
	printf("请输入用户信息，将信息存储到通讯录\n");
	scanf("%s",p->name);
	scanf("%lld",&p->phone);
	scanf("%s",p->addr);
	p->id = i++;
	return p;

}
struct txl  input_usr()
{
//	struct txl *p = malloc(sizeof(struct txl));
	struct txl usr1;
	static int i = 0;
	printf("请输入用户信息，将会存储到通信录\n");
	scanf("%s",usr1.name);
	scanf("%lld",&usr1.phone);
	scanf("%s", usr1.addr);
	usr1.id = i++;	
	return usr1;
}



int main(void)
{

	struct txl *va = NULL;
	while(1)
	{
		if((NULL != va) && (va->id >= 3)) break;
		va = input1_usr();
		//	add_usr(usr1);
		add_usr2(va);
		free(va);	
	}
	show_usr();
	return 0;
}
