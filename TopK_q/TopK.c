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

void AdjustUp(int* arr, int child)//ʱ�临�Ӷ�O(N*logN)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (arr[child] > arr[parent])//child > parent���Ͻ����, child < parent���Ͻ�С��
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

void AdjustDown(int* arr, int parent, int n)//ʱ�临�Ӷ�O(N)
{
	int child = 2 * parent + 1;//���ӽڵ�
	while (child < n)
	{                                                     //���ӽڵ����ֵ   child + 1 < n���鲻��Խ��           ���ӽڵ���Сֵ       
		if (child + 1 < n && arr[child] > arr[child + 1])//������½ڵ��л���child < child + 1 || С�����½ڵ��л���child > child + 1
		{
			child++;//�л�����ֵ���ӽڵ�
		}
		if (arr[child] < arr[parent])//��ѣ�> С�ѣ�<
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


void CreateNData()
{
	//������
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
	//������ǰK������,��С��
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
	//���µ�������
	int child = k - 1;
	int parent = (child - 1) / 2;
	for (int i = parent; i >= 0; i--)
	{
		AdjustDown(minHeap, i, k);
	}
	//����ʣ�µ�n-k�����ݣ����Ѷ��Ƚ�
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