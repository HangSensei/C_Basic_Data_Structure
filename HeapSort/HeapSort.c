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
void PrintArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//����-���ϵ����㷨����
void HeapSortBuildUp(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		AdjustUp(arr, i);
	}
	//������,Ѱ����ֵ
	ExtremeValue(arr, n);
}

//����-���µ����㷨����
void HeapSortBuildDown(int* arr, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)//���ҵ�����ӽڵ����һ�����ڵ㣬��ʼ�������µ�������
	{
		AdjustDown(arr, i, n);
	}
	//������,Ѱ����ֵ
	ExtremeValue(arr, n);
}

void test01()
{
	int arr[10] = { 24, 43, 21, 93, 51, 66, 11, 29, 95, 77 };
	int n = sizeof(arr) / sizeof(int);
	printf("Before Adjust: ");
	PrintArr(arr, n);
	HeapSortBuildDown(arr, n);//����ʱ�临�Ӷ� �ϲ㣺�ڵ��٣������� �²㣺�ڵ�࣬������
	//HeapSortBuildUp(arr, n);//����ʱ�临�Ӷ� �ϲ㣺�ڵ��٣������� �²㣺�ڵ�࣬������
	printf("After Adjust: ");
	PrintArr(arr, n);
}




int main()
{
	test01();
	return 0;
}