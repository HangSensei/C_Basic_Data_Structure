#define _CRT_SECURE_NO_WARNINGS
#include "sort_practice.h"

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		//Assume the dataset is in order
		int flag = 1;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				Swap(&arr[j], &arr[j + 1]);
				flag = 0;
			}
		}

		if (flag == 1)
		{
			break;
		}
	}
}

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
	//avoid infinitive loop
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = arr[gap + end];
			while (end >= 0)
			{
				if (arr[end] > tmp)
				{
					arr[gap + end] = arr[end];
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

void SelectSort(int* arr, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int mini = begin;
		int maxi = begin;
		//find the min and max
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
		
		if (mini != begin)
		{
			Swap(&arr[mini], &arr[begin]);
			if (begin == maxi)
			{
				maxi = mini;
			}
		}
		if (maxi != end)
		{
			Swap(&arr[maxi], &arr[end]);
		}
		begin++;
		end--;
	}
}



void AdjustDown(int* arr, int parent, int n)
{
	int child = parent * 2 + 1;
	while (child < n)//avoid outof boundary
	{
		if (child + 1 < n && arr[child + 1] > arr[child])
		{
			child++;
		}
		if (arr[child] > arr[parent])
		{
			Swap(&arr[child], &arr[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void PopExtremeValue(int* arr, int n)
{
	int lastchild = n - 1;
	int root = 0;
	while (lastchild > 0)
	{
		Swap(&arr[root], &arr[lastchild]);
		AdjustDown(arr, root, lastchild);
		lastchild--;
	}
}
void HeapSort(int* arr, int n)
{
	int lastchild = n - 1;
	for (int parent = (lastchild - 1) / 2; parent >= 0; parent-- )
	{
		AdjustDown(arr, parent, n);
	}
	PopExtremeValue(arr, n);
}

int pivot_regular(int* arr, int left, int right)
{
	int pivot = left;
	++left;
	while (left <= right)
	{
		//skip value large than pivot (find value smaller than pivot)
		while (left <= right && arr[right] > arr[pivot])
		{
			right--;
		}
		//skip value smaller than pivot (find value larger than pivot)
		while (left <= right && arr[left] < arr[pivot])
		{
			left++;
		}
		if (left <= right)
		{
			Swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
	}
	Swap(&arr[pivot], &arr[right]);
	return arr[right];
}

int pivot_lomuto(int* arr, int left, int right)
{
	int pivot = left;
	int prev = pivot;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (arr[cur] < arr[pivot] && ++prev != cur)
		{
			Swap(&arr[prev], &arr[cur]);
		}
		cur++;
	}
	Swap(&arr[pivot], &arr[prev]);
	return pivot;
}












void CountSort(int* arr, int n)
{
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
	int capacity = max - min + 1;

	int* count = (int*)calloc(capacity, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fails!");
	}
	for (int i = 0; i < n; i++)
	{
		count[arr[i] - min]++;
	}

	for (int i = 0, index = 0; i < capacity; i++)
	{
		while (count[i]--)
		{
			arr[index++] = min + i;
		}
	}
	free(count);
	count = NULL;
}