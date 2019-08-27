#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define ONE 100

int is_within(int c, char* str);
char* s_gets(char* str, int n);

int main(void)
{
	char str[ONE];
	char c;

	printf("entre the long sentence:");
	while (s_gets(str, 100))
		break;

	printf("entre the choise ch:");
	while (scanf("%c",&c))
		break;


	printf("%d",is_within(c,str));

}

int is_within(char c, char* str)
{
	char* str1;
	str1 = strchr(str, c);
	if (str1 != NULL)
		return 1;
	else  return 0;
}

char* s_gets(char* str, int n)
{
	char *str_ret;
	int i = 0;
	str_ret = fgets(str, n,stdin);

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