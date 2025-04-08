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

int main()
{
	//test01();
	test02();
	return 0;
}
