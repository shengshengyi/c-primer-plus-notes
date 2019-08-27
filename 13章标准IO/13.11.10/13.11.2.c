
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 4096
#define NAMELEN 40

char* s_gets(char* st, int n);

/*
	1、通过交互的方式让用户输入文件名，和文件内的位置（输入负数或非数值结束）
	2、打开文件
		2.5获取文件长度
	3、定位
	4、打印到下个换行符之间的内容
	*/


int main(void)
{
	char file_name[NAMELEN] = {'\0'};
	unsigned int pos;
	FILE* fp;
	long last;
	char buf[BUFSIZE] = { '\0' };

	printf("enter the file name:");
	while(s_gets(file_name, NAMELEN) == NULL)
		continue;
	//printf("%s!", file_name);
	if ((fp = fopen(file_name, "r")) == NULL)
	{
		fprintf(stderr, "Can't open file %s.\n", file_name);
		exit(EXIT_FAILURE);
	}


	fseek(fp, 0L, SEEK_END);//定位到末尾
	last = ftell(fp);//把文件开始到结尾的字节数赋给last//函数通过返回距离文件开始出的字节数来确定当前位置 
					//fp代表当前位置？？ 当前的位置是结尾，返回的也是结尾，也可以当成文件长度
					
	
	printf("enter the location of the file by Positive integer "
		"eg: 1  2  3:");
	while (scanf("%d", &pos) == 1 && pos >= 0 )
	{
		if (pos > last)
		{
			fprintf_s(stderr, "%d exceeds the number of"
				"text characters.\nEnter one again?\n:", pos);
			continue;
		}
		
		fseek(fp, pos, SEEK_SET);
		
		fgets(buf, BUFSIZE, fp);//fgets自动读取到第一个换行符后面或文件结尾，或读取BUFSIZE-1个字符
		puts("The text in that line:");
		fputs(buf, stdout);
		rewind(fp);//回到开头
		printf("enter the location of the file by Positive integer "
			"eg: 1  2  3:");
	}
	fclose(fp);

	return 0;

}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}
