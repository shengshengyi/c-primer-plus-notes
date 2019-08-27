#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 40

char* s_gets(char* st, int n);

int main(void)
{
	FILE* in,*out;
	int ch;
	char src_name[LEN];
	char des_name[LEN];
	int count = 0;
	int len;
	
	printf("Enter the file you want to copy:\n");
	s_gets(src_name, LEN);
	//设置输入
	if ((in = fopen(src_name, "r")) == NULL)
	{
		fprintf(stderr, "Can not open %s files\n", src_name);
		exit(EXIT_FAILURE);
	}

	//设置输出
	strncpy(des_name, src_name, LEN - 5);
	des_name[LEN - 5] = '\0';
	strcat(des_name, ".red");

	if ((out = fopen(des_name, "w")) == NULL)
	{
		fprintf(stderr, "Can not create output file\n");
		exit(3);
	}
	//拷贝数据
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	//收尾工作
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "error in closing files\n");

	printf("Copy succeed!\n");

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


