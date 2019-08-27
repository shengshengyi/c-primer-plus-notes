
#ifndef  _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

//���������Item���͵Ķ��壬����
//typedef int Item;//����use_q.c
typedef struct item { long arrive; int processtime; } Item;

#define MAXQUEUE 10

typedef struct  node
{
	Item item;
	struct  node* next;
}Node;

typedef struct queue
{
	Node* front;/* ָ����������ָ�� */
	Node* rear;/* ָ�����β���ָ�� */
	int items;/* �����е����� */
			  //��������һ������ô������DeQueueEnQueueInitializeQueue�����︳ֵ��
}Queue;

/*	������		��ʼ������
	ǰ��������	pqָ��һ������
	����������	���б���ʼ��Ϊ��
*/
void InitializeQueue(Queue* pq);

/*	������		�������Ƿ�����
	ǰ��������	pqָ��֮ǰ����ʼ���Ķ���
	����������	��������true������false
*/
bool QueueIsFull(const	Queue* pq);

/*	������		�������Ƿ�Ϊ��
	ǰ��������	pqָ��֮ǰ����ʼ���Ķ���
	����������  Ϊ�շ���true������false
*/
bool QueueIsEmpty(const Queue* pq);

/*	������		ȷ�������е�����
	ǰ��������	pqָ��֮ǰ����ʼ���Ķ���
	����������	���ض����е�����
*/
int QueueItemCount(const Queue* pq);

/*	������		�ڶ���ĩβ�����
	ǰ��������	pqָ��֮ǰ����ʼ���Ķ���
				item��Ҫ������ڶ���ĩβ����
	����������	���в�Ϊ�գ�item������ڶ��е�ĩβ������true�����в��䷵��false
*/
bool EnQueue(Item item, Queue* pq);

/*	������		�Ӷ��еĿ�ͷɾ����
	ǰ��������	pqָ��֮ǰ����ʼ���Ķ���
	����������	���в�Ϊ�գ������׶˵�item����������*pitem�в�ɾ��������true
				����ò���ʹ�ö���Ϊ�գ������ö���Ϊ��
				��������ڲ���ǰΪ�գ��򷵻�false
*/
bool DeQueue(Item* pitem, Queue* pq);

/*	������		��ն���
	ǰ��������	pqָ��֮ǰ����ʼ���Ķ���
	����������	���б����
*/
void EmptyTheQueue(Queue* pq);

#endif // ! _QUEUE_H


