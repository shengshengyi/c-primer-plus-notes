#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define NAME 12
#define MAXSEAT 12

char* s_gets(char* str, int n);
void eat_line(void);
char show_menu(void);
void filetoarr(FILE* pf, struct seats* ps);
void get_arr(struct seats* ps);
void arrtofile(struct seats* ps, FILE* pf);
void reset_file(FILE* pf);

//switch
void switch_list(char ch, FILE* pf, struct seats* ps);
void rb_poen_file(FILE* pf);//此子函数在被其他子函数调用时参数传递有错，暂时不知道怎么解决
void show_emptyseat(FILE* pf, struct seats* ps);
void empty_count(FILE* pf, struct seats* ps);//↑这两个函数基本一样
char atoz_list(struct seats* ps);
void assign(struct seats* ps);
void delete_ass(struct seats* ps);
struct seats {
	int num;
	int flag;
	char first_name[NAME];
	char last_name[NAME];
};
//图省事定义全局变量，不用一直传参数
int size = sizeof(struct seats);
int count = 0;

int main(void)
{
	struct seats airseat[MAXSEAT];
	FILE* pbooks = NULL;
	char choose;
	//reset_file(pbooks);
	
	filetoarr(pbooks, airseat);
	get_arr(airseat);
	arrtofile(airseat, pbooks);
	//printf("[0]%s\n\n", airseat[0].first_name);//为什么filetoarr函数不是将文件读到数组了吗怎么这里打印乱码
	//printf("[1]%s\n\n", airseat[1].first_name);									//和文件关闭没关系
										//读取是短暂的吗
		
										//原来的指针一直没有移动卧槽,前面两个switch函数可以不用那么麻烦了
	
	while ((choose = show_menu()) != 'f')
	{
		switch_list(choose, pbooks, airseat);
	}
	
}

void delete_ass(struct seats *ps)
{
	int num = 0;
	puts("please enter the seat num you want to delete (0 - 11):");
	while (scanf("%d", &num) == 1)
	{
		if ((num < 0) || (num > 11))
		{
			printf("err,enter again");
			puts("please enter the seat num you want to delete (0 - 11):");
			continue;
		}	
		else
			printf("enter succeed! your num is %d\n", num);

		puts("now deleting the data......\n");
		(ps + num)->flag = FALSE;
		puts("delete succeed!\n");
		eat_line();
		break;
		
	}
}

void assign(struct seats* ps)
{
	struct seats customer;
	int count = 0;//空位的数量
	int cnum = 0;
	int empty[MAXSEAT];
	puts("please entre your first name(empty line to quit):");
	while (s_gets(customer.first_name, NAME) && customer.first_name[0] != '\0')
	{
		puts("please entre your last name:");
		s_gets(customer.last_name, NAME);
	
		printf("now finding the empty seats for %s %s\n", customer.first_name, customer.last_name);
		for (int i = 0;i < MAXSEAT;i++,ps++)
		{
			if (ps->flag == FALSE)
			{
				
				printf("NO %d is empty\n", ps->num);
				empty[i] = ps->num;
				count++;
			}
			else
			
				empty[i] = 13;
		}
		if (count == 0)
			puts("Sorry,no seat!");
		puts("choose the seat num");
		scanf("%d", &cnum);
		printf("cnum = %d  empty[cnum] = %d\n",cnum, empty[cnum]);
	//	printf("empty[] = %d %d %d %d %d %d %d %d %d %d %d %d"
	//		,empty[0],empty[1],empty[2], empty[0], empty[0], empty[0], empty[0], empty[0]);

		//指针归为0
		ps -= (MAXSEAT);
	//	printf("%d :%s %s\n",ps->num, ps->first_name, ps->last_name);
		
		if (cnum == empty[cnum])
		{
			//strcpy((ps + cnum)->first_name, customer.first_name);
			//strcpy((ps + cnum)->last_name, customer.last_name);
			//(ps + cnum)->flag = TRUE;
			*(ps + cnum) = customer;
			(ps+cnum)->num = cnum;
			(ps + cnum)->flag = TRUE;
		}
		else
			puts("choose num err,enter all again");
		printf("%d :%s %s\n", (ps + cnum)->num, (ps + cnum)->first_name, (ps + cnum)->last_name);
		
		for (int i = 0;i < MAXSEAT;i++, ps++)
		{
			if (ps->flag == TRUE)
				printf("seat num:%d\n"
					"seat information:\n"
					"seat own name:%s%s\n"
					, ps->num, ps->last_name, ps->first_name);
			else
				printf("seat num:%d\n"
					"seat information:empty\n"
					, ps->num);
		}
		
	}
}

void switch_list(char ch, FILE* pf,struct seats* ps )
{
	switch (ch)
	{
	case'a':
		empty_count(pf, ps);
		break;
	case'b':
		show_emptyseat(pf, ps);
		break;
	case'c':
		atoz_list(ps);
		break;
	case'd':
		assign(ps);
		arrtofile(ps, pf);
		break;
	case'e':
		delete_ass(ps);
		arrtofile(ps, pf);
		break;
	case'f':

		break;
	default:
		break;
	}

}

