#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 4096
#define NAMELEN 40
#define SRC_FILE "src.txt"
#define DES_FILE "des.txt"

char* s_gets(char* st, int n);
int** rand_arr(int n, int m);//n行m列
/*
		生成数组 送入src文件		没按照题目来而是自己生成数组，所以感觉这步有点多余
		数组转换为字符 送入des文件，

	*/


int main(void)
{
	FILE* src, * des;
	int row = 0, col = 0;


	
	printf("please enter the row  and col:");
	scanf("%d", &row);

	printf("please enter the row  and col:");
	scanf("%d", &col);
	/*
	printf("please enter the row  and col:");
	scanf("%d", &row);
	*/
	/*
	int** temp = (int**)malloc(sizeof(int*) * (row));
	for (int i = 0;i < col;i++)
		temp[i] = (int*)malloc(sizeof(int) * (col));
*/

	int** temp = rand_arr(20, 20);

	if ((src = fopen(SRC_FILE, "w+")) == NULL)
	{
		fprintf_s(stderr, "Can't open file %s.\n", SRC_FILE);
		exit(EXIT_FAILURE);
	}

	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			fprintf(src,"%d",temp[i][j]);
		}
		fprintf(src, "\n");
	}
	
	//for (int i = 0;i < 10;i++)
		//free(*temp);
		//free(temp);//这里的顺序不能反
		

		fclose(src);
	
		
		
		if ((des = fopen(DES_FILE, "w+")) == NULL)
		{
			fprintf_s(stderr, "Can't open file %s.\n", DES_FILE);
			exit(EXIT_FAILURE);
		}

	
		for (int i = 0;i < row;i++)
		{
			for (int j = 0;j < col;j++)
			{
				
				
				switch (temp[i][j])
				{
				case 0:
					putchar(' ');
					fputc(' ', des);
					break;
				case 1:
					putchar('.');
					fputc('.', des);
					break;
				case 2:
					putchar('\'');
					fputc('\'', des);
					break;
				case 3:
					putchar(':');
					fputc(':', des);
					break;
				case 4:
					putchar('~');
					fputc('~', des);
					break;
				case 5:
					putchar('*');
					fputc('*', des);
					break;
				case 6:
					putchar('=');
					fputc('=', des);
					break;
				case 7:
					putchar('$');
					fputc('$', des);
					break;
				case 8:
					putchar('%');
					fputc('%', des);
					break;
				case 9:
					putchar('#');
					fputc('#', des);
					break;
				default:
					break;
				}
			
			}
			fputc('\n', des);
			fputc('\0', des);
			printf("\n");
		}
		
		 free(*temp);
		free(temp);//这里的顺序不能反
		return;
}



//这函数有问题，用变量传入参数会出错
int** rand_arr(int n, int m)//n行m列
{	
	//用二维指针申请二维数组
	int i = 0;
	int j = 0;

	int** arr = (int**)malloc(sizeof(int*) * (n) );
	for (i = 0;i < m;i++)
		 arr[i] = (int*)malloc(sizeof(int) * (m));

	srand(time(0));
	for (i = 0;i < n;i++)
		for (int j = 0; j < m;j++)
			arr[i][j] = rand() % 10;
	return arr;
	//free(a)  free(a[i])
}
