#include "list.h"

LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;
	newnode->next = newnode->prev = newnode;
	return newnode;
}

//void LTInit(LTNode** pphead)
//{
//	assert(pphead);
//	*pphead = LTBuyNode(-1);
//}

void LTPrint(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		printf("%d -> ", pcur->data);
		pcur = pcur->next;
	}
	printf("\n");
}

LTNode* LTInit()
{
	LTNode* phead = LTBuyNode(-1);
	return phead;
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead != NULL);
	LTNode* newnode = LTBuyNode(x);
	//phead phead->prev(尾节点) newnode
	newnode->next = phead;
	newnode->prev = phead->prev;

	phead->prev->next = newnode;
	phead->prev = newnode;
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* newnode = LTBuyNode(x);
	//phead newnode phead->next
	newnode->prev = phead;
	newnode->next = phead->next;

	phead->next->prev = newnode;
	phead->next = newnode;
}
//只有一个头节点的情况下，双向链表为空
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next == phead;
}

void LTPopBack(LTNode* phead)
{
	assert(!LTEmpty(phead));
	LTNode* del = phead->prev;
	//phead del->prev del
	phead->prev = del->prev;
	del->prev->next = phead;
	free(del);
	del = NULL;
}

void LTPopFront(LTNode* phead)
{
	assert(!LTEmpty(phead));
	LTNode* del = phead->next;
	del->next->prev = phead;
	phead->next = del->next;
	free(del);
	del = NULL;
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	//没找到
	return NULL;
}

void LTInsertAfter(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos->next;
	newnode->prev = pos;

	pos->next->prev = newnode;
	pos->next = newnode;
}
void LTInsertBefore(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* newnode = LTBuyNode(x);
	newnode->next = pos;
	newnode->prev = pos->prev;

	pos->prev->next = newnode;
	pos->prev = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);
	pos->next->prev = pos->prev;
	pos->prev->next = pos->next;
	free(pos);
	pos = NULL;
}

void LTDestroy(LTNode* phead)
{
	LTNode* pcur = phead->next;
	while (pcur != phead)
	{
		LTNode* next = pcur->next;
		free(pcur);
		pcur = next;
	}
	free(phead);
	phead = NULL;
}