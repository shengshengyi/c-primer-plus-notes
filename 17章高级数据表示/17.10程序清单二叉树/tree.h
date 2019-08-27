#ifndef  _TRRR_H_
#define  _TRRR_H_
#include <stdbool.h>

/* ���ݾ���������¶���Item */
#define SLEN 20
typedef struct item
{
	char petname[SLEN];
	char petkind[SLEN];
}Item;

#define MAXITEMS 10
typedef struct  trnode
{
	Item item;
	struct trnode* left;
	struct trnode* right;
}Trnode;

typedef struct tree 
{
	Trnode* root;/* ָ����ڵ��ָ�� */
	int size;	/* �������� */
}Tree;

/* ����ԭ�� */

/*	������������ʼ��Ϊ��
ǰ��������ptreeָ��һ����
����������������ʼ��Ϊ��
*/
void InitializeTree(Tree* ptree);

/*	������ȷ�����Ƿ�Ϊ��
ǰ��������ptreeָ��һ����
�����������շ���true������false
*/
bool TreeIsEmpty(const Tree* ptree);

/*	������ȷ�����Ƿ�����
ǰ��������ptreeָ��һ����
�����������Ƿ���true������false
*/
bool TreeIsFull(const Tree* ptree);

/*	������ȷ��������
ǰ��������ptreeָ��һ����
����������������������
*/
int TreeItemCount(const Tree* ptree);

/*	���������������һ����
ǰ��������pi�Ǵ���ӵ���ĵ�ַ
			ptreeָ��һ����
���������������������ӣ�������true������false
*/
bool AddItem(const Item* pi, Tree* ptree);


/*	�����������в���һ����
ǰ��������piָ��һ����
			ptreeָ��һ���ѳ�ʼ������
����������������������һ�������true������false
*/
bool InTree(const Item* pi, const Tree* ptree);

/*	������������ɾ��һ����
ǰ��������pi��ɾ����ĵ�ַ
			ptreeָ��һ���ѳ�ʼ������
��������������ɹ�ɾ��һ�������true�����򷵻�false
*/
bool DeleteItem(const Item* pi, Tree* ptree);

/*	�������Ѻ���Ӧ�������е�ÿһ��
ǰ��������ptreeָ��һ����
			pfunָ��һ������
			�ú�������һ��Item���͵Ĳ��������޷���ֵ
����������pfunָ��ĺ���Ϊ���е�ÿһ��ִ��һ��
*/
void Traverse (const Tree* ptree, void(*pfun)(Item item));

/*	������ɾ���������е�����
ǰ��������ptreeָ���ѳ�ʼ������
������������Ϊ��
*/
void DeleteALL(Tree* ptree);
	
#endif // ! _TRRR_H_

