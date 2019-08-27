#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define ONE 100

char* s_gets(char* str, int n);
char* string_in(char* str1, char* str2);
int main(void)
{
	char str1[ONE];
	char str2[ONE];

	printf("entre the long sentence:");
	while (s_gets(str1, 100))
		break;

	printf("entre the short sentence:");
	while (s_gets(str2, 100))
		break;

	printf("str1 = %s str1 = %s\n", str1, str2);

	string_in(str1, str2);
	string_in("how are you", str2);
	string_in("how are you", "are");


}

char * string_in(char * str1, char * str2)
{
	char* str;
	str = strpbrk(str1, str2);
	printf("%s  %p\n", str, str);
	return str;
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