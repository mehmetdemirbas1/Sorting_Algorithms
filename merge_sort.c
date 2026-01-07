#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "nutility.h"

#define SIZE		100

int main()
{
    int a[SIZE];
    int b[SIZE];
    int c[SIZE*2];
    int idx_a = 0, idx_b = 0;

    randomize();
    set_random_array(a, SIZE);
	set_random_array(b, SIZE);
    sort_array(a, SIZE);
	sort_array(b, SIZE);
	print_array(a, SIZE);
	print_array(b, SIZE);

    	for (int i = 0; i < SIZE*2; i++)
	{
		if (idx_a == SIZE)
			c[i] = b[idx_b++];
		else if (idx_b == SIZE)
			c[i] = a[idx_a++];
		else if (a[idx_a] < b[idx_b])
			c[i] = a[idx_a++];
		else
			c[i] = b[idx_b++];
	}

	print_array(c, SIZE * 2);

}