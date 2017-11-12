// this is operation function
#include"header.h"
#include"prototype.h"

int operation(int c,char *str,char *str1)
{
	int cl;
	
	char *open_encr;
	char *open_key;
	open_encr = (char *)malloc(sizeof(char)*20);
	open_key = (char *)malloc(sizeof(char)*20);


//	printf("in function----->  %s\n",__func__);
	switch(c)
	{
		case 1:
		printf("ENTER THE  FILE NAME :\n");
		scanf("%s",str);
		printf("Entered file name is---> %s\n",str);
		str1=str;	
			cl = compression(str);
		break;
		case 2:
		printf("Enter the encrypted file:\n");
		scanf("%s",open_encr);
		printf("Enter the key of encryption file:\n");
		scanf("%s",open_key);
		strcpy(str1, str);
//printf("in decompression option file name is---> %s\n",str1);
		decompression(open_encr,open_key,str1);
			break;
		case 3:
			exit(EXIT_FAILURE);
			break;
		default:
			printf("you entered wrong choice\n");
			break;
	}
	return 0;
}
