// this is function for finding the location
#include"header.h"
#include"prototype.h"
int findloc(char ch1, char *m,int l)
{
	int i=0;
	while(i<l)
	{
		if( ch1 == *(m+i))
		{
			return i;
		}
		i++;
	}
		
} 
