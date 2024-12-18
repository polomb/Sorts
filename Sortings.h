#ifndef _SORTINGS_
#define _SORTINGS_

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
void quickSort(double* arr, int N);
void shellSort(double* array, int size);

void countingSort(int* arr, int N);
void radixSort(int* arr, int N);
void RedixExt(int* arr, int N, int exp, int* dop);

#endif

