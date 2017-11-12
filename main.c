// main function------>
#include"header.h"
#include"prototype.h"
int main(int argc, char** argv)
{
//	 printf("in function----->  %s\n",__func__);

	
	int choice;
	char *str;
	str = (char *)malloc(sizeof(char)*25);
	char *str1;
	str1 =malloc(strlen(str) + 1);

	while(1)
	{
		choice = mainmenu();
		operation(choice,str,str1);
	}		
	return 0;
}
