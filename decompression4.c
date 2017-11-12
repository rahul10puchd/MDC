// this is decompression ofi 4 byte
#include"header.h"
#include"prototype.h"
int decompression4(char *open_encr,char *open_key,char *str)
{

//	printf("in function----->%s\n",__func__);
	unsigned char *buff=NULL,ch,c,d;
	unsigned int efd,fd2,fd3,i=0,count,count1,length,j,n,r;
	efd=open("compression",O_RDONLY);
//	printf("efd is : %d\n",efd);
	count=lseek(efd,0,SEEK_END);
//	printf("count is : %d\n",count);
	buff=(char*)malloc(sizeof(char)*(count));
	lseek(efd,0,SEEK_SET);
	count1=read(efd,buff,(count));
//	printf("master array is : %s\n and count1: %d\n",buff,count1);
	fd2=open("encrypted_file",O_RDONLY);
	if(fd2!=0)
	printf("ENCRYPTED FILE IS OPENED\n");
	fd3=open("compressed_file",O_RDWR);
	if(fd3!=0)
	{
		printf("main file is opened\n");
	}
	length=lseek(fd2,0,SEEK_END);
//	printf("the total characters in actuall file------>%d \n",length);
	lseek(fd2,0,SEEK_SET);
	for(i=0;i<=(length-1);i++)
	{
		r =read(fd2,&ch,1);
		if(r!=1)
//		printf("character is not read......oops!!\n");
		c = ch;
		d = ch;
		c = c >> 4;
		d = d << 4;
		d = d >> 4;
//		printf("the locationn is ------>%d\n",c);
		write(fd3,(buff+c),1);
//		printf("the written charracter is %c\n",*(buff+c));
	//	sprintf(&n,"%d",d);
//		printf("the location is -------->%d\n",d);
		write(fd3,(buff+d),1);
//		printf("the written character is %c\n",*(buff+d));
	}
	close(fd2);
	close(fd3);
	close(efd);
	return 0;
	
}

