#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Sortings.h"

void swapD(double* a, double* b);
void swapI(int* a, int* b);

void TestD(void Vizov(double*, int), double* arr, int N);
void TestI(void Vizov(int*, int), int* arr, int N);

double TimerD(void Vizov(double*, int), double* arr, int N);
double TimerI(void Vizov(int*, int), int* arr, int N);

void bubbleSort(double* arr, int N);
void insertionSort(double* arr, int N);
void selectSort(double* arr, int N);

void mergeSort(double* arr, int N);
void MergeSortExt(double* arr, int start, int end, double* tmp);
void quickSort(double* arr, int N);
void fastSort(double* arr, int start, int end);
int partition(double* arr, int start, int end);
void shellSort(double* array, int size);

void countingSort(int* arr, int N);
void radixSort(int* arr, int N);
void RedixExt(int* arr, int N, int exp, int* dop);

//Сортировка пузырьком
void bubbleSort(double* arr, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		char flag = 1;
		for (int j = i; j < N; j++)
		{
			if (arr[j] < arr[i])
			{
				swapD(&arr[j], &arr[i]);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
//Сортировка вставками
void insertionSort(double* arr, int N)
{
	for (int i = 1; i < N; i++)
	{
		int j = i;
		while (j - 1 >= 0 && arr[j] < arr[j - 1])
		{
			swapD(&arr[j], &arr[j - 1]);
			j -= 1;
		}
	}
}
//Сортировка выбором
void selectSort(double* arr, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		int index = i;
		for (int j = i; j < N; j++)
		{
			if (arr[j] < arr[index])
				index = j;
		}
		swapD(&arr[index], &arr[i]);
	}
}

//Сортировка слиянием
void mergeSort(double* arr, int N)
{
	int start = 0, end = N;
	double* tmp = (double*)malloc(end * sizeof(double));
	MergeSortExt(arr, start, end, tmp);
	free(tmp);
}
void MergeSortExt(double* arr, int start, int end, double* tmp)
{
	if (start + 1 == end)
	{
		return;
	}
	int mid = start + (end - start) / 2;
	MergeSortExt(arr, start, mid, tmp);
	MergeSortExt(arr, mid, end, tmp);

	int i = start, j = mid, count = start;
	while (i < mid && j < end)
	{
		if (arr[i] < arr[j])
			tmp[count++] = arr[i++];
		else if (arr[i] >= arr[j])
			tmp[count++] = arr[j++];
	}
	//Merge
	while (i < mid)
		tmp[count++] = arr[i++];
	while (j < end)
		tmp[count++] = arr[j++];
	for (int h = start; h < end; h++)
		arr[h] = tmp[h];
}
//Быстрая сортировка
void quickSort(double* arr, int N)
{
	fastSort(arr, 0, N - 1);
}
void fastSort(double* arr, int start, int end)
{
	if (end - start <= 1)
		return;
	int q;
	while (start < end)
	{
		q = partition(arr, start, end);
		if (q - start < end - q)
		{
			fastSort(arr, start, q);
			start = q + 1;
		}
		else
		{
			fastSort(arr, q + 1, end);
			end = q;
		}
	}
}
int partition(double* arr, int start, int end)
{
	int i = start - 1, j = end; double pivot = arr[end];
	while (1)
	{
		while (arr[++i] < pivot);
		while (arr[--j] > pivot);
		if (i < j) swapD(&arr[i], &arr[j]);
		else
		{
			swapD(&arr[i], &arr[end]);
			return j;
		}
	}
}
//Сортировка Шеллы
void shellSort(double* arr, int N)
{
	for (int a = N / 2; a > 0; a /= 2)
	{
		for (int b = a; b < N; ++b)
		{
			for (int c = b - a; c >= 0 && arr[c] > arr[c + a]; c -= a)
			{
				double temp = arr[c];
				arr[c] = arr[c + a];
				arr[c + a] = temp;
			}
		}
		/*
		for (int a = 0; a < N; a++)
		{
			printf("%0.1lf ", arr[a]);
		}
		printf("\n");
		*/
	}
}

//Сортировка подсчётом
void countingSort(int* arr, int N)
{
	int i, max = arr[0];
	for (i = 1; i < N; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	int* dop = (int*)malloc((max + 1) * sizeof(int));
	for (i = 0; i < max + 1; i++)
	{
		dop[i] = 0;
	}
	for (i = 0; i < N; i++)
	{
		int x = arr[i];
		dop[x] += 1;
	}
	int a = 0;
	for (i = 0; i < max + 1; i++)
	{
		while (dop[i] != 0)
		{
			arr[a] = i;
			dop[i] -= 1;
			a += 1;
		}
	}
	free(dop);
}
//Поразрядная сортировка
void radixSort(int* arr, int N)
{
	int maxim = arr[0];
	for (int i = 1; i < N; i++)
		if (maxim < arr[i])
			maxim = arr[i];
	int* dop = (int*)malloc(N * sizeof(int));
	for (int exp = 1; (maxim / exp) > 0; exp *= 10)
		RedixExt(arr, N, exp, dop);
	free(dop);
}
void RedixExt(int* arr, int N, int exp, int* dop)
{
	/*for (int a = 0; a < N; a++)
	{
		dop[a] = -1;
	}*/
	int i, count[10] = { 0 };
	for (i = 0; i < N; i++)
		count[(arr[i] / exp) % 10] += 1;
	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = N - 1; i >= 0; i--)
	{
		dop[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
		/*for (int a = 0; a < N; a++)
		{
			printf("%d ", dop[a]);
		}
		printf("\n");*/
	}
	for (i = 0; i < N; i++)
		arr[i] = dop[i];
}

//Таймер
double TimerD(void Vizov(double*, int), double* arr, int N)
{
	double* Extrarr = (double*)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++)
	{
		Extrarr[i] = arr[i];
	}
	clock_t start, end;
	start = clock();

	Vizov(Extrarr, N);

	end = clock();
	double TimeTaken = (double)(end - start) / (CLOCKS_PER_SEC);
	free(Extrarr);
	return TimeTaken;
}
double TimerI(void Vizov(int*, int), int* arr, int N)
{
	int* Extrarr = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		Extrarr[i] = arr[i];
	}
	clock_t start, end;
	start = clock();

	Vizov(Extrarr, N);

	end = clock();
	double TimeTaken = (double)((double)(end - start) / CLOCKS_PER_SEC);
	free(Extrarr);
	return TimeTaken;
}

//Тесты
void TestD(void Vizov(double*, int), double* arr, int N)
{
	double* Extrarr = (double*)malloc(N * sizeof(double));
	for (int i = 0; i < N; i++)
	{
		Extrarr[i] = arr[i];
	}
	for (int a = 0; a < N; a++)
	{
		printf("%0.2lf ", Extrarr[a]);
	}
	printf("\n");
	Vizov(Extrarr, N);
	for (int b = 0; b < N; b++)
	{
		printf("%0.2lf ", Extrarr[b]);
	}
	printf("\n");
	free(Extrarr);
}
void TestI(void Vizov(int*, int), int* arr, int N)
{
	int* Extrarr = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++)
	{
		Extrarr[i] = arr[i];
	}
	for (int a = 0; a < N; a++)
	{
		printf("%d ", Extrarr[a]);
	}
	printf("\n");
	Vizov(Extrarr, N);
	for (int b = 0; b < N; b++)
	{
		printf("%d ", Extrarr[b]);
	}
	printf("\n");
	free(Extrarr);
}
//Смена значений
void swapD(double* a, double* b)
{
	double tmp = *a;
	*a = *b;
	*b = tmp;
}
//Смена значений
void swapI(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
