#include"http_analysis.h"
#include<stdio.h>
#include<string.h>
#define size 800
int main(int argc,char *argv[])
{
	FILE *fp=NULL;
	char *filename=NULL;
	if(argc>=2)
		filename=argv[1];
	else
	{
		printf("syntax error\n");
		return -1;
	}
	fp=fopen(filename,"r");
	analysis(fp);
	fclose(fp);
	return 0;
}
