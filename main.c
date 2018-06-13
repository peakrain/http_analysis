#include<stdio.h>
#include<string.h>
typedef struct http{
	char name[20];
	char value[100];
}data;
void analysis(char str[]);
void print_info(char *name,char *value);
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
	char str[200];
	data a;
	while(fgets(str,200,fp)!=NULL)
	{
		//printf("%s",str);
		analysis(str);
	}
	fclose(fp);
	return 0;
}
void analysis(char str[])
{
	char head[200];
	char value[200];
	sscanf(str,"%s%s",head,value);
	if(strncmp(head,"GET",3)==0||strncmp(head,"POST",4)==0)
	{
		printf("\n请求头:\n");
		print_info("请求类型",head);
		print_info("url",value);
	}
	else if(strncmp(head,"HTTP",4)==0)
	{
		char version[10];
		printf("\n响应头:\n");
		sscanf(str,"%*[HTTP/]%s",version);
		print_info("version",version);
		print_info("code",value);
	}
	else
	{
		int len=strlen(head);
		int len2=strlen(value);
		int len3=strlen(str);
		if(value[len-1]!=str[len3-1])
			sscanf(str,"%s%[^\n]",head,value);
		if(head[len-1]==':')
		{
			
			head[len-1]='\0';
			print_info(head,value);
		}
		
	}	
}
void print_info(char *name,char *value)
{
	printf("字段名:%s 字段值:%s\n",name,value);
}
