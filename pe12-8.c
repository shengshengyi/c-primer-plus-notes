#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int* make_array(int elem, int val);
void show_array(const int ar[], int n);

int main(void)
{
	int* pa;
	int size = 0;
	int value;
	printf("Enter the number of elements:");
	while (scanf("%d", &size) == 1 && size > 0)
	{
		printf("Enter the initialization value: ");
		scanf("%d,", &value);
		pa = make_array(size, value);
		if (pa)
		{
			show_array(pa, size);
			free(pa);
		}
		printf("Enter the number of elements ( <1 to quit ):");

	}
	printf("Done.\n");
	return 0;
}

int* make_array(int elem, int val)
{
	int* p = (int*)malloc(sizeof(int) * elem);
	for (int i = 0;i < elem;i++)
	{
		p[i] = val;
	}
	return p;
}
void show_array(const int ar[], int n)
{
	int col = n / 8 + 1;//ÐÐ
	for (int i = 0;i < col;i++) 
	{
		for (int j = 0; j < 8;j++)
		{
			if ((i * 8 + j) < n)
				printf("ar[%02d] = %d   ", i * 8 + j, ar[i * 8 + j]);
		}	
		printf("\n");
	}
}
/*
void show_array(const int ar[], int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
		if (i % 8 == 7)
			printf("\n");
	}
	printf("\n");
}
*/

