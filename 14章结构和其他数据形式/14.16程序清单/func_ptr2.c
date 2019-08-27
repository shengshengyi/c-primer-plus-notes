#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef void (*V_FP_CHARP)(char*);


#define LEN 81

char showmenu(void);
void eat_line(void);
void ToUpper(char* str);
void ToLower(char* str);
void Dummy(char* str);
void Transpose(char* str);
//void show(void (*fp)(char*), char* str);
char* s_gets(char* str, int n);

void show(V_FP_CHARP fp, char* str);

/*
	还可以这样写
	typedef void (*V_FP_CHARP )(char *);
	void show(V_FP_CHARP fp,char *);
	V_FP_CHARP pfun;
	*/
int main(void)
{
	char line[LEN];
	char copy[LEN];
	char choice;
	//void (*pfun)(char*) = Dummy;
	V_FP_CHARP pfun = Dummy;

	puts("Enter a string (empty line to quit):");
	while (s_gets(line, LEN) != NULL && line[0] != '\0')
	{
		while ((choice = showmenu()) != 'n')
		{
			switch (choice)
			{
			case 'u':
				pfun = ToUpper;
				break;
			case 'l':
				pfun = ToLower;
				break;
			case 't':
				pfun = Transpose;
				break;
			case 'o':
				pfun = Dummy;
				break;
			default:
				break;
			}
			strcpy(copy, line);
			show(pfun, copy);
		}
		puts("Enter a string (empty line to quit):");
	}
	puts("Bye!");
	return 0;

}

char showmenu(void)
{
	char ans;
	puts("Enter menu choice:");
	puts("u)	uppercase			l)lowercase");
	puts("t)	transposed case		o)original case");
	puts("n)	next string");
	ans = getchar();
	ans = tolower(ans);
	eat_line();
	while (strchr("ulton", ans) == NULL)
	{
		puts("Please enter a, u, l, t, o, or n:");
		ans = tolower(getchar());
		eat_line();
	}
	return ans;
}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}

void ToUpper(char* str)
{
	while(*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if(islower(*str))
			* str = toupper(*str);
		else if (isupper(*str))
			* str = tolower(*str);
		str++;
	}
}

void Dummy(char* str)
{
	//不改变字符串
}

void show(V_FP_CHARP fp, char*str)
{
	(fp)(str);
	puts(str);
}

char* s_gets(char* str, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}