char atoz_list(struct seats* ps)
{
	char ch;
	//char temp[NAME];
	int len = 0;
	struct seats temp;

	//先获得有效长度
	
	while (ps++->flag)
	{
		len++;
	}
	printf("len = %d\n", len);
	ps -= (len + 1);
	//printf("%c", ps->first_name[0]);
//	printf("%c", (ps + 1)->first_name[0]);

	//printf("%s", ps->first_name);
	
		for (int i = 0;i < len - 1;i++)
			for (int j = 0;j < len - 1 - i;j++)
			{
				if ((ps + j)->flag == TRUE && (ps + j + 1)->flag == TRUE)
				{
			
					if ((ps + j)->first_name[0] > (ps + j+1)->first_name[0])
					{
						//temp[0] = ps->first_name[0];
						//(ps + i)->first_name[0] = (ps + i + 1)->first_name[0];
						//(ps + i + 1)->first_name[0] = temp[0];
						temp = *(ps + j);
						*(ps + j) = *(ps + j + 1);
						*(ps + j + 1) = temp;
						
					}
				}
			}
		//printf("[0] %c", (ps)->first_name[0]);
		//printf("[1] %c\n", (ps + 1)->first_name[0]);
		//printf("***************\n");
		for (int i = 0;i < MAXSEAT;i++, ps++)
		{
			if (ps->flag == FALSE)
				printf("seat num:%d is empty\n", ps->num);
			else
				printf("seat num:%d\n"
					"seat information:\n"
					"seat own name:%s%s\n"
					, ps->num, ps->last_name, ps->first_name);
		}
	
	
}

void rb_poen_file(FILE* pf)
{
	if ((pf = fopen("airseats.dat", "rb")) == NULL)
	{
		fputs("can not open book.dat file\n", stderr);
		exit(1);
	}
	printf("open succeed");
	rewind(pf);
	fclose(pf);
	printf("close succeed");
}

void show_emptyseat(FILE* pf,struct seats*ps)
{
	
/*	if ((pf = fopen("airseats.dat", "rb")) == NULL)
	{
		fputs("can not open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pf);
	
	//rb_poen_file(pf);为什么调用一样的子函数会出错
	while (circle < MAXSEAT && fread(ps, size, 1, pf) == 1)
	{
		if (ps->flag == FALSE)
			printf("seat num:%d is empty\n", ps->num);
		circle++;
	}
	fclose(pf);*/
	for (int i = 0;i < MAXSEAT;i++, ps++)
	{
		if (ps->flag == FALSE)
			printf("seat num:%d is empty\n", ps->num);
	}
}

void empty_count(FILE* pf, struct seats* ps)
{
	int num = 0;
	//int circle = 0;
	/*if ((pf = fopen("airseats.dat", "rb")) == NULL)
	{
		fputs("can not open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pf);
	
	//rb_poen_file(pf);
	while (circle < MAXSEAT && fread(ps, size, 1, pf) == 1)
	{
		if (ps->flag == FALSE)
			num++;
		circle++;
	}
	fclose(pf);
	*/
	for (int i = 0;i < MAXSEAT;i++, ps++)
	{
		if (ps->flag == FALSE)
			num++;
	}
	printf("the count of empty :%d\n", num);
	

}

//准备工作，创建文件，文件读到数组，关闭文件,打印文件内容
void filetoarr(FILE* pf,struct seats *ps)
{
	if ((pf = fopen("airseats.dat", "a+b")) == NULL)
	{
		fputs("can not open book.dat file\n", stderr);
		exit(1);
	}

	rewind(pf);

	while (count < MAXSEAT && fread(ps, size, 1, pf) == 1)
	{
		if (count == 0)
			puts("current contents of book.dat:");

		if (ps->flag == TRUE)
		printf("seat num:%d\n"
				"seat information:\n"
				"seat own name:%s%s\n"
				, ps->num, ps->last_name, ps->first_name);
		else
			printf("seat num:%d\n"
				"seat information:empty\n"
				, ps->num);
		count++;
		ps++;
	}

	if (count == MAXSEAT)
	{
		fputs("the airseats.dat file is full\n", stderr);
		//exit(2);
	}
	fclose(pf);
}

//准备工作，输入数据到数组
void get_arr(struct seats* ps)
{
	
	puts("now enter the owner first name:");
	puts("press [enter] at the start of a line to stop:");
	while (count < MAXSEAT && s_gets(ps->first_name, NAME) != NULL && ps->first_name[0] != '\0')
	{
		puts("now enter the owner last name:");
		s_gets(ps->last_name, NAME);
		
		ps->num = count;
		//puts("please add new seat num :");
		//scanf("%d", &ps->num);//这里要加&不是很理解

		//printf("%d", ps->num);
		
		ps->flag = TRUE;
		ps++;
		eat_line();
		count++;
		if (count < MAXSEAT)
			puts("enter the next title:");
	}
	puts("Autofilling...");


	while (MAXSEAT - count)
	{
		ps->first_name[NAME] = NULL;
		ps->last_name[NAME] = NULL;
		ps->num = count;
		ps->flag = FALSE;
		count++;
		ps++;
		eat_line();
	}

	puts("Fill succeed...");
}

//把数组12成员全写入文件
void arrtofile(struct seats* ps, FILE* pf)
{
	pf = fopen("airseats.dat", "w+b");
	
	fwrite(ps, size, count, pf);
	
	
	fclose(pf);
	return;
}

//重置文件
void reset_file(FILE* pf)
{
	pf = fopen("airseats.dat", "w+b");
	fclose(pf);
}

char show_menu(void)
{
	char ans;
	puts("to choose a function,enter its letter label:");
	printf("a)show number of empty seats\n");
	printf("b)show list of empty seats\n");
	printf("c)show alphabetical list of seats\n");
	printf("d)assign a cunstomer to a srat assignment\n");
	printf("e)delete a seat assignment\n");
	printf("f)quit\n");
	ans = getchar();
	ans = tolower(ans);
	eat_line();
	while (strchr("abcdef", ans) == NULL)
	{
		puts("please enter a b c d e or f:");
		ans = tolower(getchar());
		eat_line();
	}
	return ans;

}

void eat_line(void)
{
	while (getchar() != '\n')
		continue;
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