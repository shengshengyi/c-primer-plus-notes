#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUM 100

char* s_gets(char* str, int n);
/* �����ַ����ĵ���������д��ĸ����Сд��ĸ�������������������ַ�����ʹ��ctype.hͷ�ļ��ĺ��� */
/* isdigit()����  ispunct()������  isupper()��д  islower()Сд */
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