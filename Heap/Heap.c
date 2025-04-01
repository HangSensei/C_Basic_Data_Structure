#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void HPInit(HP* php)
{
	php->arr = NULL;
	php->size = php->capacity = 0;

}

void HPDestroy(HP* php)
{
	assert(php);
	if (php->arr)
	{
		free(php->arr);
	}
	php->size = php->capacity = 0;
}

void Swap(int* child, int* parent)
{
	int tmp = *child;
	*child = *parent;
	*parent = tmp;
}

void AdjustUp(HPDataType* arr, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])//С�����ϵ�����arr[child] < arr[parent]   ������ϵ�����arr[child] > arr[parent]
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;//childλ�ø���
			parent = (child - 1) / 2;//parentǰ����һ���ȽϽڵ�
		}
		else
		{
			break;
		}
	}
}

//���µ���
void AdjustDown(HPDataType* arr, int parent, int sz)
{
	int child = 2 * parent + 1;//���ӽڵ�
	while (child < sz)
	{
		if (child + 1 < sz && arr[child] < arr[child + 1])// ������£�arr[child] < arr[child + 1] С�����£�arr[child] > arr[child + 1]
		{
			child++;//child�л������ӽڵ�
		}
		if (arr[child] > arr[parent])//������£�arr[child] > arr[parent] С�����£�arr[child] < arr[parent]
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HPPush(HP* php, HPDataType x)
{
	assert(php);
	//�жϿռ��Ƿ��㹻
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataType* tmp = (HPDataType*)realloc(php->arr, newcapacity*sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		php->arr = tmp;
		php->capacity = newcapacity;
	}
	php->arr[php->size] = x;
	//���ϵ���
	AdjustUp(php->arr, php->size);
	php->size++;
}

bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


void HPPop(HP* php)
{
	assert(!HPEmpty(php));
	//�����Ѷ��� size-1 index����
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	--php->size;
	//���µ���
	AdjustDown(php->arr, 0, php->size);
}

void HPPrint(HP* php)
{
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->arr[i]);
	}
	printf("\n");
}

HPDataType HPTop(HP* php)
{
	assert(!HPEmpty(php));
	return php->arr[0];
}

int HPSize(HP* php)
{
	assert(php);
	return php->size;
}