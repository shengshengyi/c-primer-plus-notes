#include <stdio.h>
#include <math.h>

#define TEST(a1,a2) (a1##a2)
#define PSQR(x) printf("The squar of #x is %d.\n",((x)*(x)))
#define PR(X, ...) printf("Message"#X" :" __VA_ARGS__) 

int main(void)
{
	int num = TEST(13, 14);
	int num1 = PSQR(12);
	double x = 48;
	double y;
	//printf("num = %d", num);
	//printf("num1 = %d", num1);
//	y = sqrt(x);
//	PR(1, "x = %g\n", x);
//	PR(2, "x = %.2f,y = %.4f\n", x, y);
	printf("the date is %s", __DATE__);
	printf("the file is %s", __FILE__);
	printf("the time is %s", __TIME__);
}