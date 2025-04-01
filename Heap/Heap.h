#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
//堆的结构
typedef struct Heap
{
	HPDataType* arr;
	int size;//有效数据个数
	int capacity;//空间大小
}HP;

void HPInit(HP* php);
void HPDestroy(HP* php);

void HPPush(HP* php, HPDataType x);

void Swap(int* child, int* parent);

void AdjustUp(HPDataType* arr, int child);//需要调整的数组， 刚插入的x的index（child节点w位置）
void AdjustDown(HPDataType* arr, int parent, int sz);

bool HPEmpty(HP* php);

void HPPop(HP* php);//弹出堆顶数据

void HPPrint(HP* php);

HPDataType HPTop(HP* php);//取堆顶数据

int HPSize(HP* php);