#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void showmovies(Item item);
char* s_gets(char* st, int n);
void eat_line(void);
int main(void)
{
	List movies;
	Item temp;

	/* 初始化 */
	InitializeList(&movies);
	if (ListIsFull(&movies))
	{
		fprintf(stderr, "NO MENORY AVAILABLE ,BYE\n");
		exit(1);
	}

	/* 获取用户输入并储存 */
	puts("Enter first movie title:");
	while (s_gets(temp.title, TSIZE) != NULL && temp.title[0] != '\0')
	{
		puts("Enter the rating 0 - 10:");
		scanf("%d", &temp.rating);
		eat_line();

		if (AddItem(temp, &movies) == false)
		{
			fprintf(stderr, "problem allocating memory\n");
			break;
		}
		
		if (ListIsFull(&movies))
		{
			puts("List is now full.");
			break;
		}
		puts("Enter next movie title(empty line to stop):");
	}

	/* 显示 */
	if (ListIsEmpty(&movies))
		printf("No data entered.");
	else
	{
		printf("Here is the movies list:\n");
		Traverse(&movies, showmovies);
	}
	printf("you entered %d movies \n", ListItemCount(&movies));

	/* 清理 */
	EmptyTheList(&movies);
	printf("BYE \n");

	return 0;
}
void showmovies(Item item)
{
	printf("Moives:%s  Rating: %d \n", item.title, item.rating);
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
			eat_line();
	}
	return ret_val;
}
void eat_line(void)
{
	while (getchar() != '\n')
		continue;
}