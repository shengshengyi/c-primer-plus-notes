#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* 局部数据类型 */
typedef struct pair {
	Trnode* parent;
	Trnode* child;
}Pair;

/* 局部函数原型 */
static Trnode* MakeNode(const Item* pi);
static bool ToLeft(const Item* i1, const Item* i2);
static bool ToRight(const Item* i1, const Item* i2);
static void AddNode(Trnode* new_node, Trnode* root);
static void InOrder(const Trnode* root, void (*pfun)(Item item));
static Pair SeekItem(const Item* pi, const Tree* ptree);
static void DeleteNode(Trnode** ptr);
static void DeleteAllNodes(Trnode* ptr);

/* 函数定义 */
void InitializeTree(Tree* ptree)
{
	ptree->root = NULL;
	ptree->size = 0;
}

bool TreeIsEmpty(const Tree* ptree)
{
	if (ptree->root == NULL)
		return true;
	else
		return false;
}
bool TreeIsFull(const Tree* ptree)
{
	if (ptree->size == MAXITEMS)
		return true;
	else
		return false;
}
int TreeItemCount(const Tree* ptree)
{
	return ptree->size;
}
bool AddItem(const Item* pi, Tree* ptree)
{
	Trnode* new_node;
	if (TreeIsFull(ptree))
	{
		fprintf(stderr, "Tree is full\n");
		return false;
	}
	if (SeekItem(pi, ptree).child != NULL)
	{
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;
	}
	new_node = MakeNode(pi);
	if (new_node == NULL)
	{
		fprintf(stderr, "Could not create node\n");
		return false;
	}
	/* 成功创建新节点 */
	ptree->size++;

	if (ptree->root == NULL)	/* 情况1：树为空 */
		ptree->root = new_node; /* 新节点为树的根节点 */
	else						/* 情况2：树不为空 */
		AddNode(new_node, ptree->root);
	
	return true;
}

bool InTree(const Item* pi, const Tree* ptree)
{
	return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item* pi, Tree* ptree)
{
	Pair look;
	look = SeekItem(pi, ptree);
	if (look.child == NULL)
		return false;
	if (look.parent == NULL)//根节点，删除
		DeleteNode(&ptree->root);
	else if (look.parent->left == look.child)//还能这样
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	ptree->size--;
	
	return true;
}

void Traverse(const Tree* ptree, void (*pfun)(Item item))
{
	if (ptree != NULL)
		InOrder(ptree->root, pfun);
}

void DeleteAll(Tree* ptree)
{
	if (ptree != NULL)
		DeleteAllNodes(ptree->root);
	ptree->root = NULL;
	ptree->size = 0;
}
/* 局部函数 */
static Trnode* MakeNode(const Item* pi)
{
	Trnode* new_node;
	new_node = (Trnode*)malloc(sizeof(Trnode));
	if (new_node != NULL)
	{
		new_node->item = *pi;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}
static bool ToLeft(const Item* i1, const Item* i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) < 0)
		return true;
	else if (comp1 == 0 &&
		strcmp(i1->petkind, i2->petkind) < 0)
		return true;
	else
		return false;
}

static bool ToRight(const Item* i1, const Item* i2)
{
	int comp1;
	if ((comp1 = strcmp(i1->petname, i2->petname)) > 0)
		return true;
	else if (comp1 == 0 &&
		strcmp(i1->petkind, i2->petkind) > 0)
		return true;
	else
		return false;
}
static void AddNode(Trnode* new_node, Trnode* root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode(new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if(root->right == NULL)
			root->right = new_node;
		else
			AddNode(new_node,root->right);
	}
	else 
	{
		fprintf(stderr, "loacation error in AddNode()\n");
		exit(1);
	}

}

static Pair SeekItem(const Item* pi, const Tree* ptree)
{
	Pair look;
	look.parent = NULL;
	look.child = ptree->root;
	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(pi, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}



static void DeleteNode(Trnode** ptr)
{
	Trnode* temp;
	if ((*ptr)->left == NULL)//左边没节点的情况，两边都没节点相同
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)//右边没节点的情况
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else/* 两边都有节点 */
	{
		/* 找到左节点右半边有空位的地方将右节点连接进去 */
		for (temp = (*ptr)->left;temp->right != NULL;
			temp = temp->right)
			continue;
		temp->right = (*ptr)->right;//右节点放到找到的空位上
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static void InOrder(const Trnode* root, void (*pfun)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(*pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes(Trnode* root)
{
	Trnode* pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}