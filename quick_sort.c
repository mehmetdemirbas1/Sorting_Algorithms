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

static int partition(int* arr, int low, int high)
{
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
	}

	swap_int(&arr[i + 1], &arr[high]);
	return i + 1;
}

static void quick_sort(int* arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
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
	quick_sort(pd, 0, n - 1);
	clock_t end = clock();

	printf("Siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	print_array(pd, n);
	free(pd);
	return 0;
}
