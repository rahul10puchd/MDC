//this is compression  of 3 byte
#include"header.h"
#include"prototype.h"
int compression5(char *m,int l,char *str)
{

	char encr1[]=".encr";
	
	char* encr;
	
	encr=malloc(strlen(str) + strlen(encr1) + 1);
	

    strcpy(encr, str);
    strcat(encr, encr1);

    
//	printf("in function------>%s\n",__func__);
	int i=0,fd4,fd2,w,g;
	unsigned int n,count,val,new,d;
	int loc,x,eof;
	unsigned char ch1;
	unsigned char byte;
	char *buff;
	buff = (char *)malloc(sizeof(char)*l);
	if(!buff)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

//	printf("the master arraay is -----> %s\n",m);
//	printf("the final legth of masterarray is---------------------->%d\n",l);

        preserve_masterarray(m,l,str);	
	fd2 = open(str,O_RDONLY);
	count=lseek(fd2,0,SEEK_END);
	lseek(fd2,0,SEEK_SET);

	val=(count*0.625);
	if(count%8 != 0)
	val = val+1;
//	printf("the no. of characters in actual file is & the encrypted file will be---------------------->%d & %d\n",count,val);
	
	fd4 = open(encr,O_WRONLY | O_CREAT);
	d=0,w=0;
	while(1)
	{
		if(i==0 || x==0)
		{
			byte= byte^byte;
		}
		if(i==0 || i==1 || i==3 || i==4 || i==6 || i==8 || i==9 || i==11 )
		{
			eof=read(fd2,&ch1,1);
//			printf("the ch1----->%c\n",ch1);
			loc = findloc(ch1,m,l);
//			printf("the %cth location is--------->%d\n",ch1,loc);
			n = loc;
			if(eof==1)
			{	
				w++;
//				printf(" the %d th character is read from file\n",w);	
			}
		}
		if( eof==0)
		{
			if(i>0 && d<val)
			{
				write(fd4,&byte,1);
//				printf("the last byte is written to the file is-------------------->%c && %d\n",byte,byte);
				d++;
			}
			break;
		}


		if(i==0)
		{
			n = n << 3;
			byte = byte | n;	
		}
		if(i==1)
		{
			new = n;
			n = n << 3;
			n = n >> 5;
			byte = byte | n;	
		}
		if(i==2)
		{
			new = new << 6;
			byte = byte | new;
		}
		if(i==3)
		{
			n = n << 3;
			n = n >> 2;
			byte = byte | n;	
		}
		if(i==4)
		{
			new = n;
			n = n << 3;
			n = n >> 7;
			byte = byte | n;	
		}
		if(i==5)
		{
			new = new << 4;
			byte = byte | new;	
		}
		if(i==6)
		{
			new = n;
			n = n << 3;
			n = n >> 4;
			byte = byte | n;	
		}
		if(i==7)
		{
			new = new << 7;
			byte = byte | new;	
		}
		if(i==8)
		{
			n = n << 3;
			n = n >> 1;
			byte = byte | n;	
		}
		if(i==9)
		{
			new = n;
			n = n << 3;
			n = n >> 6;
			byte = byte | n;	
		}
		if(i==10)
		{
			new = new << 5;
			byte = byte | new;	
		}
		if(i==11)
		{
			n = n << 3;
			n = n >> 3;
			byte = byte | n;	
		}
		
		if(i==1 || i==4 || i==6 || i==9 || i==11)
		{
			if(d<val)
			{
				write(fd4,&byte,1);
				x=0;
				d++;
//				printf("the byte is written to the file is-------------------->%c && %d && %d\n",byte,byte,d);
			}
		}
		else
		x=1;
//		printf("value of i ----------------------------------->>>>>>>>%d\n",i);
		i++;
		if(i==12)
		i=0;
		


	}
//	printf("fd2-----> %d\n fd4-------->%d\n",fd2,fd4);

	lseek(fd4,0,SEEK_SET);
	read(fd4,buff,l);
//	printf("the encryption code is -------->%s\n",buff);
	close(fd4);
	close(fd2);
	printf("\n.\n..\n...\n.....\n........Encrypted file is generated using 5-Bit Compression named %s\n\n",encr);
	return 0;
}

