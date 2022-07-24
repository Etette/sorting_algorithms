#include "sort.h"

void sift_down(int *array, size_t start, size_t end, size_t size);
void swap_elem(int *arr, size_t size, int *a, int *b);

/**
 * sift_down - builds heap from bottom
 * @array: array
 * @size: size of array
 * @start: root of heap
 * @end: last element in heap
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root, child, swap;

	root = start;

	while ((root * 2) + 1 <= end)
	{
		child = (root * 2) + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			swap_elem(array, size, &array[root], &array[swap]);
			root = swap;
		}
		else
			return;
	}
}

/**
 * heapify - arrange heap so root = largest num
 * @array: array
 * @size: size of array
 */
void heapify(int *array, size_t size)
{
	int start;

	start = (size / 2) - 1;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}
}

/**
 * heap_sort - sort list in ascending order
 * @array: array
 * @size: size of rray
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t last;

	if (!array || size < 2)
		return;

	last = size - 1;
	heapify(array, size);

	while (last > 0)
	{
		swap_elem(array, size, &array[last], &array[0]);
		last--;
		sift_down(array, 0, last, size);
	}
}

/**
 * swap_elem - swap value of array elements
 * @array: array
 * @size: size of array
 * @a: pointer to array element
 * @b: pointer to array element
 */
void swap_elem(int *array, size_t size, int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	print_array(array, size);
}
