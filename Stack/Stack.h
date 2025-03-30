#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//定义栈的结构
typedef int StackDataType;
typedef struct Stack
{
	int* arr;
	int top; //指向栈顶的位置
	int capacity;//栈的容量
}Stack;

void StackInit(Stack* ps);

void StackDestroy(Stack* ps);

void StackPush(Stack* ps, StackDataType x);

void StackPop(Stack* ps);

bool StackEmpty(Stack* ps);

StackDataType StackTop(Stack* ps);

int StackSize(Stack* ps);