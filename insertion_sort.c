#include <stdio.h>
#include "nutility.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>

static void insertion_sort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
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
	insertion_sort(pd, n);
	clock_t end = clock();

	printf("Siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	print_array(pd, n);
	free(pd);
	return 0;
}
