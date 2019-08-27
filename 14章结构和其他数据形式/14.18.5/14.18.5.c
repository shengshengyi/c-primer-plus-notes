#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 20
#define CSIZE 4
char* s_gets(char* str, int n);
float get_avg(struct student* p);
void put_all_info(struct student* p);
void class_avg(struct student* p);
struct  name
{
	char first_name[LEN];
	char last_name[LEN];
};


struct student {
	struct name st_name;
	float grade[3];
	float avg;
};

static int count = 0;

int main(void)
{
	struct  student st[CSIZE];

	//struct  student* p = &st[count];

	printf("Enter the NO.%d student name: ", count + 1);
	while (count < 3 && s_gets(st[count].st_name.first_name, LEN) && s_gets(st[count].st_name.last_name, LEN))
	{
		//printf("%s", st[count].st_name.first_name);
		//printf("%s", st[count].st_name.last_name);

		printf("Enter the his first class grade :");
		scanf("%f", &st[count].grade[0]);
		//printf("%.2f", st[count].grade[0]);

		printf("Enter the his second class grade :");
		scanf("%f", &st[count].grade[1]);

		printf("Enter the his third class grade :");
		scanf("%f", &st[count].grade[2]);

		st[count].avg = get_avg(&st[count]);
		//printf("return avg = %.2f", get_avg(&st[count]));
		printf("avg = %.2f\n", st[count].avg);

		count++;
		if (count == 3)//消除输入最后一位学生成绩后继续提示输入下一位
			break;
		printf("Enter the NO.%d student name:", count + 1);
	}

	put_all_info(st);
	class_avg(st);
}

//一定要注意变量类型匹配，编译器不会自动强制转换
float get_avg(struct student* p)
{
	float sum = 0;
	for (int i = 0;i < 3;i++)
	{
		sum += p->grade[i];
	}
	p->avg = (float)(sum / 3);
	//printf("sum = %.2f avg = %.2f", sum, p->avg);

	return p->avg;
}

void put_all_info(struct student* p)
{
	for (int i = 0;p != NULL ,i < 3;i++)
	{
		printf("%s%s :\n"
			"no.1class : %.2f\n"
			"no.2class : %.2f\n"
			"no.3class : %.2f\n"
			"avg  : %.2f\n"
		, p->st_name.last_name,p->st_name.first_name,p->grade[0], p->grade[1], p->grade[2],p->avg );
		p++;
	}
}

void class_avg(struct student* p)
{
	float sum = 0;
	
	for (int i = 0;i < 3;i++)
	{
		sum += p[i].avg;
		
	}
	/*这样用while循环一直出错，暂时不知道原因
	while (p)
	{
		sum += (*p).avg;//p->avg;
		p++;
	}
	*/
	printf("the average of whole class is %.2f", sum / 3);
	
}

char* s_gets(char* str, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(str, n, stdin);
	if (ret_val)
	{
		find = strchr(str, '\n');
		if (find)
			* find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}