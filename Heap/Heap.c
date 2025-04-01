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
		if (arr[child] > arr[parent])//小堆向上调整：arr[child] < arr[parent]   大堆向上调整：arr[child] > arr[parent]
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;//child位置更新
			parent = (child - 1) / 2;//parent前往下一个比较节点
		}
		else
		{
			break;
		}
	}
}

//向下调整
void AdjustDown(HPDataType* arr, int parent, int sz)
{
	int child = 2 * parent + 1;//左子节点
	while (child < sz)
	{
		if (child + 1 < sz && arr[child] < arr[child + 1])// 大堆向下：arr[child] < arr[child + 1] 小堆向下：arr[child] > arr[child + 1]
		{
			child++;//child切换到右子节点
		}
		if (arr[child] > arr[parent])//大堆向下：arr[child] > arr[parent] 小堆向下：arr[child] < arr[parent]
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
	//判断空间是否足够
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
	//向上调整
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
	//交换堆顶和 size-1 index数据
	Swap(&php->arr[0], &php->arr[php->size - 1]);
	--php->size;
	//向下调整
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