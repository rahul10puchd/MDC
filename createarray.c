// this is create array function

#include"header.h"
#include"prototype.h"
char *createarray(int fd)
{
	char ch;
	int flag;
	char *ma;
	char *p;
	int length,eof;
	ma = (char *)malloc(sizeof(char)*1);
//	printf("in function----->  %s\n",__func__);
	while(1)
	{
		flag = 1;
		eof=read(fd,&ch,1);
//		printf("the character read is -----> %c\n",ch);
		if(eof==0)
		break;
		flag = unique(ma,ch);
		if (flag)
		p = insert(ma,ch);
	}
	close(fd);
	return p;

}
