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

static void up(int* b, int* c)
{
	int temp = *b;
	*b = *b + *c + 1;
	*c = temp;
}

static void down(int* b, int* c)
{
	int temp = *b;
	*b = *c;
	*c = temp - *c - 1;
}

static void sift(int* m, int* r1, int* b1, int* c1)
{
	while (*b1 >= 3)
	{
		int r2 = *r1 - *b1 + *c1;

		if (m[r2] <= m[*r1 - 1])
		{
			r2 = *r1 - 1;
			down(b1, c1);
		}

		if (m[*r1] >= m[r2])
		{
			*b1 = 1;
		}
		else
		{
			swap_int(&m[*r1], &m[r2]);
			*r1 = r2;
			down(b1, c1);
		}
	}
}

static void trinkle(int* m, int* r1, int p, int b, int c)
{
	int p1 = p;
	int b1 = b;
	int c1 = c;

	while (p1 > 0)
	{
		while ((p1 & 1) == 0)
		{
			p1 >>= 1;
			up(&b1, &c1);
		}

		{
			int r3 = *r1 - b1;

			if (p1 == 1 || m[r3] <= m[*r1])
			{
				p1 = 0;
			}
			else
			{
				p1 -= 1;

				if (b1 == 1)
				{
					swap_int(&m[*r1], &m[r3]);
					*r1 = r3;
				}
				else
				{
					int r2 = *r1 - b1 + c1;

					if (m[r2] <= m[*r1 - 1])
					{
						r2 = *r1 - 1;
						down(&b1, &c1);
						p1 = 2 * p1;
					}

					if (m[r3] >= m[r2])
					{
						swap_int(&m[*r1], &m[r3]);
						*r1 = r3;
					}
					else
					{
						swap_int(&m[*r1], &m[r2]);
						*r1 = r2;
						down(&b1, &c1);
						p1 = 0;
					}
				}
			}
		}
	}

	sift(m, r1, &b1, &c1);
}

static void semitrinkle(int* m, int r, int p, int b, int c)
{
	int r1 = r - c;

	if (m[r1] > m[r])
	{
		swap_int(&m[r], &m[r1]);
		trinkle(m, &r1, p, b, c);
	}
}

static void smooth_sort(int* m, int n)
{
	if (n <= 1)
		return;

	int q = 1;
	int r = 0;
	int p = 1;
	int b = 1;
	int c = 1;

	while (q != n)
	{
		int r1 = r;

		if (p % 8 == 3)
		{
			int b1 = b;
			int c1 = c;
			sift(m, &r1, &b1, &c1);
			p = (p + 1) / 4;
			up(&b, &c);
			up(&b, &c);
		}
		else if (p % 4 == 1)
		{
			if (q + c < n)
			{
				int b1 = b;
				int c1 = c;
				sift(m, &r1, &b1, &c1);
			}
			else
			{
				trinkle(m, &r1, p, b, c);
			}

			down(&b, &c);
			p = 2 * p;

			while (b != 1)
			{
				down(&b, &c);
				p = 2 * p;
			}

			p = p + 1;
		}

		q = q + 1;
		r = r + 1;
	}

	{
		int r1 = r;
		trinkle(m, &r1, p, b, c);
	}

	while (q != 1)
	{
		q = q - 1;

		if (b == 1)
		{
			r = r - 1;
			p = p - 1;

			while (p % 2 == 0)
			{
				p = p / 2;
				up(&b, &c);
			}
		}
		else
		{
			p = p - 1;
			r = r - b + c;

			if (p > 0)
				semitrinkle(m, r, p, b, c);

			down(&b, &c);
			p = 2 * p + 1;
			r = r + c;
			semitrinkle(m, r, p, b, c);

			down(&b, &c);
			p = 2 * p + 1;
		}
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
	smooth_sort(pd, n);
	clock_t end = clock();

	printf("Siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
	_getch();
	print_array(pd, n);
	free(pd);
	return 0;
}
