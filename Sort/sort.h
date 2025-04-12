#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

void Swap(int* a, int* b);

void InsertSort(int* arr, int n);

void ShellSort(int* arr, int n);

void SelectSort(int* arr, int n);

void HeapSort(int* arr, int n);

void QuickSort(int* arr, int left, int right);

void QuickSortNoR(int* arr, int left, int right);

void MergeSort(int* arr, int n);

void CountSort(int* arr, int n);