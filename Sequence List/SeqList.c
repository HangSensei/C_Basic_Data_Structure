#pragma once
#include "SeqList.h"

void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


void SLCheckCapacity(SL* ps)
{
	// initially the capacity is 0, we need to allocate the space, if the capacity is not enough, we also need to realloc space
	// if capacity == 0 allocate 4 space, if not, means more space needed, typically realloc 2 times space
	int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
	// determine if the space is enough
	if (ps->size == ps->capacity)
	{
		// more capacity needed, realloc is needed (realloc could also use as malloc)
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail !");
			return 1;
		}
		// update the adress for arr
		ps->arr = tmp;
		// update the capacity
		ps->capacity = newCapacity;
	}
}


void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

void SLPushBack(SL* ps, SLDataType x)
{
	// avoid NULL pointer
	assert(ps != NULL);
	// check if the capacity is enough or add capacity
	SLCheckCapacity(ps);
	// data insert
	ps->arr[ps->size++] = x;
}

void SLPopBack(SL* ps)
{
	// avoid NULL pointer
	// avoid size = 0
	assert(ps && ps->size);
	// pop out, size - 1
	--ps->size;
}



void SLPushFront(SL* ps, SLDataType x)
{
	// avoid NULL pointer
	assert(ps != NULL);
	// check if the capacity is enough or add capacity
	SLCheckCapacity(ps);
	// move all the element in SL 1 position behind
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	// data insert
	ps->arr[0] = x;
	// size + 1
	++ps->size;
}

void SLPopFront(SL* ps)
{
	assert(ps && ps->arr);
	// move all elements 1 position ahead
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	// size - 1
	--ps->size;
}

// insert the data before the desired index
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);
	// data at pos or after pos move 1 position behind
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	++ps->size;
}


// delete the data at desired position
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	--ps->size;
}

int SLFind(SL* ps, SLDataType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void SLDestroy(SL* ps)
{
	if (ps->arr != NULL)
	{
		free(ps->arr);
		ps->capacity = 0;
		ps->size = 0;
	}
}