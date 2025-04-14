#define _CRT_SECURE_NO_WARNINGS
#include "sort_practice.h"

void PrintArr(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test0(int* arr, int sz)
{
	printf("Before Sort: ");
	PrintArr(arr, sz);
	BubbleSort(arr, sz);
	printf("After Sort: ");
	PrintArr(arr, sz);

}

void test1(int* arr, int sz)
{
	printf("Before Sort: ");
	PrintArr(arr, sz);
	InsertSort(arr, sz);
	printf("After Sort: ");
	PrintArr(arr, sz);
}

void test2(int* arr, int sz)
{
	printf("Before Sort: ");
	PrintArr(arr, sz);
	ShellSort(arr, sz);
	printf("After Sort: ");
	PrintArr(arr, sz);
}

void test3(int* arr, int sz)
{
	printf("Before Sort: ");
	PrintArr(arr, sz);
	SelectSort(arr, sz);
	printf("After Sort: ");
	PrintArr(arr, sz);
}

void test4(int* arr, int sz)
{
	printf("Before Sort: ");
	PrintArr(arr, sz);
	HeapSort(arr, sz);
	printf("After Sort: ");
	PrintArr(arr, sz);
}

void test5(int* arr, int sz)
{
	printf("Before Sort: ");
	PrintArr(arr, sz);
	CountSort(arr, sz);
	printf("After Sort: ");
	PrintArr(arr, sz);
}

int main()
{
	int arr[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	int sz = sizeof(arr) / sizeof(int);
	test5(arr, sz);
	return 0;
}