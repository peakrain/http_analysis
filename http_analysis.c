#include"http_analysis.h"
#define size 1024
#define max_size 65535
void analysis(FILE *fp)
{
	char str[size];
	char name[size];
	char value[size];
	char type[10];
	char url[size];
	char version[10];
	char code[10];
	char *flag;
	char body[max_size];
	flag=fgets(str,size,fp);
	if(!flag)
		return;
	while(1)
	{
		if(strncmp(str,"GET",3)==0||strncmp(str,"POST",4)==0)
		{
			sscanf(str,"%s%s",type,url);
			printf("请求头:\n");
			print_info("请求类型",type);
			print_info("url",url);
			while(fgets(str,size,fp)!=NULL&&sscanf(str,"%s",name)!=EOF)
			{
				sscanf(str,"%[^:]:%[^\n]",name,value);
				print_info(name,value);
			}
			strcpy(body,"");
			while(fgets(str,size,fp)!=NULL&&strncmp(str,"HTTP",4)!=0)
				strcat(body,str);
			if(sscanf(body,"%s",name)!=EOF)
				printf("请求体:\n%s",body);
			printf("\n");
		}
		else if(strncmp(str,"HTTP",4)==0)
		{
			sscanf(str,"%*[HTTP/]%s%s",version,code);
			printf("响应头:\n");
			print_info("version",version);
			print_info("code",code);
			while(fgets(str,size,fp)!=NULL&&sscanf(str,"%s",name)!=EOF)
			{
				sscanf(str,"%[^:]:%[^\n]",name,value);
				print_info(name,value);
			}
			strcpy(body,"");
			while(fgets(str,size,fp)!=NULL&&strncmp(str,"POST",4)!=0&&strncmp(str,"GET",3)!=0)
				strcat(body,str);
			if(sscanf(body,"%s",name)!=EOF)
				printf("响应体:\n%s",body);
				
			printf("\n");
			
		}
		else
		{
			flag=fgets(str,size,fp);
			if(!flag)
				break;
		}
	}
}
void print_info(char *name,char *value)
{
	printf("字段名:%s 字段值:%s\n",name,value);
}
