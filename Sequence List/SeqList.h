#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//define dynamic data_list
typedef int SLDataType;

typedef struct SequenceList{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

void SLInit(SL* ps);
void SLDestroy(SL* ps);
void SLPrint(SL* ps);

void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);

void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

int SLFind(SL* ps, SLDataType x);
