#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME 100
#define BUFSIZE 4096


char* s_gets(char* str, int n);
void display_file(FILE* fp);
//按顺序在屏幕上显示命令行中列出的所有文件，使用argc控制循环

int main(int argc,char *argv[])
{
	FILE* file;
	char file_name[NAME];
	int i = 1;
	
	

	for(i;i<argc;i++)
	{
		
		if ((file = fopen(argv[i], "r")) == NULL)//读模式可否？？
			fprintf(stderr, "Can not open %s file", argv[i]);
	
			
			if (setvbuf(file, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can not create output buffer\n", stderr);
				continue;
			}
			
			printf("no.%d : %s contents:\n", i, argv[i]);

			display_file(file);
			//i++;
			printf("\n");
		
			fclose(file);
		
	}
	
	return 0;
}

//假设文件已打开，显示文件
void display_file(FILE* fp)
{
	static char ch[BUFSIZE];
	while ((fgets(ch, 256, fp)) != NULL)
		fputs(ch, stdout);
		
	
	
}

char* s_gets(char* str, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n');
	}
	return ret_val;
}


