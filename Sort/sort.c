#pragma once
#include "sort.h"
#include "Stack.h"

void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = arr[end + 1];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				end--;
			}
			else
			{
				break;
			}
		}
		arr[end + 1] = tmp;
	}
}

void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;

		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[end + gap];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tmp;
		}
	}
	
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&arr[mini], &arr[begin]);
		Swap(&arr[maxi], &arr[end]);
		begin++;
		end--;
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

void HeapSort(int* arr, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//先找到最后子节点的上一个父节点，开始遍历向下调整建堆
	{
		AdjustDown(arr, i, n);
	}
	//堆排序,寻找最值
	ExtremeValue(arr, n);
}

int _QuickSort(int* arr, int left, int right)
{
	int keyi = left;
	++left;
	while (left <= right)
	{
		//right: 从右往左走，找比基准值要小的
		while (left <= right && arr[right] > arr[keyi])
		{
			right--;
		}
		//left: 从左往右走，找比基准值要大的
		while (left <= right && arr[left] < arr[keyi])
		{
			left++;
		}
		if (left <= right)
		{
			Swap(&arr[left++], &arr[right--]);
		}
	}
	Swap(&arr[keyi], &arr[right]);
	return right;
}

int _QuickSort_lomuto(int* arr, int left, int right)
{
	int keyi = left;
	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[keyi], &arr[prev]);
	return keyi;//
}

void QuickSort(int* arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//找基准值
	int keyi = _QuickSort_lomuto(arr, left, right);
	// left keyi right
	//left: [left, keyi - 1]  right: [keyi+1, right]
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr, keyi + 1, right);

}

void QuickSortNoR(int* arr, int left, int right)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, left);
	StackPush(&st, right);
	while (!StackEmpty(&st))
	{
		//取栈顶两次
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		//[begin, end]找基准值
		int keyi = begin;
		int prev = begin;
		int cur = prev + 1;
		while (cur <= end)
		{
			if (arr[cur] < arr[keyi] && ++prev != cur)
			{
				Swap(&arr[prev], &arr[cur]);
			}
			cur++;
		}
		Swap(&arr[keyi], &arr[prev]);
		keyi = prev;
		//begin keyi end
		//左序列：[begin, keyi-1] 右序列：[key1+1, end]
		if (keyi + 1 < end)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, end);
		}
		if (begin < keyi - 1)
		{
			StackPush(&st, begin);
			StackPush(&st, keyi - 1);
		}
	}
	StackDestroy(&st);
}

//归并排序

void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;// mid = (left + right) / 2
	//根据mid划分左右序列[left, mid] [mid + 1, right]
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid+1, right, tmp);

	//合并两个有序序列
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int index = begin1;
	//[begin1, end1] [begin2, end2]
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmp[index++] = arr[begin1++];
		}
		else
		{
			tmp[index++] = arr[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[index++] = arr[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = arr[begin2++];
	}
	//tmp中有序的数据导入到原数组中
	memcpy(arr + left, tmp + left, (right - left + 1) * sizeof(int));
	/*for (int i = left; i <= right; i++)
	{
		arr[i] = tmp[i];
	}*/
}
void MergeSort(int* arr, int n)
{
	int* arr_tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(arr, 0, n - 1, arr_tmp);
	free(arr_tmp);
	arr_tmp = NULL;
}
//计数排序（哈希表）
void CountSort(int* arr, int n)
{
	//找最大值和最小值
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	//max - min确定count数组大小
	int range = max - min + 1;
	//开辟空间
	/*int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail!");
	}
	//初始化为0
	memset(count, 0, sizeof(int) * range);*/
	//开辟空间并初始化为0
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fails!");
	}
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}
	//count数组还原到原数组中,使其有序
	int index = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			arr[index++] = i + min;
		}
	}
	free(count);
	count == NULL;
}