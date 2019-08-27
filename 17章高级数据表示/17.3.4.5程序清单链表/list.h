#ifndef LIST_H
#define LIST_H
#include <stdbool.h>

#define TSIZE 45	

struct film
{
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node* List;

/*	������		��ʼ��һ������
	ǰ��������	plistָ��һ������
	����������	�����ʼ��Ϊ��
*/
void InitializeList(List* plist);

/*	������		ȷ�������Ƿ�Ϊ�ն��壬plistָ��һ���ѳ�ʼ��������
	ǰ��������	
	����������	�������Ϊ�գ��ú�������true�����򷵻�false
*/
bool ListIsEmpty(const List* plist);

/*	������		ȷ�������Ƿ�������plistָ��һ���ѳ�ʼ��������
	ǰ��������
	����������	��������������ú��������棻���򷵻ؼ�
*/
bool ListIsFull(const List* plist);

/*	������		ȷ�������е�������plistָ��һ���ѳ�ʼ��������
	ǰ��������
	����������	�ú������������е�����
*/
unsigned int ListItemCount(const List* plist);

/*	������		�������ĩβ�����
	ǰ��������	item��һ���������������plistָ��һ���ѳ�ʼ��������
	����������	������ԣ��ú���������ĩβ���һ����ҷ���true�����򷵻�false
*/
bool IddItem(Item item, List* plist);

/*	������		�Ѻ��������������е�ÿһ��
				plistָ��һ���ѳ�ʼ��������
				pfunָ��һ���������ú�������һ��Item���͵Ĳ��������޷���ֵ
	ǰ��������	
	����������	pfunָ��ĺ��������������е�ÿһ��һ��
*/
void Traverse(const List* plist, void (*pfun)(Item Item));

/*	������		�ͷ��ѷ�����ڴ�
				plistָ��һ���ѳ�ʼ��������
	ǰ��������	
	����������	�ͷ���Ϊ�������������ڴ棬��������Ϊ��
*/
void EmptyTheList(List* plist);
#endif