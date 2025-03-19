#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDatatype;
//定义链表的结构---节点的结构
typedef struct SListNode
{
	SLTDatatype data;//存储的数据
	struct SListNode* next;//指向下一个节点
}SLTNode;

//链表的打印
void SLTPrint(SLTNode* phead);

//尾插
void SLTPushBack(SLTNode** pphead, SLTDatatype x);
//尾删
void SLTPopBack(SLTNode** pphead);

//头插
void SLTPushFront(SLTNode** pphead, SLTDatatype x);
//头删
void SLTPopFront(SLTNode** pphead);