// this is unique function
#include"header.h"
#include"prototype.h"
int unique(char *ma,char ch)
{
	int ndc;
	int i=0;
//	printf("in function----->  %s\n",__func__);
	ndc = strlen(ma);
	while(i<ndc)
	{
		if(ch == *(ma+i))
		return 0;
		i++;
	}
	return 1;
}
