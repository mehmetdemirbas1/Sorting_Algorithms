#include <stdio.h>
#include "nutility.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>

static void swap_int(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

static void heapify(int* arr, int n, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i)
	{
		swap_int(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

static void heap_sort(int* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		swap_int(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	int n;
	printf("Kac eleman: ");
	(void)scanf("%d", &n);
	if (n <= 0)
	{
		printf("Gecersiz eleman sayisi\n");
		return 1;
	}

	int* pd = (int*)malloc(n * sizeof(int));
	if (!pd)
	{
		printf("Bellek yetersiz\n");
		return 1;
	}

	set_random_array(pd, n);

	clock_t start = clock();
	heap_sort(pd, n);
	clock_t end = clock();

	printf("Siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	print_array(pd, n);
	free(pd);
	return 0;
}
