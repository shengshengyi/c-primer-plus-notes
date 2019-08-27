#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUM 100

char* s_gets(char* str, int n);
/* 报告字符串的单词数，大写字母数，小写字母数，标点符号数，数字字符数，使用ctype.h头文件的函数 */
/* isdigit()数字  ispunct()标点符号  isupper()大写  islower()小写 */
int main(void)
{
	char str[NUM];
	int i = 0;
	int upper = 0, lower = 0, digit = 0, punct = 0;

	printf("entre the long sentence:");
	while (s_gets(str, 100))
		break;


	while (str[i])
	{
		if (isdigit(str[i]))
			digit++;

		else if (ispunct(str[i]))
			punct++;

		else if (isupper(str[i]))
			upper++;

		else if (islower(str[i]))
			lower++;
		
		i++;
	}
	printf("num_digit:%d\n"
		"num_punct:%d\n"
		"num_upper:%d\n"
		"num_lower:%d\n", digit,punct,upper,lower);

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