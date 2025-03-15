#pragma once
#include "SeqList.h"

void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLPushBack(SL* ps, SLDataType x)
{
	//initially the capacity is 0, we need to allocate the space, if the capacity is not enough, we also need realloc space
	//if capacity == 0 allocate 4 space, if not, means more space needed, typically 2 times space
	int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
	//determine if the space is enough
	if (ps->size == ps->capacity)
	{
		//more capacity needed, realloc is needed (realloc could also use as malloc)
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail !");
			return 1;
		}
		//update the adress for arr
		ps->arr = tmp;
		//update the capacity
		ps->capacity = newCapacity;
	}
	//if capacity is enough, insert x
	ps->arr[ps->size++] = x;
}