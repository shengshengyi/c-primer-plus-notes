
#ifndef  _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

//在这里插入Item类型的定义，例如
//typedef int Item;//用于use_q.c
typedef struct item { long arrive; int processtime; } Item;

#define MAXQUEUE 10

typedef struct  node
{
	Item item;
	struct  node* next;
}Node;

typedef struct queue
{
	Node* front;/* 指向队列首项的指针 */
	Node* rear;/* 指向队列尾项的指针 */
	int items;/* 队列中的项数 */
			  //不明白这一项是怎么工作的DeQueueEnQueueInitializeQueue函数里赋值的
}Queue;

/*	操作：		初始化队列
	前提条件：	pq指向一个队列
	后置条件：	队列被初始化为空
*/
void InitializeQueue(Queue* pq);

/*	操作：		检查队列是否已满
	前提条件：	pq指向之前被初始化的队列
	后置条件：	已满返回true，否则false
*/
bool QueueIsFull(const	Queue* pq);

/*	操作：		检查队列是否为空
	前提条件：	pq指向之前被初始化的队列
	后置条件：  为空返回true，否则false
*/
bool QueueIsEmpty(const Queue* pq);

/*	操作：		确定队列中的项数
	前提条件：	pq指向之前被初始化的队列
	后置条件：	返回队列中的项数
*/
int QueueItemCount(const Queue* pq);

/*	操作：		在队列末尾添加项
	前提条件：	pq指向之前被初始化的队列
				item是要被添加在队列末尾的项
	后置条件：	队列不为空，item则被添加在队列的末尾，返回true，队列不变返回false
*/
bool EnQueue(Item item, Queue* pq);

/*	操作：		从队列的开头删除项
	前提条件：	pq指向之前被初始化的队列
	后置条件：	队列不为空，队列首端的item将被拷贝到*pitem中并删除，返回true
				如果该操作使得队列为空，则重置队列为空
				如果队列在操作前为空，则返回false
*/
bool DeQueue(Item* pitem, Queue* pq);

/*	操作：		清空队列
	前提条件：	pq指向之前被初始化的队列
	后置条件：	队列被清空
*/
void EmptyTheQueue(Queue* pq);

#endif // ! _QUEUE_H


