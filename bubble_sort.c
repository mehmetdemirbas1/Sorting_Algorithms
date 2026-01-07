#include<stdio.h>
#include"nutility.h"
#include <time.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Kac eleman: ");
	(void)scanf("%d", &n);
	int* pd = malloc(n * sizeof(int));
	if (!pd)
	{
		printf("Bellek yetersiz\n");
		return 1;
	}
	set_random_array(pd, n);

	clock_t start = clock();

	for (int i = 0; i < n -1; i++)
	{
		for (int k = 0; k < n -1-i; k++)
		{
			if (pd[k]> pd[k+1])
			{
				int temp = pd[k];
				pd[k] = pd[k + 1];
				pd[k + 1] = temp;
			}
		}
	}
	clock_t end = clock();

	printf("Siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	print_array(pd, n);
}