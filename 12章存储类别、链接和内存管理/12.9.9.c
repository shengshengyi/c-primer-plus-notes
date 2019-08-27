#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE	100

int main(void)
{
	char** p1;
	char* p2 = (char *)malloc(SIZE * sizeof(char));
	int words;
	int len;

	printf("How many words do you wish to enter ?");
	scanf("%d", &words);
	p1 = (char**)malloc(words * sizeof(char*));
	printf("Enter %d words now:\n",words);

	for (int i = 0;i < words;i++)
	{
		scanf("%s", p2);
		len = strlen(p2);
		p1[i] = (char*)malloc(len * sizeof(char));
		strcpy(p1[i], p2);
	}
	free(p2);
	
	printf("Here are your words:\n");
	for (int i = 0;i < words;i++)
	{
		puts(p1[i]);
	}
	free(p1);

	return;
}