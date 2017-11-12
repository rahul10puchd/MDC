// this is decompression function
#include"header.h"
#include"prototype.h"
int decompression(char *open_encr,char *open_key,char *str)
{
//	printf("in function ----->%s\n",__func__);
	int fd,ndc,l;
//		printf("encryption file name is---> %s\n",open_encr);
//	printf("kry file name is---> %s\n",open_key);
//	printf("original file name is---> %s\n",str);
	fd = open(open_key,O_RDONLY);
	printf("fd is--------->%d",fd);
	ndc=lseek(fd,0,SEEK_END);
	l = codelength(ndc);
//	printf("the length of master arry for codelength is ----%d\n",ndc);	
	//printf("the codelength is ---->%d\n",l);
	switch(l)
	{
		case 2:
		printf(".\n..\n...\n.....\n.............Going to perform 2-Bit Deompression\n");
			decompression2(open_encr,open_key,str);
			break;
		case 3:
		printf(".\n..\n...\n.....\n.............Going to perform 3-Bit Deompression\n");
			decompression3(open_encr,open_key,str);
			break;
		case 4:
		printf(".\n..\n...\n.....\n.............Going to perform 4-Bit Deompression\n");
			decompression4(open_encr,open_key,str);
			break;
		case 5:
		printf(".\n..\n...\n.....\n.............Going to perform 5-Bit Deompression\n");
			decompression5(open_encr,open_key,str);
			break;
		case 6:
		printf(".\n..\n...\n.....\n.............Going to perform 6-Bit Deompression\n");
			
			decompression6(open_encr,open_key,str);
			break;
		case 7:
		printf(".\n..\n...\n.....\n.............Going to perform 7-Bit Deompression\n");
			decompression7(open_encr,open_key,str);
			break;
		default:
			printf("\"This file cannot be decompressed or may be some error\"");
			break;
	}
	return 0;
}

