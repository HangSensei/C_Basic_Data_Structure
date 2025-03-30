#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"


void test01()
{
	Stack st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPop(&st);
	while (!StackEmpty(&st))
	{
		int top = StackTop(&st);
		printf("%d ", top);
		StackPop(&st);
	}
}

int main()
{
	test01();
	return 0;
}