// this is insert function
#include"header.h"
#include"prototype.h"
char * insert(char *ma, char ch)
{
	int ndc;
//	int *ptr;
//	 printf("in function----->  %s\n",__func__);
	ma=realloc(ma,ndc+2);
	*(ma+ndc)=ch;
	*(ma+ndc+1)= '\0';
	ndc=strlen(ma);
//	printf("the maasterarray is  ---------------->%s\n",ma);
//	printf("the length of masterarray is-------->>%d\n",ndc);
	return ma;
}
