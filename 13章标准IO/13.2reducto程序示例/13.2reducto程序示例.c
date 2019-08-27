#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 40

int main(int argc,char *argv[])
{
	FILE* in,*out;
	int ch;
	char name[LEN];
	int count = 0;
	
	//�������������
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
	}
	//��������
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Can not open %s files\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	//�������
	strncpy(name, argv[1], LEN - 5);
	name[LEN - 5] = '\0';
	strcat(name, ".red");

	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can not create output file\n");
		exit(3);
	}
	//��������
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);
	//��β����
	if(fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "error in closing files\n");

	return 0;
}



