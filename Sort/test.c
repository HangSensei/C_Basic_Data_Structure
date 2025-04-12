#pragma once
#include "sort.h"
void arrprint(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test01()
{
	int arr1[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	printf("Before Sort : ");
	int sz = sizeof(arr1) / sizeof(int);
	arrprint(arr1, sz);
	InsertSort(arr1, sz);
	printf("After Sort : ");
	arrprint(arr1, sz);
}

void test02()
{
	int arr2[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
	printf("Before Sort : ");
	int sz = sizeof(arr2) / sizeof(int);
	arrprint(arr2, sz);
	ShellSort(arr2, sz);
	printf("After Sort : ");
	arrprint(arr2, sz);

}

void test03()
{
	int arr3[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8};
	printf("Before Sort : ");
	int sz = sizeof(arr3) / sizeof(int);
	arrprint(arr3, sz);
	SelectSort(arr3, sz);
	printf("After Sort : ");
	arrprint(arr3, sz);

}

void test04()
{
	int arr3[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	printf("Before Sort : ");
	int sz = sizeof(arr3) / sizeof(int);
	arrprint(arr3, sz);
	HeapSort(arr3, sz);
	printf("After Sort : ");
	arrprint(arr3, sz);
}

void test05()
{
	int arr5[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	printf("Before Sort : ");
	int sz = sizeof(arr5) / sizeof(int);
	arrprint(arr5, sz);
	QuickSort(arr5, 0, sz - 1);
	printf("After Sort : ");
	arrprint(arr5, sz);
}

void test06()
{
	int arr5[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	printf("Before Sort : ");
	int sz = sizeof(arr5) / sizeof(int);
	arrprint(arr5, sz);
	QuickSortNoR(arr5, 0, sz - 1);
	printf("After Sort : ");
	arrprint(arr5, sz);
}

void test07()
{
	int arr7[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	printf("Before Sort : ");
	int sz = sizeof(arr7) / sizeof(int);
	arrprint(arr7, sz);
	MergeSort(arr7, sz);
	printf("After Sort : ");
	arrprint(arr7, sz);
}

void test08()
{
	int arr7[] = { 5, 3, 9, 6, 2, 4, 7, 1, 8 };
	printf("Before Sort : ");
	int sz = sizeof(arr7) / sizeof(int);
	arrprint(arr7, sz);
	CountSort(arr7, sz);
	printf("After Sort : ");
	arrprint(arr7, sz);
}

int main()
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}
