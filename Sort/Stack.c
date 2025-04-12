#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void StackInit(Stack* ps)
{
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}

void StackDestroy(Stack* ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->arr = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(Stack* ps, StackDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		//ÔöÈÝ
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		StackDataType* tmp = (StackDataType*)realloc(ps->arr, newcapacity * sizeof(StackDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
	ps->arr[ps->top++] = x;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->top == 0;
}

void StackPop(Stack* ps)
{
	assert(!StackEmpty(ps));
	--ps->top;
}

StackDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->arr[ps->top - 1];
}

int StackSize(Stack* ps)
{
	return ps->top;
}