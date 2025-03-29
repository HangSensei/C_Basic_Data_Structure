#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
//队列节点的结构
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;
//队列的结构
typedef struct Queue
{
	QueueNode* phead;
	QueueNode* ptail;
	//int size;//队列中有效数据个数
}Queue;

//初始化
void QueueInit(Queue* pq);
//入队-队尾
void QueuePush(Queue* pq, QDataType x);
//出队-队头
void QueuePop(Queue* pq);
//队列判空
bool QueueEmpty(Queue* pq);
//取队头数据
QDataType QueueFront(Queue* pq);
//取队尾数据
QDataType QueueBack(Queue* pq);
//队列销毁
void QueueDestroy(Queue* pq);
//队列有效元素个数
int QueueSize(Queue* pq);