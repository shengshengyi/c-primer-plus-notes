#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME 20
#define BUFSIZE 4096

void copy_file(FILE* dest, FILE* source);
char* s_gets(char* str, int n);
/*
	1.打开cp文件，判断文件是否有内容，有删除（打开方式为wb+）
	2.创建缓冲区

	3.打开源文件，判断①两个文件是否同名，②源文件是否为空 ③正常 创建缓冲区，
	4.调用子函数复制过去
												3.4可否做一个循环？没必要，一个文件复制成一个文件就够了，
	5.关闭文件
*/

int main(void)
{
	FILE* cp_file, * src_file;
	char dest_name[NAME];
	char src_name[NAME];

	puts("Enter the destination file:");
	s_gets(dest_name, NAME);
	if ((cp_file = fopen(dest_name, "wb+")) == NULL)
	{
		fprintf(stderr, "Can not open %s file.\n", dest_name);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(cp_file, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fputs("Can not create output buffer\n", stderr);
		exit(EXIT_FAILURE);
	}
	puts("Enter name of source file (q to quit) :");
	while (s_gets(src_name, NAME) && src_name[0] != 'q')
	{
		if (strcmp(dest_name, src_name) == 0)
			fputs("Can not copy file to itself\n", stderr);
		else if ((src_file = fopen(src_name, "rb")) == NULL)//读模式可否？？
			fprintf(stderr, "Can not open %s file", src_name);
		else
		{
			if (setvbuf(src_file, NULL, _IOFBF, BUFSIZE) != 0)
			{
				fputs("Can not create output buffer\n", stderr);
				continue;
			}
			copy_file(cp_file, src_file);

			if (ferror(cp_file) != 0)
				fprintf(stderr, "Error in reading file %s\n", dest_name);
			if (ferror(src_file) != 0)
				fprintf(stderr, "Error in reading file %s\n", src_name);
			fclose(src_file);

			break;
		}
	}
	
	printf("Copy succeed!\n");
	fclose(cp_file);
	return 0;
}

void copy_file(FILE* dest, FILE* source)
{
	size_t bytes;
	static char temp[BUFSIZE];

	while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
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