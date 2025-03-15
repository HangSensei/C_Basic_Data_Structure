#pragma once
#include <stdio.h>
#include <stdlib.h>

//define dynamic data_list
typedef int SLDataType;

typedef struct SequenceList{
	SLDataType* arr;
	int size;
	int capacity;
}SL;

void SLInit(SL* ps);

void SLPushBack(SL* ps, SLDataType x);