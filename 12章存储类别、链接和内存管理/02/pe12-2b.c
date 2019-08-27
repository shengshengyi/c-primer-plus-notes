#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "pe12-2a.h"

int main(void)
{
	int mode;

	printf("Enter 0 for metric mode,1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		get_mode(mode);
		get_info();
		show_info();
		printf("Enter 0 for metric mode,1 for US mode: ");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}