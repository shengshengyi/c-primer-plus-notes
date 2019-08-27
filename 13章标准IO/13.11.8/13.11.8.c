#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 4096

int count_char(const char* buf, char ch);
char* s_gets(char* st, int n);

/*
	1、命令行参数如果小于2	err
	2.只输入了字符
		提示继续输入文件
		接收输入的字符串
		调用count_ch函数
		返回打印
	3.大于等于2
		打开文件
		把文件放到数组里面
		调用count_ch函数接收字符和数组
		返回打印
					2循环

*/
int main(int argc, char* argv[])
{
	FILE* fp;
	char buff[BUFSIZE];
	char ch;
	int ct = 0;

	if (argc < 2)
	{
		fprintf(stderr, "enter err\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		ch = argv[1][0];
		printf("Because enter empty file\n"
			"Print some text\n"
			"Press # to quit:\n");
		while (fgets(buff, BUFSIZE, stdin) != NULL && buff[0]!= '#')
		{
			ct += count_char(buff, ch);
			printf("Next line:\n");
		}
		printf("the character '%c' has appeared %d timers in your input", ch, ct);
	}
	else 
	{
		ch = argv[1][0];
		for (int i = 2; i < argc;i++)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can not open % file\n", argv[i]);
				continue;
			}
			while (fgets(buff, BUFSIZE, fp) != NULL)//这里BUFSIZE换成1也因该可以
			{
				ct += count_char(buff, ch);
			}

			printf("the character %c has appeared %d timers in the file %s \n", ch, ct, argv[i]);
			fclose(fp);
			ct = 0;
		}
	}
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

int count_char(const char* buf, char ch)
{
	int count = 0;
	while (*buf)
	{
		if (*buf == ch)
			count++;
		buf++;
	}
	return count;
}

