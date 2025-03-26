#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//双向链表结构

typedef int LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//双向链表的初始化
//void LTInit(LTNode** pphead);
LTNode* LTInit();

//销毁节点
//传二级：违背接口一致性
// void LTDestroy(LTNode** pphead);
//传一级：调用完成后将实参手动置为NULL
void LTDestroy(LTNode* phead);


//双向链表的打印
void LTPrint(LTNode* phead);

//头节点要发生改变，传二级
//头节点不发生改变，传一级

//尾插
void LTPushBack(LTNode* phead, LTDataType x);
//头插
void LTPushFront(LTNode* phead, LTDataType x);
//尾删
void LTPopBack(LTNode* phead);
//链表判空
bool LTEmpty(LTNode* phead);
//头删
void LTPopFront(LTNode* phead);
//任意位置插入删除
void LTInsertAfter(LTNode* pos, LTDataType x);
void LTInsertBefore(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);
LTNode* LTFind(LTNode* phead, LTDataType x);
