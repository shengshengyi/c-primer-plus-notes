#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFISZE 4096
#define SLEN 81

void append(FILE* source, FILE* dest);
char* s_gets(char* st, int n);

int main(void)
{
	FILE* fa, * fs;
	int files = 0;
	char file_app[SLEN];
	char file_src[SLEN];
	int ch;
	puts("Enter name of destination file:");
	s_gets(file_app, SLEN);
	if ((fa = fopen(file_app, "a+")) == NULL)
	{
		fprintf(stderr, "Can not open %s file:", file_app);
			exit(EXIT_FAILURE);
	}

	if (setvbuf(fa, NULL, _IOFBF, BUFISZE) != 0)
	{
		fputs("Can not create output buffer\n", stderr);
			exit(EXIT_FAILURE);
	}

	puts("Enter name of first source file(empty line to quir):");
	while (s_gets(file_src, SLEN) && file_src[0] != '\0')
	{
		if (strcmp(file_app, file_src) == 0)//源文件和目标文件相同，跳至下个文件
			fputs("Can not append file to itself\n", stderr);
		else if((fs = fopen(file_src, "r")) == NULL)//读模式无法打开，跳至下个文件
			fprintf(stderr, "Can not open %s file", file_src);
		else
		{
			if (setvbuf(fs, NULL, _IOFBF, BUFISZE) != 0)
			{
				fputs("Can not create output buffer\n", stderr);
				continue;
			}
			append(fs, fa);
			if (ferror(fs) != 0)
				fprintf(stderr, "Error in reading file %s\n", file_src);
			if (ferror(fa) != 0)
				fprintf(stderr, "Error in reading file %s\n", file_app);

			fclose(fs);
			files++;
			printf("File %s appended successed\n", file_src);
			puts("Add next file(empty line to quit):");
		}
	}
	printf("Done appending. %d files appended.\n", files);
	rewind(fa);
	printf("%s contents:\n", file_app);
	while (ch = getc(fa) != EOF)
		putchar(ch);
	puts("Done displaying.");
	fclose(fa);

	return 0;

}

void append(FILE* source, FILE* dest)
{
	size_t bytes;
	static char temp[BUFISZE];

	while ((bytes = fread(temp, sizeof(char), BUFISZE, source)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);

	
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