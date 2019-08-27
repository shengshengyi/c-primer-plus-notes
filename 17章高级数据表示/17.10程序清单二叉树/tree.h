#ifndef  _TRRR_H_
#define  _TRRR_H_
#include <stdbool.h>

/* 根据具体情况重新定义Item */
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
	Trnode* root;/* 指向根节点的指针 */
	int size;	/* 数的项数 */
}Tree;

/* 函数原型 */

/*	操作：把树初始化为空
前提条件：ptree指向一个树
后置条件：树被初始化为空
*/
void InitializeTree(Tree* ptree);

/*	操作：确定树是否为空
前提条件：ptree指向一个树
后置条件：空返回true，否则false
*/
bool TreeIsEmpty(const Tree* ptree);

/*	操作：确定树是否已满
前提条件：ptree指向一个树
后置条件：是返回true，否则false
*/
bool TreeIsFull(const Tree* ptree);

/*	操作：确定树的项
前提条件：ptree指向一个树
后置条件：返回树的项数
*/
int TreeItemCount(const Tree* ptree);

/*	操作：在树中添加一个项
前提条件：pi是待添加的项的地址
			ptree指向一个树
后置条件：可以添加则添加，并返回true，否则false
*/
bool AddItem(const Item* pi, Tree* ptree);


/*	操作：在树中查找一个项
前提条件：pi指向一个项
			ptree指向一个已初始化的数
后置条件：如果在树中添加一个项，返回true，否则false
*/
bool InTree(const Item* pi, const Tree* ptree);

/*	操作：从树中删除一个项
前提条件：pi是删除项的地址
			ptree指向一个已初始化的数
后置条件：如果成功删除一个项，返回true，否则返回false
*/
bool DeleteItem(const Item* pi, Tree* ptree);

/*	操作：把函数应用于树中的每一项
前提条件：ptree指向一个树
			pfun指向一个函数
			该函数接收一个Item类型的参数，并无返回值
后置条件：pfun指向的函数为树中的每一项执行一次
*/
void Traverse (const Tree* ptree, void(*pfun)(Item item));

/*	操作：删除树中所有的内容
前提条件：ptree指向已初始化的数
后置条件：树为空
*/
void DeleteALL(Tree* ptree);
	
#endif // ! _TRRR_H_

