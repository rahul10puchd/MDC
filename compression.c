// this is compression function
#include"header.h"
#include"prototype.h"

int compression(char *str)
{
	//char *m[1];
	//char *str;
	int fd,l,c;
	char *m;
//	 printf("in function----->  %s\n",__func__);
 	//str = (char *)malloc(sizeof(char)*10);
	while(fd != 3)
	{
//		printf("ENTER THE  FILE NAME :\n");
  //    		scanf("%s",str);
	//	printf("Entered file name is---> %s\n",str);
//		exit (0);
		fd = open(str, O_RDONLY);
		if(fd == 3)
		printf("\n");
		else
		{
			printf("invalid filename\n");
			exit (0);
		}
	}
	m = createarray(fd);
	l = strlen(m);
	printf("final length of  master array  is ---------> %d\n",l);
//	printf("master arraay  is -----> %s\n",m);
	c = codelength(l);
	switch(c)
	{
		case 2:
		{
			printf("\n.\n..\n...\n.....\n.............Going to perform 2-Bit Compression\n");
			compression2(m,l,str);
			break;
		}
		case 3:
		{
			printf("\n.\n..\n...\n.....\n.............Going to perform 3-Bit Compression\n");
			compression3(m,l,str);
			break;
		}
		case 4:
		{
			printf("\n.\n..\n...\n.....\n.............Going to perform 4-Bit Compression\n");
			compression4(m,str,l);
			break;
		}
		case 5:
		{
			printf("\n.\n..\n...\n.....\n.............Going to perform 5-Bit Compression\n");
			compression5(m,l,str);
			break;
		}
		case 6:
		{
			printf("\n.\n..\n...\n.....\n.............Going to perform 6-Bit Compression\n");
			compression6(m,l,str);
			break;
		}
		case 7:
		{
			printf("\n.\n..\n...\n.....\n.............Going to perform 7-Bit Compression\n");
			compression7(m,l,str);
			break;
		}
		default :
		printf("IT IS ALREADY COMPRESSED!!\n");
	}
	
	return l;
	
}

