#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

//链表的打印
void SLTPrint(SLTNode* phead)//node1节点的地址，确保phead始终指向第一个节点
{
	SLTNode* pcur = phead;//node1节点的地址给pcur
	while (pcur != NULL)
	{
		printf("%d -> ", pcur->data);//node1->data （1 ->）
		pcur = pcur->next;//把下一个节点的地址赋值给pcur （pcur指向的地址更新）
	}
	printf("NULL\n");//最终输出example：（1 -> 2 -> 3 -> 4 -> NULL）
}

SLTNode* SLTbuyNode(SLTDatatype x)
{
	//根据x创建节点
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//开辟空间
	if (newnode == NULL)
	{
		perror("malloc fail!");//malloc报错返回
		exit(1);
	}
	newnode->data = x;//data赋值x
	newnode->next = NULL;//下一个节点地址为NULL（尾节点不存在下一个节点）

	return newnode;//返回创建节点的地址
}

//链表尾插
void SLTPushBack(SLTNode** pphead, SLTDatatype x)
{
	//创建新节点
	SLTNode* newnode = SLTbuyNode(x);
	//链表为空
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//寻找尾节点
		SLTNode* ptail = *pphead;//首个节点地址赋值给寻找尾部的指针变量,以便后续ptail遍历
		while (ptail->next != NULL)
		{
			ptail = ptail->next;
		}
		//找到了尾节点
		ptail->next = newnode;
	}
}

//链表尾删
void SLTPopBack(SLTNode** pphead)
{
	//传参不能为空，不能传空链表
	assert(pphead && *pphead);
	//只有一个节点的情况下
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	//不止一个节点的情况下
	else
	{
		//找prev和ptail
		SLTNode* ptail = *pphead;
		SLTNode* prev = NULL;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//找到了prev和ptail
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//链表头插
void SLTPushFront(SLTNode** pphead, SLTDatatype x)
{
	assert(pphead != NULL);
	SLTNode* newnode = SLTbuyNode(x);

	newnode->next = *pphead;
	//链表头节点地址更新
	*pphead = newnode;
}
//链表头删
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}