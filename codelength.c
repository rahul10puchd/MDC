#include"header.h"
#include"prototype.h"
int codelength(int l)
{
	if(l>=0 && l<=4)
	{
		return 2;
	}
	else if(l>=5 && l<=8)
	{
		return 3;
	}
	else if(l>=9 && l<=16)
	{
		return 4;
	}
	else if(l>=17 && l<=32)
	{
		return 5;
	}
	else if(l>=33 && l<=64)
	{
		return 6;
	}
	else if(l>=65 && l<=128)
	{
		return 7;
	}
	else
	printf("THIS FILE CANNOT BE COMPRESSED!!\n");
	return l;

}
