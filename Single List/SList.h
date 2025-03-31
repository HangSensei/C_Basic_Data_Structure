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

//����
SLTNode* SLTFind(SLTNode* phead, SLTDatatype x);

//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDatatype x);
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode* pos, SLTDatatype x);

//ɾ��pos���
void SLTErase(SLTNode** pphead, SLTNode* pos);

//ɾ��pos֮��Ľ��
void SLTEraseAfter(SLTNode* pos);

//��������
void SListDestroy(SLTNode** pphead);