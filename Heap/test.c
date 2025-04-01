#define _CRT_SECURE_NO_WARNINGS
#include "Heap.h"

void test01()
{
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 56);
	HPPush(&hp, 10);
	HPPush(&hp, 15);
	HPPush(&hp, 30);
	HPPush(&hp, 70);
	HPPush(&hp, 25);
	HPPrint(&hp);

	HPPop(&hp);
	HPPrint(&hp);

	printf("Heap Size: %d\n", HPSize(&hp));
	HPDestroy(&hp);
}

void test02()
{
	HP hp;
	HPInit(&hp);
	HPPush(&hp, 56);
	HPPush(&hp, 10);
	HPPush(&hp, 15);
	HPPush(&hp, 30);
	HPPush(&hp, 70);
	HPPush(&hp, 25);

	while (!HPEmpty(&hp))
	{
		int top = HPTop(&hp);
		printf("%d ", top);
		HPPop(&hp);
	}
	HPDestroy(&hp);
}

void HeapSort(int* arr, int sz)
{
	//建堆-向下调整算法建堆
	for (int i = (sz - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(arr, i, sz);
	}
	//堆排序
	int end = sz - 1;
	while (end > 0)
	{
		Swap(&arr[0], &arr[end]);
		AdjustDown(arr, 0, end);
		end--;
	}
}

int main()
{
	test01();
	//test02();
	/*int arr[7] = { 19, 15, 20, 17, 13, 10, 77 };
	HeapSort(arr, 7);
	printf("After Sort: ");
	for (int i = 0; i < 7; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");*/
	return 0;
}