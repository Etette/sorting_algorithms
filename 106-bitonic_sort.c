#include "sort.h"

void dohalf(int *array, int flag, size_t size, size_t initsize);
void merge(int *array, int flag, size_t size);
/**
 * bitonic_sort - implements bitonic sort
 * @array: array
 * @size: size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	dohalf(array, 1, size, size);
}

/**
 * dohalf - split array
 * @array: array
 * @flag: int 0 or 1
 * @size: size of array
 * @initsize: full size of array
 */
void dohalf(int *array, int flag, size_t size, size_t initsize)
{
	size_t half = (size / 2);

	if (size < 2)
		return;

	printf("Merging [%lu/%lu] (%s):\n", size, initsize,
			(flag == 1) ? "UP" : "DOWN");
	print_array(array, size);
	dohalf(array, 1, half, initsize);
	dohalf((array + half), 0, half, initsize);
	merge(array, flag, size);
	printf("Result [%lu/%lu] (%s):\n", size, initsize,
			(flag == 1) ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * merge - merge
 * @array: array
 * @flag: set up or down
 * @size: size of array
 */
void merge(int *array, int flag, size_t size)
{
	size_t i, gap;
	int aux;

	size_t half = size / 2;

	if (size < 2)
		return;

	gap = size / 2;

	for (i = 0; i < gap; i++)
	{
		if ((array[i] > array[i + gap]) == flag)
		{
			aux = array[i];
			array[i] = array[i + gap];
			array[i + gap] = aux;
		}
	}
	merge(array, flag, half);
	merge((array + half), flag, half);
}
