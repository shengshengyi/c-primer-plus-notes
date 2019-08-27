#include <stdio.h>
#include <ctype.h>
#include <string.h>
char* s_gets(char* str, int n);
char get_choice(void);
char get_first(void);
char _p(char* str);
char _u(char* str);
char _l(char* str);
void is_n(void);

#define NUM 100
int main(void)
{
	char str[100];
	char choice;
	char choice1;
	
	printf("enter your sencenter:");
	while (s_gets(str, 100))
		break;
	//printf("%s", str);
/*
	choice1 = get_choice();
	printf(" choice1 :%c\n", choice1);
*/

	while (choice = get_choice())//choice = get_choice() != 'q'会得到一个空字符
	{
		printf(" choice :%c\n", choice);
		switch (choice)
		{
			case 'p':
					_p(str);
					break;
			//case 'P': 
					
	
					

			case 'u':
			case 'U':
					_u(str);
					break;

			case 'l':
			case 'L':	
					break;

			default:printf("err\n");
				break;
		}
	}
	
	return 0;

}

void is_n(void)
{
	while (getchar != '\n')
		continue;
	return;
}

char _u(char* str)
{
	for (int i = 0; i < strlen(str);i++)
	{
		str[i] = toupper(str[i]);
	}
	printf("%s", str);
	return str;

}

char _l(char* str)
{

}
char _p(char* str)
{
	printf("no chance");
	printf("%s", str);
	return str;
}

char get_choice(void)
{
	int ch;
	printf("enter your choice:\n");
	printf("p . nochance   u . upper \n");
	printf("l . lower      q . quit \n");
	
	ch = get_first();
	while (ch != 'p' && ch != 'u' && ch != 'l' && ch != 'q')
	{
		printf("erro\n");
		printf("enter again\n");
		ch = get_first();
		
	}
	//printf("your choice is %c", ch);
	return ch;
}

char get_first(void) 
{
	int ch;


	/*
	while (1)
	{
		ch = getchar();
		if (ch != ' ' && ch != '\t' && ch != '\n')
			break;
	}
	*/
		/*		ch = getchar();
	while (isspace(ch))                                  // isspace（）已经包含检验其是否未非空字符，即只需要while(isspace())则可以判断了
	{
		ch = getchar();
		printf("1");
	}
	*/
	ch = getchar();
	while (getchar() != '\n')
		continue;
	
	return ch;
}

char* s_gets(char* str, int n)
{
	char* ret;
	int i = 0;

	ret = fgets(str, n, stdin);
	
	if (ret[i])
	{
		while (ret[i] != '\n' && ret[i] != '\0')
			i++;
		if (ret[i] == '\n')
			ret[i] == '\0';
		else
			while (getchar() != '\n')
				continue;
	}
}




