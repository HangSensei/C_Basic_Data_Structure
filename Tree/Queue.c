#define _CRT_SECURE_NO_WARNINGS
#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	//pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	newnode->data = x;
	newnode->next = NULL;
	//����Ϊ��
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		//���зǿ�
		pq->ptail->next = newnode;
		pq->ptail = pq->ptail->next;//pq->ptail = newnode
	}
	//pq->size++;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->phead == NULL;
}

void QueuePop(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//ֻ��һ���ڵ㣬phead��ptail��Ҫ��Ϊ��
	if (pq->phead == pq->ptail)
	{
		free(pq->phead);
		pq->phead = pq->ptail = NULL;
	}
	else
	{
		QueueNode* next = pq->phead->next;
		free(pq->phead);
		pq->phead = next;
	}
	//pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->phead->data;

}

QDataType QueueBack(Queue* pq)
{
	assert(!QueueEmpty(pq));
	return pq->ptail->data;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);
	QueueNode* pcur = pq->phead;
	while (pcur)
	{
		QueueNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	//pq->size = 0;
}

int QueueSize(Queue* pq)
{
	assert(!QueueEmpty(pq));
	//1. �������������ڲ�Ƶ�����ö�����Ч���ݸ����ĳ���
	QueueNode* pcur = pq->phead;
	int size = 0;
	while (pcur)
	{
		size++;
		pcur = pcur->next;
	}
	return size;
	//2. Queue�ṹ������int size��������Ƶ�����ö�����Ч���ݸ����ĳ���
	//return pq->size;
}