#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void Swap(int* child, int* parent)
{
	int tmp = *child;
	*child = *parent;
	*parent = tmp;
}

void AdjustUp(int* arr, int child)//时间复杂度O(N*logN)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])//child > parent向上建大堆, child < parent向上建小堆
		{
			Swap(&arr[child], &arr[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void AdjustDown(int* arr, int parent, int n)//时间复杂度O(N)
{
	int child = 2 * parent + 1;//左子节点
	while (child < n)
	{                                                     //找子节点最大值   child + 1 < n数组不能越界           找子节点最小值       
		if (child + 1 < n && arr[child] < arr[child + 1])//大堆向下节点切换：child < child + 1 || 小堆向下节点切换：child > child + 1
		{
			child++;//切换到最值右子节点
		}
		if (arr[child] > arr[parent])//大堆：> 小堆：<
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;//移动到下一个父节点
			child = 2 * parent + 1;//移动到下一个子节点
		}
		else
		{
			break;
		}
	}
}

void ExtremeValue(int* arr, int n)//复杂度n*logn
{
	//堆排序,寻找最值
	int end = n - 1; //最后子节点的index
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;//pop出最大值(暂时不访问,在数组最末尾)
	}
}
void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//建堆-向上调整算法建堆
void HeapSortBuildUp(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}
	//堆排序,寻找最值
	ExtremeValue(arr, n);
}

//建堆-向下调整算法建堆
void HeapSortBuildDown(int* arr, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//先找到最后子节点的上一个父节点，开始遍历向下调整建堆
	{
		AdjustDown(arr, i, n);
	}
	//堆排序,寻找最值
	ExtremeValue(arr, n);
}

void test01()
{
	int arr[10] = { 24, 43, 21, 93, 51, 66, 11, 29, 95, 77 };
	int n = sizeof(arr) / sizeof(int);
	printf("Before Adjust: ");
	PrintArr(arr, n);
	HeapSortBuildDown(arr, n);//更低时间复杂度 上层：节点少，层数多 下层：节点多，层数少
	//HeapSortBuildUp(arr, n);//更高时间复杂度 上层：节点少，层数少 下层：节点多，层数多
	printf("After Adjust: ");
	PrintArr(arr, n);
}




int main()
{
	test01();
	return 0;
}