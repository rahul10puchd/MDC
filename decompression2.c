// this is decompression of 2 bytei
#include"header.h"
#include"prototype.h"
int decompression2(char *open_encr,char *open_key,char *str)
{

	//printf("in function----->%s\n",__func__);
	
	unsigned char *buff=NULL,ch,d,c,e,f;
	unsigned int efd,efd2,fd2,fd3,i=0,count,count1,length,j,n,r;	
	
char decr1[]=".decompressed";
	
	char *decr;
	
	decr=malloc(strlen(str) + strlen(decr1) + 1);
	

    strcpy(decr, str);
    strcat(decr, decr1);
   printf("decompressed file name is....................... %s\n",decr);
	efd=open(open_key,O_RDONLY);
	efd2=open(str,O_RDONLY);
	fd2=open(open_encr,O_RDONLY);
	fd3=open(decr,O_WRONLY | O_CREAT);

	count=lseek(efd2,0,SEEK_END); 
	count1=lseek(efd,0,SEEK_END); //master array
	length=lseek(fd2,0,SEEK_END); //encrypted file
	lseek(efd2,0,SEEK_SET);
	lseek(efd,0,SEEK_SET);
	lseek(fd2,0,SEEK_SET);
	
//	printf("no. of characters in actual file && encrypted file is : %d && %d\n",count,length);
	buff=(char*)malloc(sizeof(char)*(count1));

	count1=read(efd,buff,(count1));
//	printf("master array is : %s\n and no. of characters-----: %d\n",buff,count1);
	j=1;
//	count =  count-1;
	while(i<length)
	{
		r =read(fd2,&ch,1);
		if(r=1)
		{	
//			printf("character is read......yeah!----->%c && %d\n",ch,ch);
			c = ch;
			d = ch;
			e = ch;
			f = ch;
			c = c >> 6;
			d = d << 2;
			d = d >> 6;
			e = e << 4;
			e = e >> 6;
			f = f << 6;
			f = f >> 6;
		}
//		else
//			printf("character is not readed from file....oops!!\n");
	
		

		if(j<count)
		{
			
//			printf("the locationn is ------>%d\n",c);
			write(fd3,(buff+c),1);
//			printf("the written charracter is %c\n",*(buff+c));
//			printf("the no. of characters had witten---->%d\n",j);
			j++;
		}


		if(j<count)
		{
//			printf("the location is -------->%d\n",d);
			write(fd3,(buff+d),1);
//			printf("the written character is %c\n",*(buff+d));
//			printf("the no. of characters had witten---->%d\n",j);
			j++;
		}

		

		if(j<count)
		{
//			printf("the locationn is ------>%d\n",e);
			write(fd3,(buff+e),1);
//			printf("the written charracter is %c\n",*(buff+e));
//			printf("the no. of characters had witten---->%d\n",j);
			j++;
		}



		if(j<count)
		{
//			printf("the location is -------->%d\n",f);
			write(fd3,(buff+f),1);
//			printf("the written character is %c\n",*(buff+f));
//			printf("the no. of characters had witten---->%d\n",j);
			j++;
		}

		i++;
	}
	close(fd2);
	close(fd3);
	close(efd);
	return 0;
	
}

