#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
//���нڵ�Ľṹ
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;
//���еĽṹ
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	//int size;//��������Ч���ݸ���
}Queue;

//��ʼ��
void QueueInit(Queue* pq);
//���-��β
void QueuePush(Queue* pq, QDataType x);
//����-��ͷ
void QueuePop(Queue* pq);
//�����п�
bool QueueEmpty(Queue* pq);
//ȡ��ͷ����
QDataType QueueFront(Queue* pq);
//ȡ��β����
QDataType QueueBack(Queue* pq);
//��������
void QueueDestroy(Queue* pq);
//������ЧԪ�ظ���
int QueueSize(Queue* pq);