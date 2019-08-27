#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS	10
char* s_gets(char* str, int n);
void eat_line(void);
void show_books(struct book* p, int count);
char show_menu(void);
void dela_book(struct book* p, int count, FILE* pb);

void mod_book(struct book* p, int count, FILE* pb);
struct book {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	//int flag;
};

int main(void)
{
	struct book library[MAXBKS];
//	struct book temp = {"no0book","no0author",0};
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(struct book);
	char menu;

	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("can not open book.dat file\n", stderr);
		exit(1);
	}
	
	//先把文件内容读到数组中
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("current contents of book.dat:");
		printf("%s by %s :$%.2f\n", library[count].title, library[count].author, library[count].value);
		count++;
	}
	filecount = count;
	if (count == MAXBKS)
	{
		fputs("the book.dat file is full", stderr);
		exit(2);
	}
	
	//添加内容到数组中
	puts("please add new book titles:");
	puts("press [enter] at the start of a line to stop:");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("now enter the author:");
		s_gets(library[count].author, MAXAUTL);
		puts("now enter the value:");
		scanf("%f", &library[count++].value);
		eat_line();
		if (count < MAXBKS)
			puts("enter the next title:");
	}
	
	//打印数组并把新添加的内容写入文件
	if (count > 0)
	{
		show_books(&library[0],count);
		fwrite(&library[filecount], size, count - filecount, pbooks);
	}
	else
		puts("no books?too bad\n");
	puts("bye");

	menu = show_menu();

	switch (menu)
	{
	case 'd':
		dela_book(library,count,pbooks);//&library[0]

		break;
	case 'm':
		mod_book(library, count, pbooks);
		//printf("%s by %s :$%.2f\n", library[1].title, library[1].author, library[1].value);
		break;

	default:
		break;
	}

	fclose(pbooks);
	return 0;
}

//这个结构体数组完全不知道怎么操作好
void mod_book(struct book *p, int count, FILE* pb)
{
	struct book b;
	int n ;

	

	puts("enter the nums you want to modify:");
	scanf("%d", &n);
	eat_line();
	
	p += (n - 1);


	puts("please add new book titles:");
	puts("press [enter] at the start of a line to stop:");
	s_gets(b.title, MAXTITL);
	strcpy(p->title, b.title);
	
	puts("now enter the author:");
	s_gets(b.author, MAXAUTL);
	strcpy(p->author, b.author);

	puts("now enter the value:");
	scanf("%f", &b.value);
	p->value = b.value;

	eat_line();
		
	//printf("%s by %s :$%.2f\n", b.title, b.author, b.value);

	//修改完成写入文件
	fclose(pb);
	pb = fopen("book.dat", "w+b");//没有找到好的直接更改的方法只能全部删除重新写入

	fwrite(p, sizeof(struct book), count, pb);
}


void dela_book(struct book *p,int count,FILE *pb)
{
	int n;
	printf("please enter the number you want delate:");
	scanf("%d", &n);
	
	
	
								 
	//如果是删除最后一个，直接将前面的重写入
	if (n == count)
	{
		fclose(pb);
		pb = fopen("book.dat", "w+b");//没有找到好的直接更改的方法只能全部删除重新写入
		count--;
		fwrite(p, sizeof(struct book), count, pb);
			//fwrite(&library[filecount], size, count - filecount, pbooks);
	}

	//如果不是最后一项，将后面的内容前移
	else
	{
	/*	往前移一直不成功就只能这样
		for (int i = n;n < count;i++)
		{
			p[i] = p[i + 1];
			(*p)[i] = 
		}
		
		p += (n - 1);
		for (int i = n;n < count;i++)
		{
			p = ++p;
		}*/
		fclose(pb);
		pb = fopen("book.dat", "w+b");//没有找到好的直接更改的方法只能全部删除重新写入
		//count--;
		fwrite(p, sizeof(struct book), n-1, pb);

		fclose(pb);
		pb = fopen("book.dat", "a+b");
		fwrite(p+n, sizeof(struct book), count - n, pb);
	}
	
}
	
	


char show_menu(void)
{
	char ans;
	puts("enter menu choioce:");
	printf("d)delet		m)modify\n");
	ans = getchar();
	ans = tolower(ans);
	eat_line();
	while (strchr("dm", ans) == NULL)
	{
		puts("please enter d or m:");
		ans = tolower(getchar());
		eat_line();
	}
	return ans;

}

void show_books(struct book *p,int count)
{


	puts("here is the list of your books:");
	for (int index = 0;index < count;index++, p++)
	{
		if (p->title == NULL)
			continue;
		printf("%s by %s :$%.2f\n", p->title, p->author, p->value);
	}
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