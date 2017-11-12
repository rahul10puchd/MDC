// this is preserve master array function
#include"header.h"
#include"prototype.h"
int preserve_masterarray(char *m,int l,char *str)
{
	int fd1;
	char key1[]=".key";
	char* key;
	key=malloc(strlen(str) + strlen(key1) + 1);
	strcpy(key, str);
    strcat(key, key1);
	fd1 = open(key, O_WRONLY | O_CREAT);
	write(fd1, m ,l);
	close(fd1);
	printf("\n.\n..\n...\n.....\n.......Key is generated for the file %s\n",key);
	return 0;
}
