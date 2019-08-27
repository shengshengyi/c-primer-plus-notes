#include <stdio.h>

char get_choice(void);
char get_first(void);
float add(void);
float divide(void);


int main(void)
{
	int choice;

	while((choice = get_choice()) != 'q')
	{

		switch (choice)
		{
			case 'a':
					add();
					break;
			case 's':
					//subtract();
					break;

			case 'm':
					//multiply();
					break;
			case 'd':
					divide();
					break;
			default:
					printf("error!\n");
					break;
		}
	}
	printf("Bye.\n");
	return 0;
}

char get_choice(void)
{
	int ch;

    printf("Enter the operation of your choice:\n");
	printf("a.add		s.subtract\n");
	printf("m.multiply	d.divide\n");

	ch = get_first();

	while((ch != 'a') && (ch != 's') && (ch != 'm') && (ch != 'd') && (ch != 'q'))
	{
		printf("Please enter with a, s, m, d or q.\n");
		ch = get_first();
	}

	return ch;
}


char get_first(void)
{
	int ch;

	ch = getchar();

	while (getchar() != '\n')
		continue;

	return ch;
}


float add(void)
{
	float num1,num2;
	char ch;


        printf("Enter first number:");
        while(scanf("%f",&num1) != 1)
        {
            while((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not an number.\nPlease enter an ");
            printf("integer value,such as 25, -178, or 3:");
        }

        printf("Enter second number:");
        while(scanf("%f",&num2) != 1)
        {
            while((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not an number.\nPlease enter an ");
            printf("integer value,such as 25, -178, or 3:");
        }


        printf("%.1f + %.1f = %.1f\n",num1,num2,num1+num2);

         while(getchar() != '\n')//消除最后的\n，防止进入下个循环
            continue;

	return (num1+num2);
}

float divide(void)
{
	float num1,num2;
	char ch;


        printf("Enter first number:");
        while(scanf("%f",&num1) != 1)
        {
            while((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not an number.\nPlease enter an ");
            printf("integer value,such as 25, -178, or 3:");
        }


        printf("Enter second number:");

        while(scanf("%f",&num2) != 1)
        {

            while((ch = getchar()) != '\n')
                putchar(ch);
            printf(" is not an number.\nPlease enter an ");
            printf("integer value,such as 25, -178, or 3:");


                printf("Enter a number other than 0:");
        }

        if(num2 == 0)
        {
            printf("Enter a number other than 0:");
            scanf("%f",&num2);
        }



        printf("%.1f / %.1f = %.1f\n",num1,num2,num1/num2);

        while(getchar() != '\n')//消除最后的\n，防止进入下个循环
            continue;

		return (num1/num2);

}


