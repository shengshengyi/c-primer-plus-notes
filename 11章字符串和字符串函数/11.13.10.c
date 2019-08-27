#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NUM 100
char* delete_space(char* str);
char* s_gets(char* str, int n);
int main(void)
{
	char str[NUM];

	while (1) 
	{
		printf("entre the  sentence:");
		while (s_gets(str, 100))
			break;
		delete_space(str);
	}
	
}


char* delete_space(char* str)
{
	char arr[NUM];
	int i = 0;
	int j = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			arr[j] = str[i];
			//printf("%c", arr[j]);
			j++;
		}
		
		
		i++;
	}
	arr[j] = '\0';
	printf("%s", arr);
	return arr;
}

char* s_gets(char* str, int n)
{
	char* str_ret;
	int i = 0;
	str_ret = fgets(str, n, stdin);

	if (str_ret)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] != '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return str_ret;
}