#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define A 8
#define D1 2000
#define D2 2000
#define D3 2000
#define FORCOUNT 100
#define FORRADIX 100

#define NTEST 20
#define FORTESTS 100

void Print();

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
void RedixExt(int* arr, int N, int exp);

int main()
{
	//Консоль
	HANDLE consol = GetStdHandle(STD_OUTPUT_HANDLE);
	//Позиция курсора
	COORD pos; pos.X = 0; pos.Y = 0;
	//SetConsoleCursorPosition(consol, pos);
	srand(0);


	int DopPer;
	printf("Enter 1 or 0 (1 - for manual, 0 - for excel)\n");
	scanf_s("%d", &DopPer);
	system("cls");
	if (DopPer == 1)
	{
		Print();

		int N = D1;
		double* arrDSred = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDSred[i] = (rand() % D1) / 10.0;
		double* arrDBest = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDBest[i] = i / 10.0;
		double* arrDWorst = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDWorst[i] = (N - i) / 10.0;
		//Bubble
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 1;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(bubbleSort, arrDWorst, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 1;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(bubbleSort, arrDSred, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 1;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerD(bubbleSort, arrDBest, N));
		//Insertion
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 2;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(insertionSort, arrDWorst, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 2;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(insertionSort, arrDSred, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 2;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerD(insertionSort, arrDBest, N));
		//Select
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 3;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(selectSort, arrDWorst, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 3;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(selectSort, arrDSred, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 3;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(selectSort, arrDBest, N));
		free(arrDSred);
		free(arrDBest);
		free(arrDWorst);

		N = D2;
		double* arrDSred1 = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDSred1[i] = (rand() % D2) / 10.0;
		double* arrDBest1 = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDBest1[i] = i / 10.0;
		double* arrDWorst1 = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDWorst1[i] = (N - i) / 10.0;
		//Merge
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 4;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n*log n) = %0.3lf", TimerD(mergeSort, arrDWorst1, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 4;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n*log n) = %0.3lf", TimerD(mergeSort, arrDSred1, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 4;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n*log n) = %0.3lf", TimerD(mergeSort, arrDBest1, N));
		//Fast
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 5;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(quickSort, arrDWorst1, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 5;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n*log n) = %0.3lf", TimerD(quickSort, arrDSred1, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 5;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n^2) = %0.3lf", TimerD(quickSort, arrDBest1, N));
		//Shell
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 6;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n*log^2 n)=%0.3lf", TimerD(shellSort, arrDWorst1, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 6;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n*log^2 n)=%0.3lf", TimerD(shellSort, arrDSred1, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 6;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n*log^2 n)=%0.3lf", TimerD(shellSort, arrDBest1, N));
		free(arrDSred1);
		free(arrDBest1);
		free(arrDWorst1);

		N = D3;
		int* arrISred = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrISred[i] = rand() % FORCOUNT;
		int* arrIBest = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIBest[i] = i / (D3 / FORCOUNT);
		int* arrIWorst = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIWorst[i] = (N - i - 1) / (D3 / FORCOUNT);

		//Counting
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 7;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerI(countingSort, arrIWorst, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 7;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerI(countingSort, arrISred, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 7;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerI(countingSort, arrIBest, N));

		free(arrISred);
		free(arrIBest);
		free(arrIWorst);

		N = D3;
		int* arrISredR = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrISredR[i] = rand() % FORRADIX;
		int* arrIBestR = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIBestR[i] = i / (D3 / FORRADIX);
		int* arrIWorstR = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIWorstR[i] = (N - i - 1) / (D3 / FORRADIX);

		//Radix
		pos.X = 22; pos.Y = (4 * 1) + 2 + 4 * 8;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerI(radixSort, arrIWorstR, N));
		pos.X = 42; pos.Y = (4 * 1) + 2 + 4 * 8;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerI(radixSort, arrISredR, N));
		pos.X = 62; pos.Y = (4 * 1) + 2 + 4 * 8;
		SetConsoleCursorPosition(consol, pos);
		printf("O(n) = %0.3lf", TimerI(radixSort, arrIBestR, N));

		free(arrISredR);
		free(arrIBestR);
		free(arrIWorstR);
		//Возврат консольного курсора
		pos.X = 0; pos.Y = 1 + 4 * 2 + 4 * A;
		SetConsoleCursorPosition(consol, pos);



		//Тесты
		int x;
		printf("0 - Direct, 1 - Imerse, 2 - Random");
		scanf_s("%d", &x);
		double* arr1 = (double*)malloc(NTEST * sizeof(double));
		if (x == 0)
		{
			for (int i = 0; i < NTEST; i++)
				arr1[i] = i / 10.0;
		}
		if (x == 1)
		{
			for (int i = 0; i < NTEST; i++)
				arr1[i] = (NTEST - i) / 10.0;
		}
		if (x == 2)
		{
			for (int i = 0; i < NTEST; i++)
				arr1[i] = (rand() % FORTESTS) / 10.0;
		}
		printf("Bubble\n");
		TestD(bubbleSort, arr1, NTEST);
		printf("Insertion\n");
		TestD(insertionSort, arr1, NTEST);
		printf("Select\n");
		TestD(selectSort, arr1, NTEST);
		printf("Merge\n");
		TestD(mergeSort, arr1, NTEST);
		printf("Quick\n");
		TestD(quickSort, arr1, NTEST);
		printf("Shell\n");
		TestD(shellSort, arr1, NTEST);

		int* arr2 = (int*)malloc(NTEST * sizeof(int));
		if (x == 0)
		{
			for (int i = 0; i < NTEST; i++)
				arr2[i] = i;
		}
		if (x == 1)
		{
			for (int i = 0; i < NTEST; i++)
				arr2[i] = NTEST - i;
		}
		if (x == 2)
		{
			for (int i = 0; i < NTEST; i++)
				arr2[i] = rand() % FORTESTS;
		}
		printf("Counting\n");
		TestI(countingSort, arr2, NTEST);
		printf("Radix\n");
		TestI(radixSort, arr2, NTEST);
		free(arr1);
		free(arr2);
	}
	else if (DopPer == 0)
	{
		int N = D1;
		double* arrDSred = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDSred[i] = (rand() % D1) / 10.0;
		double* arrDBest = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDBest[i] = i / 10.0;
		double* arrDWorst = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDWorst[i] = (N - i) / 10.0;

		N = D2;
		double* arrDSred1 = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDSred1[i] = (rand() % D2) / 10.0;
		double* arrDBest1 = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDBest1[i] = i / 10.0;
		double* arrDWorst1 = (double*)malloc(N * sizeof(double));
		for (int i = 0; i < N; i++)
			arrDWorst1[i] = (N - i) / 10.0;

		N = D3;
		int* arrISred = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrISred[i] = rand() % FORCOUNT;
		int* arrIBest = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIBest[i] = i / (D3 / FORCOUNT);
		int* arrIWorst = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIWorst[i] = (N - i - 1) / (D3 / FORCOUNT);

		N = D3;
		int* arrISredR = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrISredR[i] = rand() % FORRADIX;
		int* arrIBestR = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIBestR[i] = i / (D3 / FORRADIX);
		int* arrIWorstR = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; i++)
			arrIWorstR[i] = (N - i - 1) / (D3 / FORRADIX);

		int a = 19;
		while (a >= 0)
		{
			int b1 = D1 - ((D1 / 20) * a);
			int b2 = D2 - ((D2 / 20) * a);
			int b3 = D3 - ((D3 / 20) * a);
			//Это для того, чтобы всё было одной строкой

			printf("N;%d;Bubble;%0.3lf;%0.3lf;%0.3lf;", b1, TimerD(bubbleSort, arrDWorst, b1), TimerD(bubbleSort, arrDSred, b1), TimerD(bubbleSort, arrDBest, b1));
			printf("Insertion;%0.3lf;%0.3lf;%0.3lf;", TimerD(insertionSort, arrDWorst, b1), TimerD(insertionSort, arrDSred, b1), TimerD(insertionSort, arrDBest, b1));
			printf("Select;%0.3lf;%0.3lf;%0.3lf;", TimerD(selectSort, arrDWorst, b1), TimerD(selectSort, arrDSred, b1), TimerD(selectSort, arrDBest, b1));
			printf("Quick;%0.3lf;-;%0.3lf;", TimerD(quickSort, arrDWorst1, b1), TimerD(quickSort, arrDBest1, b1));

			printf("N;%d;Merge;%0.3lf;%0.3lf;%0.3lf;", b2, TimerD(mergeSort, arrDWorst1, b2), TimerD(mergeSort, arrDSred1, b2), TimerD(mergeSort, arrDBest1, b2));
			printf("Quick;-;%0.3lf;-;", TimerD(quickSort, arrDSred1, b2));
			printf("Shell;%0.3lf;%0.3lf;%0.3lf;", TimerD(shellSort, arrDWorst1, b2), TimerD(shellSort, arrDSred1, b2), TimerD(shellSort, arrDBest1, b2));

			printf("n;%d;Counting;%0.3lf;%0.3lf;%0.3lf;", b3, TimerI(countingSort, arrIWorst, b3), TimerI(countingSort, arrISred, b3), TimerI(countingSort, arrIBest, b3));
			printf("Radix;%0.3lf;%0.3lf;%0.3lf\n", TimerI(radixSort, arrIWorstR, b3), TimerI(radixSort, arrISredR, b3), TimerI(radixSort, arrIBestR, b3));

			a -= 1;
		}
		free(arrDSred);
		free(arrDBest);
		free(arrDWorst);

		free(arrDSred1);
		free(arrDBest1);
		free(arrDWorst1);

		free(arrISred);
		free(arrIBest);
		free(arrIWorst);

		free(arrISredR);
		free(arrIBestR);
		free(arrIWorstR);
	}
}
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
	while (true)
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
	for (int exp = 1; (maxim / exp) > 0; exp *= 10)
		RedixExt(arr, N, exp);
}
void RedixExt(int* arr, int N, int exp)
{
	int* dop = (int*)malloc(N * sizeof(int));
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
	free(dop);
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
	double TimeTaken = double(end - start) / double(CLOCKS_PER_SEC);
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
	double TimeTaken = double(double(end - start) / CLOCKS_PER_SEC);
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

//Вывод в консоль таблицы
void Print()
{
	//Консоль
	HANDLE consol = GetStdHandle(STD_OUTPUT_HANDLE);
	//Позиция курсора
	COORD pos; pos.X = 0; pos.Y = 0;
	//SetConsoleCursorPosition(consol, pos);
	for (int y = 0; y < 1 + 4 * 2 + 4 * A; y++)
	{
		int x = 0;
		while (x <= 110)
		{
			if ((x == 0 || x == 20 || x == 40 || x == 60 || x == 80 || x == 90 || x == 100 || x == 110) && (y % 4 == 0) && !((x == 40 || x == 60) && y == 0))
			{
				printf("+");
				x++;
			}
			else if ((x == 0 || x == 20 || x == 40 || x == 60 || x == 80 || x == 90 || x == 100 || x == 110) && !((x == 40 || x == 60) && (y >= 0 && y <= 3)))
			{
				printf("|");
				x++;
			}
			else if (y % 4 == 0 && !(y == 4 && (x < 20 || x > 80)))
			{
				printf("-");
				x++;
			}
			else
			{
				printf(" ");
				x++;
			}
		}
		printf("\n");
	}
	//Начальное положение
	pos.X = 2 + 4; pos.Y = 4;
	SetConsoleCursorPosition(consol, pos);
	printf("Sortings");
	pos.X = 22; pos.Y = 2;
	SetConsoleCursorPosition(consol, pos);
	printf("Algorithmic complexity");
	pos.X = 82; pos.Y = 3;
	SetConsoleCursorPosition(consol, pos);
	printf("Extra");
	pos.X = 82; pos.Y = 4;
	SetConsoleCursorPosition(consol, pos);
	printf("Memory");
	pos.X = 82; pos.Y = 5;
	SetConsoleCursorPosition(consol, pos);
	printf(" O(n)");
	pos.X = 92; pos.Y = 4;
	SetConsoleCursorPosition(consol, pos);
	printf("Stable");
	pos.X = 102; pos.Y = 4;
	SetConsoleCursorPosition(consol, pos);
	printf("Natural");
	pos.X = 22 + 6; pos.Y = 6;
	SetConsoleCursorPosition(consol, pos);
	printf("Worst");
	pos.X = 42 + 5; pos.Y = 6;
	SetConsoleCursorPosition(consol, pos);
	printf("Average");
	pos.X = 62 + 6; pos.Y = 6;
	SetConsoleCursorPosition(consol, pos);
	printf("Best");
	//Названия сортировок
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 1;
	SetConsoleCursorPosition(consol, pos);
	printf("Bubble Sort");
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 2;
	SetConsoleCursorPosition(consol, pos);
	printf("Insertion Sort");
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 3;
	SetConsoleCursorPosition(consol, pos);
	printf("Select Sort");
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 4;
	SetConsoleCursorPosition(consol, pos);
	printf("Merge Sort");
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 5;
	SetConsoleCursorPosition(consol, pos);
	printf("Fast Sort");
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 6;
	SetConsoleCursorPosition(consol, pos);
	printf("Shell Sort");
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 7;
	SetConsoleCursorPosition(consol, pos);
	printf("Counting Sort");
	pos.X = 2; pos.Y = (4 * 1) + 2 + 4 * 8;
	SetConsoleCursorPosition(consol, pos);
	printf("Radix Sort");
	//Доп память
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 1;
	SetConsoleCursorPosition(consol, pos);
	printf("O(1)");
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 2;
	SetConsoleCursorPosition(consol, pos);
	printf("O(1)");
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 3;
	SetConsoleCursorPosition(consol, pos);
	printf("O(1)");
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 4;
	SetConsoleCursorPosition(consol, pos);
	printf("O(n)");
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 5;
	SetConsoleCursorPosition(consol, pos);
	printf("O(1)");
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 6;
	SetConsoleCursorPosition(consol, pos);
	printf("O(1)");
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 7;
	SetConsoleCursorPosition(consol, pos);
	printf("O(n)");
	pos.X = 82; pos.Y = (4 * 1) + 2 + 4 * 8;
	SetConsoleCursorPosition(consol, pos);
	printf("O(n)");
	//Устойчивость
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 1;
	SetConsoleCursorPosition(consol, pos);
	printf("+");
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 2;
	SetConsoleCursorPosition(consol, pos);
	printf("+");
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 3;
	SetConsoleCursorPosition(consol, pos);
	printf("+?");
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 4;
	SetConsoleCursorPosition(consol, pos);
	printf("+?");
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 5;
	SetConsoleCursorPosition(consol, pos);
	printf("?");
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 6;
	SetConsoleCursorPosition(consol, pos);
	printf("+?");
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 7;
	SetConsoleCursorPosition(consol, pos);
	printf("+");
	pos.X = 92; pos.Y = (4 * 1) + 2 + 4 * 8;
	SetConsoleCursorPosition(consol, pos);
	printf("+");
	//Естественность
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 1;
	SetConsoleCursorPosition(consol, pos);
	printf("+");
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 2;
	SetConsoleCursorPosition(consol, pos);
	printf("+");
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 3;
	SetConsoleCursorPosition(consol, pos);
	printf("-");
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 4;
	SetConsoleCursorPosition(consol, pos);
	printf("-");
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 5;
	SetConsoleCursorPosition(consol, pos);
	printf("-");
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 6;
	SetConsoleCursorPosition(consol, pos);
	printf("+?");
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 7;
	SetConsoleCursorPosition(consol, pos);
	printf("-");
	pos.X = 102; pos.Y = (4 * 1) + 2 + 4 * 8;
	SetConsoleCursorPosition(consol, pos);
	printf("-");
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
