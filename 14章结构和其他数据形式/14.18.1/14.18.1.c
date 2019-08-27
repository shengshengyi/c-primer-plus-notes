#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LEN 10
char* s_gets(char* str, int n);

enum mname {january,febrary,march,april,may,june,july,august,september,october,november,december};
const char* months[] = { "january","febrary","march", "april", "may", "june", "july" ,"august","september","october","november","december" };
const int day_mon[12] = {31,28,31,30,31,30,31, 31, 30, 31, 30, 31 };

int main(void)
{
	char choice[LEN];
	enum mname month;
	bool month_is_found = false;
	int tol = 0;

	puts("Enter the month (empty line to quit):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0')
	{
		
		for (month = january; month <= december; month++)
		{
			tol += day_mon[month];

			if (strcmp(choice,months[month] ) == 0)//卧槽多了一个；在这疯狂跳出，找半天
			{
				month_is_found = true;
				break;
			}

		}
		if (month_is_found)
		{
			printf("your enter is %s before %s has %d days",choice, months[month], tol);
		}
	}
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