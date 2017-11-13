
//this is compression  of 4 byte
#include"header.h"
#include"prototype.h"
int compression4(char *m,char *str,int l)
{
	char encr1[]=".encr";
	
	char* encr;
	
	encr=malloc(strlen(str) + strlen(encr1) + 1);
	

    strcpy(encr, str);
    strcat(encr, encr1);


	int i=0,fd4,fd2,w;
	int loc,d,eof;
	unsigned int n;
	unsigned char ch1,c;
	char byte;
	char *buff;
	c = c ^ c;
	buff = (char *)malloc(sizeof(char)*l);
	if(!buff)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	printf("in function ------> %s\n", __func__);
	printf("the master arraay is -----> %s\n",m);
	printf("the final legth of masterarray is---------------------->%d\n",l);
        preserve_masterarray(m,l,str);	


	fd2 = open(str,O_RDONLY);
	fd4 = open(encr,O_WRONLY | O_CREAT);

	while(1)
	{
		byte = byte ^ byte;
		eof=read(fd2,&ch1,1);
		printf("the ch1----->%c\n",ch1);
		loc = findloc(ch1,m,l);
		printf("the %cth location is-------->%d\n",ch1,loc);
		n = loc;
		n = n << 4;
		byte = byte | n;
		eof=read(fd2,&ch1,1);
		printf("the ch1----->%c\n",ch1);
		loc = findloc(ch1,m,l);
		printf("the %cth location is -------->%d\n",ch1,loc);
		n = loc;
		n = n << 4;
		n = n >> 4;
		byte = byte | n;
		printf("the byte is ---------------------------------->%c\n",byte);

		w = write(fd4,&byte,1);
		if(w!=1)
		printf("CHARACTER IS NOT WRITTEN\n");
		if( eof == 0)
		break;
	}
	printf("fd2-----> %d\n fd4-------->%d\n",fd2,fd4);

	lseek(fd4,0,SEEK_SET);
	read(fd4,buff,l);
	printf("the encryption code is -------->%s\n",buff);
	close(fd2);
	close(fd4);
	return 0;
}

