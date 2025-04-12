#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//����ջ�Ľṹ
typedef int StackDataType;
typedef struct Stack
{
	int* arr;
	int top; //ָ��ջ����λ��
	int capacity;//ջ������
}Stack;

void StackInit(Stack* ps);

void StackDestroy(Stack* ps);

void StackPush(Stack* ps, StackDataType x);

void StackPop(Stack* ps);

bool StackEmpty(Stack* ps);

StackDataType StackTop(Stack* ps);

int StackSize(Stack* ps);