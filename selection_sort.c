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

static void selection_sort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
			swap_int(&arr[i], &arr[min_idx]);
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
	selection_sort(pd, n);
	clock_t end = clock();

	printf("Siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	print_array(pd, n);
	free(pd);
	return 0;
}
