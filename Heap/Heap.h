#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
//�ѵĽṹ
typedef struct Heap
{
	HPDataType* arr;
	int size;//��Ч���ݸ���
	int capacity;//�ռ��С
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);

void HPPush(HP* php, HPDataType x);

void Swap(int* child, int* parent);

void AdjustUp(HPDataType* arr, int child);//��Ҫ���������飬 �ղ����x��index��child�ڵ�wλ�ã�
void AdjustDown(HPDataType* arr, int parent, int sz);

bool HPEmpty(HP* php);

void HPPop(HP* php);//�����Ѷ�����

void HPPrint(HP* php);

HPDataType HPTop(HP* php);//ȡ�Ѷ�����

int HPSize(HP* php);