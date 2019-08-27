#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

static int  mode;//Ä£Ê½: 1 US  0 METRIC
static float distance;//¾àÀë£º kilometers metric   miles  us
static float fuel;//È¼ÁÏ

void get_mode(int mod)
{
	mode = mod;
}

void get_info(void) 
{
	//mode 0   return =  fuel/(distance / 100)
	if (mode == 0)
	{
		printf("Enter distance traceled in kilometers: ");
		scanf("%f", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%f", &fuel);
		
	}
	else if (mode == 1) // mode 1	return = (distance / fuel)
	{
		printf("Enter distance traceled in miles: ");
		scanf("%f", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%f", &fuel);
		//printf("Fuel consumption is %0.1f miles per gallon", distance / fuel);
	}

	else if (mode >= 2)//mode 1
	{
		printf("Invalid mode specified. Mode 1(US) used\n");
		printf("Enter distance traceled in miles: ");
		scanf("%f", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%f", &fuel);
		//printf("Fuel consumption is %0.1f miles per gallon", distance / fuel);
	}
	else
		return;
}


void show_info(void)
{
	if(mode == 0)
		printf("Fuel consumption is %0.2f liters per 100 km \n", fuel / (distance / 100));
	else 
		printf("Fuel consumption is %0.1f miles per gallon\n", distance / fuel);
}