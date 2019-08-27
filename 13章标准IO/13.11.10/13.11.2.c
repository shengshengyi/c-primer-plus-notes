
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 4096
#define NAMELEN 40

char* s_gets(char* st, int n);

/*
	1��ͨ�������ķ�ʽ���û������ļ��������ļ��ڵ�λ�ã����븺�������ֵ������
	2�����ļ�
		2.5��ȡ�ļ�����
	3����λ
	4����ӡ���¸����з�֮�������
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


	fseek(fp, 0L, SEEK_END);//��λ��ĩβ
	last = ftell(fp);//���ļ���ʼ����β���ֽ�������last//����ͨ�����ؾ����ļ���ʼ�����ֽ�����ȷ����ǰλ�� 
					//fp����ǰλ�ã��� ��ǰ��λ���ǽ�β�����ص�Ҳ�ǽ�β��Ҳ���Ե����ļ�����
					
	
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
		
		fgets(buf, BUFSIZE, fp);//fgets�Զ���ȡ����һ�����з�������ļ���β�����ȡBUFSIZE-1���ַ�
		puts("The text in that line:");
		fputs(buf, stdout);
		rewind(fp);//�ص���ͷ
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
