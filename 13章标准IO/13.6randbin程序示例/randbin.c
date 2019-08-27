#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARSIZE 1000

int main(void)
{
	double numbers[ARSIZE];
	double value;
	const char* file = "numbers.dat";
	int i;
	long pos;
	FILE* iofile;

	//创建一组double类型值
	for (int i = 0;i < ARSIZE;i++)
		numbers[i] = 100 * i + 1.0 / (i + 1);

	//打开文件，无则创建
	if ((iofile = fopen(file, "wb")) == NULL)
	{
		fprintf(stderr, "Could not open %s for output.\n", file);
		exit(EXIT_FAILURE);
	}
	//二进制格式写入文件
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);

	if ((iofile = fopen(file, "rb")) == NULL)
	{
		fprintf(stderr, "Could not open %s for random access.\n", file);
		exit(EXIT_FAILURE);
	}
	printf("Enter an index in the range 0 - %d.\n", ARSIZE - 1);
	while (scanf("%d", &i) == 1 && i >= 0 &&i < ARSIZE)
	{
		pos = (long)i * sizeof(double);//偏移量
		fseek(iofile, pos, SEEK_SET);//定位到此处
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f.\n", value);
		printf("Next index(out of range to quit):\n");
	}
	fclose(iofile);
	puts("Bye");
	return 0;
	
}
