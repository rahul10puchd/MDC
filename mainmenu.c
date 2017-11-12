// this is main menu
#include"header.h"
#include"prototype.h"

int mainmenu()
{
//	 printf("in function----->  %s\n",__func__);

	int a;
	printf("Enter your choice\n 1.COMPRESSION \n 2.DECOMPRESSION \n 3.EXIT\n");
	scanf("%d",&a);
	return a;
}

