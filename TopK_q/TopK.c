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
		if (child + 1 < n && arr[child] > arr[child + 1])//大堆向下节点切换：child < child + 1 || 小堆向下节点切换：child > child + 1
		{
			child++;//切换到最值右子节点
		}
		if (arr[child] < arr[parent])//大堆：> 小堆：<
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


void CreateNData()
{
	//造数据
	int n = 100000;
	srand(time(0));
	const char* file = "data.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("fopen error");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}
	fclose(fin);
	fin == NULL;
}

void TopK()
{
	int k;
	printf("Please enter the K:");
	scanf("%d", &k);
	const char* file = "data.txt";
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail!");
		exit(1);
	}
	//找最大的前K个数据,建小堆
	int* minHeap = (int*)malloc(k * sizeof(int));
	if (minHeap == NULL)
	{
		perror("malloc fail!");
		exit(2);
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minHeap[i]);
	}
	//向下调整建堆
	int child = k - 1;
	int parent = (child - 1) / 2;
	for (int i = parent; i >= 0; i--)
	{
		AdjustDown(minHeap, i, k);
	}
	//遍历剩下的n-k个数据，跟堆顶比较
	int x;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		// x mineHeap-Top
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			AdjustDown(minHeap, 0, k);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	fclose(fout);
	fout == NULL;
}

void test02()
{
	//CreateNData();
	TopK();
}

int main()
{
	test02();
	return 0;
}