#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int COUNT_1 = 0;
int COUNT_2 = 0;
int COUNT_3 = 0;
int COUNT_4 = 0;
int COUNT_5 = 0;
int COUNT_6 = 0;
int COUNT_7 = 0;
int COUNT_8 = 0;
int COUNT_9 = 0;
int COUNT_10 = 0;


int main(void)
{
	int roll;
	long int num = 100000;
	while (num)
	{
		roll = roll_size(10);
		count_dice(roll);
		
		num--;
	}
	printf("COUNT_1 = %d \n"
		"COUNT_2 = %d \n"
		"COUNT_3 = %d \n"
		"COUNT_4 = %d \n"
		"COUNT_5 = %d \n"
		"COUNT_6 = %d \n"
		"COUNT_7 = %d \n"
		"COUNT_8 = %d \n"
		"COUNT_9 = %d \n"
		"COUNT_10 = %d \n", COUNT_1, COUNT_2, COUNT_3, COUNT_4, COUNT_5, COUNT_6, COUNT_7, COUNT_8, COUNT_9, COUNT_10);
}

int roll_size(int size)//size = 10
{
	int roll;

	roll = rand() % size + 1;

	return roll;
}

int count_dice(int roll)//对骰子点数统计1000次
{
	if (roll == 1)
		COUNT_1++;
	else if (roll == 2)
		COUNT_2++;
	else if (roll == 3)
		COUNT_3++;
	else if (roll == 4)
		COUNT_4++;
	else if (roll == 5)
		COUNT_5++;
	else if (roll == 6)
		COUNT_6++;
	else if (roll == 7)
		COUNT_7++;
	else if (roll == 8)
		COUNT_8++;
	else if (roll == 9)
		COUNT_9++;
	else
		COUNT_10++;
	return 0;
}

