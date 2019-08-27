#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char* select_from_string(char* str1, int len);
char* s_gets(char* st, int leng);
#define SENTENCE "how are you"


int main(void)
{

	char str1[100];
	//char *str_cmp = SENTENCE;
	int len;



	printf("enter the word:");
	while (s_gets(str1, 10) != NULL)
	{
		printf("your word:%s\n", str1);
		break;
	}



	printf("enter the len:");
	while (scanf("%d", &len) != 1);
	printf("your len:%d\n", len);

	printf("***************************\n");
	//select_from_string(str1, len);

	/*
	printf("select word :%s\n"
			"select len :%d\n"
			"complete:%s\n",str1,len,select_from_string(str1, len));
	*/
	select_from_string(str1, len);


	//printf("***************************\n");
	//printf("SENTENCE addr: %p"
	 //      "str_cmp  addr: %p ",SENTENCE,str_cmp);

}

char* select_from_string(char* str1, int len)
{
	char* str;

	str = strstr(SENTENCE, str1);

	//str[len] = '\0';

	for (int i = 0; i < len; i++)
	{
		printf("%c", str[i]);
	}


	//printf("%d %s", strlen(str), str);
	//printf("%c,%c,", str[0], str[1]);
	return str;

}

char* s_gets(char* st, int leng)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, leng, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';

		else
			while (getchar != '\n')
				continue;

	}
	return ret_val;
}


