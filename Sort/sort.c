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

void AdjustDown(int* arr, int parent, int n)//ʱ�临�Ӷ�O(N)
{
	int child = 2 * parent + 1;//���ӽڵ�
	while (child < n)
	{                                                     //���ӽڵ����ֵ   child + 1 < n���鲻��Խ��           ���ӽڵ���Сֵ       
		if (child + 1 < n && arr[child] < arr[child + 1])//������½ڵ��л���child < child + 1 || С�����½ڵ��л���child > child + 1
		{
			child++;//�л�����ֵ���ӽڵ�
		}
		if (arr[child] > arr[parent])//��ѣ�> С�ѣ�<
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;//�ƶ�����һ�����ڵ�
			child = 2 * parent + 1;//�ƶ�����һ���ӽڵ�
		}
		else
		{
			break;
		}
	}
}

void ExtremeValue(int* arr, int n)//���Ӷ�n*logn
{
	//������,Ѱ����ֵ
	int end = n - 1; //����ӽڵ��index
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;//pop�����ֵ(��ʱ������,��������ĩβ)
	}
}

void HeapSort(int* arr, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//���ҵ�����ӽڵ����һ�����ڵ㣬��ʼ�������µ�������
	{
		AdjustDown(arr, i, n);
	}
	//������,Ѱ����ֵ
	ExtremeValue(arr, n);
}

int _QuickSort(int* arr, int left, int right)
{
	int keyi = left;
	++left;
	while (left <= right)
	{
		//right: ���������ߣ��ұȻ�׼ֵҪС��
		while (left <= right && arr[right] > arr[keyi])
		{
			right--;
		}
		//left: ���������ߣ��ұȻ�׼ֵҪ���
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
	//�һ�׼ֵ
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
		//ȡջ������
		int end = StackTop(&st);
		StackPop(&st);
		int begin = StackTop(&st);
		StackPop(&st);
		//[begin, end]�һ�׼ֵ
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
		//�����У�[begin, keyi-1] �����У�[key1+1, end]
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

//�鲢����

void _MergeSort(int* arr, int left, int right, int* tmp)
{
	if (left >= right)
	{
		return;
	}
	int mid = left + (right - left) / 2;// mid = (left + right) / 2
	//����mid������������[left, mid] [mid + 1, right]
	_MergeSort(arr, left, mid, tmp);
	_MergeSort(arr, mid+1, right, tmp);

	//�ϲ�������������
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
	//tmp����������ݵ��뵽ԭ������
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
//�������򣨹�ϣ��
void CountSort(int* arr, int n)
{
	//�����ֵ����Сֵ
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
	//max - minȷ��count�����С
	int range = max - min + 1;
	//���ٿռ�
	/*int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
	{
		perror("malloc fail!");
	}
	//��ʼ��Ϊ0
	memset(count, 0, sizeof(int) * range);*/
	//���ٿռ䲢��ʼ��Ϊ0
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fails!");
	}
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}
	//count���黹ԭ��ԭ������,ʹ������
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