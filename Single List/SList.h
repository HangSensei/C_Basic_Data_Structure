#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDatatype;
//��������Ľṹ---�ڵ�Ľṹ
typedef struct SListNode
{
	SLTDatatype data;//�洢������
	struct SListNode* next;//ָ����һ���ڵ�
}SLTNode;

//����Ĵ�ӡ
void SLTPrint(SLTNode* phead);

//β��
void SLTPushBack(SLTNode** pphead, SLTDatatype x);
//βɾ
void SLTPopBack(SLTNode** pphead);

//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDatatype x);
//ͷɾ
void SLTPopFront(SLTNode** pphead);