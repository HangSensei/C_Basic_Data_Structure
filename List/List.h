#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//˫������ṹ

typedef int LTDataType;
typedef struct ListNode {
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//˫������ĳ�ʼ��
//void LTInit(LTNode** pphead);
LTNode* LTInit();

//���ٽڵ�
//��������Υ���ӿ�һ����
// void LTDestroy(LTNode** pphead);
//��һ����������ɺ�ʵ���ֶ���ΪNULL
void LTDestroy(LTNode* phead);


//˫������Ĵ�ӡ
void LTPrint(LTNode* phead);

//ͷ�ڵ�Ҫ�����ı䣬������
//ͷ�ڵ㲻�����ı䣬��һ��

//β��
void LTPushBack(LTNode* phead, LTDataType x);
//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);
//βɾ
void LTPopBack(LTNode* phead);
//�����п�
bool LTEmpty(LTNode* phead);
//ͷɾ
void LTPopFront(LTNode* phead);
//����λ�ò���ɾ��
void LTInsertAfter(LTNode* pos, LTDataType x);
void LTInsertBefore(LTNode* pos, LTDataType x);
void LTErase(LTNode* pos);
LTNode* LTFind(LTNode* phead, LTDataType x);
