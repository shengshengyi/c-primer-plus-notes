
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45

void eat_line(void);
char* s_gets(char* ch, int n);
struct film
{
	char title[TSIZE];
	int rating;
	struct film* next;
};

int main(void)
{
	struct film* head = NULL;
	struct film* current, * prev;
	char input[TSIZE];

	/*�ֻ����洢��Ϣ*/
	puts("Enter first move title:");
	while (s_gets(input, TSIZE) != NULL && input[0] != '\0')
	{
		current = (struct film*)malloc(sizeof(struct film));
		if (head == NULL)
			head = current;
		else
			prev->next = current;
		current->next = NULL;
		
		strcpy(current->title, input);
		puts("Enter your rating 0 - 10:");
		scanf("%d", &current->rating);
		eat_line();
		puts("Enter next movie title(empty line to quit):");
		prev = current;
	}
	/*��ʾ��Ӱ�б�*/
	if (head == NULL)
		puts("NO data .");
	else
		puts("Here is the movies list:\n");
	current = head;//��λ��ͷ
	while (current != NULL)
	{
		printf("MOVIE : %s	RATING:%d\n",
			current->title, current->rating);
		current = current->next;
	}
	/*�ͷ��ڴ�*/
	current = head;//��λ��ͷ
	while (current != NULL)
	{
		current = head;
		head = current->next;//������ô������
		free(current);//current = current->next;
	}
	printf("BYE\n");
	return 0;
}

char* s_gets(char* ch, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(ch, n, stdin);
	if (ret_val)
	{
		find = strchr(ch, '\n');
		if (find)
			*find = '\0';
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