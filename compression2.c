//this is compression  of 4 byte
#include"header.h"
#include"prototype.h"
int compression2(char *m,int l,char *str)
{
	//printf("in function------>%s\n",__func__);
	char encr1[]=".encr";
	
	char* encr;
	
	encr=malloc(strlen(str) + strlen(encr1) + 1);
	

    strcpy(encr, str);
    strcat(encr, encr1);

    int i=0,fd4,fd2,w;
	unsigned int n,count,val;
	int loc,d,eof;
	unsigned char ch1;
	char byte;
	char *buff;
	buff = (char *)malloc(sizeof(char)*l);
	if(!buff)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
//	printf("in function ------> %s\n", __func__);
//	printf("the master arraay is -----> %s\n",m);
	//printf("the final legth of masterarray is---------------------->%d\n",l);
        preserve_masterarray(m,l,str);	
	fd2 = open(str,O_RDONLY);
	count=lseek(fd2,0,SEEK_END);
	lseek(fd2,0,SEEK_SET);
	val=(count/4);
	val = val+1;
	fd4 = open(encr,O_WRONLY | O_CREAT);
	d=0;
	while(1)
	{
		if(i==0 || i>3)
		{
			i = 0;
			byte= byte^byte;
		}
		eof=read(fd2,&ch1,1);
	
		if( eof == 0)
		{
			if(i>0 && d<val)
			{
				write(fd4,&byte,1);
				d++;
//				printf("the byte is written to the file is-------------------->%c && %d\n",byte,byte);
			}
			break;
		}
//		printf("the ch1----->%c\n",ch1);
		loc = findloc(ch1,m,l);
//		printf("the %cth location is--------->%d\n",ch1,loc);
		n = loc;
		if(i==0)
		{
			n = n << 6;
			byte = byte | n;	
		}
		if(i==1)
		{
			n = n << 6;
			n = n >> 2;
			byte = byte | n;	
		}
		if(i==2)
		{
			n = n << 6;
			n = n >> 4;
			byte = byte | n;	
		}
		if(i==3)
		{
			n = n << 6;
			n = n >> 6;
			byte = byte | n;	
		}
		if(i==3 && d<val)
		{
			write(fd4,&byte,1);
			d++;
//			printf("the byte is written to the file is-------------------->%c && %d\n",byte,byte);
		}

		i++;
		


	}
//	printf("fd2-----> %d\n fd4-------->%d\n",fd2,fd4);

	lseek(fd4,0,SEEK_SET);
	read(fd4,buff,l);
//	printf("the encryption code is -------->%s\n",buff);
	close(fd4);
	close(fd2);
	printf("\n.\n..\n...\n.....\n........Encrypted file is generated using 2-Bit Compression named %s\n",encr);
	return 0;
}

